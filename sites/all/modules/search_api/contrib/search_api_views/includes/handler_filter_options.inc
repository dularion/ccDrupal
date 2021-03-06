<?php

/**
 * Views filter handler class for handling fields with a limited set of possible
 * values.
 *
 * Definition items:
 * - options: An array of possible values for this field.
 */
class SearchApiViewsHandlerFilterOptions extends SearchApiViewsHandlerFilter {

  protected $value_form_type = 'checkboxes';

  /**
   * Provide a list of options for the operator form.
   */
  public function operator_options() {
    $options = array(
      '=' => t('Is one of'),
      'all of' => t('Is all of'),
      '<>' => t('Is none of'),
      'empty' => t('Is empty'),
      'not empty' => t('Is not empty'),
    );
    // "Is all of" doesn't make sense for single-valued fields.
    if (empty($this->definition['multi-valued'])) {
      unset($options['all of']);
    }
    return $options;
  }

  /**
   * Set "reduce" option to FALSE by default.
   */
  public function expose_options() {
    parent::expose_options();
    $this->options['expose']['reduce'] = FALSE;
  }

  /**
   * Add the "reduce" option to the exposed form.
   */
  public function expose_form(&$form, &$form_state) {
    parent::expose_form($form, $form_state);
    $form['expose']['reduce'] = array(
      '#type' => 'checkbox',
      '#title' => t('Limit list to selected items'),
      '#description' => t('If checked, the only items presented to the user will be the ones selected here.'),
      '#default_value' => !empty($this->options['expose']['reduce']),
    );
  }

  /**
   * Define "reduce" option.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['expose']['contains']['reduce'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Reduce the options according to the selection.
   */
  protected function reduce_value_options() {
    $options = array();
    foreach ($this->definition['options'] as $id => $option) {
      if (isset($this->options['value'][$id])) {
        $options[$id] = $option;
      }
    }
    return $options;
  }

  /**
   * Save set checkboxes.
   */
  public function value_submit($form, &$form_state) {
    // Drupal's FAPI system automatically puts '0' in for any checkbox that
    // was not set, and the key to the checkbox if it is set.
    // Unfortunately, this means that if the key to that checkbox is 0,
    // we are unable to tell if that checkbox was set or not.

    // Luckily, the '#value' on the checkboxes form actually contains
    // *only* a list of checkboxes that were set, and we can use that
    // instead.

    $form_state['values']['options']['value'] = $form['value']['#value'];
  }

  /**
   * Provide a form for setting options.
   */
  public function value_form(&$form, &$form_state) {
    $options = array();
    if (!empty($this->options['expose']['reduce']) && !empty($form_state['exposed'])) {
      $options += $this->reduce_value_options($form_state);
    }
    else {
      $options += $this->definition['options'];
    }
    $form['value'] = array(
      '#type' => $this->value_form_type,
      '#title' => empty($form_state['exposed']) ? t('Value') : '',
      '#options' => $options,
      '#multiple' => TRUE,
      '#size' => min(4, count($this->definition['options'])),
      '#default_value' => is_array($this->value) ? $this->value : array(),
    );

    // Hide the value box if the operator is 'empty' or 'not empty'.
    // Radios share the same selector so we have to add some dummy selector.
    if (empty($form_state['exposed'])) {
      $form['value']['#states']['visible'] = array(
        ':input[name="options[operator]"],dummy-empty' => array('!value' => 'empty'),
        ':input[name="options[operator]"],dummy-not-empty' => array('!value' => 'not empty'),
      );
    }
    elseif (!empty($this->options['expose']['use_operator'])) {
      $name = $this->options['expose']['operator_id'];
      $form['value']['#states']['visible'] = array(
        ':input[name="' . $name . '"],dummy-empty' => array('!value' => 'empty'),
        ':input[name="' . $name . '"],dummy-not-empty' => array('!value' => 'not empty'),
      );
    }
  }

  /**
   * Provides a summary of this filter's value for the admin UI.
   */
  public function admin_summary() {
    if (!empty($this->options['exposed'])) {
      return t('exposed');
    }

    if ($this->operator === 'empty') {
      return t('is empty');
    }
    if ($this->operator === 'not empty') {
      return t('is not empty');
    }

    if (!is_array($this->value)) {
      return;
    }

    $operator_options = $this->operator_options();
    $operator = $operator_options[$this->operator];
    $values = '';

    // Remove every element which is not known.
    foreach ($this->value as $i => $value) {
      if (!isset($this->definition['options'][$value])) {
        unset($this->value[$i]);
      }
    }
    // Choose different kind of ouput for 0, a single and multiple values.
    if (count($this->value) == 0) {
      return $this->operator != '<>' ? t('none') : t('any');
    }
    elseif (count($this->value) == 1) {
      switch ($this->operator) {
        case '=':
        case 'all of':
          $operator = '=';
          break;

        case '<>':
          $operator = '<>';
          break;
      }
      // If there is only a single value, use just the plain operator, = or <>.
      $operator = check_plain($operator);
      $values = check_plain($this->definition['options'][reset($this->value)]);
    }
    else {
      foreach ($this->value as $value) {
        if ($values !== '') {
          $values .= ', ';
        }
        if (drupal_strlen($values) > 20) {
          $values .= '…';
          break;
        }
        $values .= check_plain($this->definition['options'][$value]);
      }
    }

    return $operator . (($values !== '') ? ' ' . $values : '');
  }

  /**
   * Add this filter to the query.
   */
  public function query() {
    if ($this->operator === 'empty') {
      $this->query->condition($this->real_field, NULL, '=', $this->options['group']);
      return;
    }
    if ($this->operator === 'not empty') {
      $this->query->condition($this->real_field, NULL, '<>', $this->options['group']);
      return;
    }

    // Extract the value.
    while (is_array($this->value) && count($this->value) == 1) {
      $this->value = reset($this->value);
    }

    // Determine operator and conjunction.
    switch ($this->operator) {
      case '=':
        $operator = '=';
        $conjunction = 'OR';
        break;

      case 'all of':
        $operator = '=';
        $conjunction = 'AND';
        break;

      case '<>':
        $operator = '<>';
        $conjunction = 'AND';
        break;
    }

    // If the value is an empty array, we either want no filter at all (for
    // "is none of", or want to find only items with no value for the field.
    if ($this->value === array()) {
      if ($this->operator != '<>') {
        $this->query->condition($this->real_field, NULL, '=', $this->options['group']);
      }
      return;
    }

    if (is_scalar($this->value) && $this->value !== '') {
      $this->query->condition($this->real_field, $this->value, $operator, $this->options['group']);
    }
    elseif ($this->value) {
      $filter = $this->query->createFilter($conjunction);
      // $filter will be NULL if there were errors in the query.
      if ($filter) {
        foreach ($this->value as $v) {
          $filter->condition($this->real_field, $v, $operator);
        }
        $this->query->filter($filter, $this->options['group']);
      }
    }
  }

}
