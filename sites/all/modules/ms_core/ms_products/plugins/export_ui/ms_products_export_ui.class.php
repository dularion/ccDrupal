<?php

/**
 * @file
 * Contains ms_products_export_ui.
 */

/**
 * Adds tabledrag and other useful things to the export ui.
 */
class ms_products_export_ui extends ctools_export_ui {

  /**
   * hook_menu() entry point.
   */
  function hook_menu(&$items) {
    parent::hook_menu($items);

    $bundles = ms_products_get_bundles();
    foreach ($bundles as $bundle => $bundle_info) {
      $items['admin/structure/ms_products/' . $bundle . '/add'] = $items['admin/structure/ms_products/add'];
      $items['admin/structure/ms_products/' . $bundle . '/add']['access callback'] = 'user_access';
      $items['admin/structure/ms_products/' . $bundle . '/add']['access arguments'] = array('administer ' . $bundle . ' plans');
      $items['admin/structure/ms_products/' . $bundle . '/import'] = $items['admin/structure/ms_products/import'];
      $items['admin/structure/ms_products/' . $bundle . '/import']['access callback'] = 'user_access';
      $items['admin/structure/ms_products/' . $bundle . '/import']['access arguments'] = array('administer ' . $bundle . ' plans');
    }

    unset($items['admin/structure/ms_products/add']);
  }

  /**
   * Adds the 'weight' option to the sort options.
   */
  function list_sort_options() {
    $sort_options = parent::list_sort_options();
    $sort_options['weight'] = t('Weight');
    return $sort_options;
  }

  /**
   * Adds ability to sort based on weight.
   */
  function list_build_row($item, &$form_state, $operations) {
    // Set up sorting
    $name = $item->{$this->plugin['export']['key']};
    $schema = ctools_export_get_schema($this->plugin['schema']);
    if ($bundle = arg(3)) {
      if ($bundle == 'list') {
        $plan = ms_products_plan_load(arg(4));
        if ($item->bundle != $plan->bundle) {
          return;
        }
      }
      elseif ($item->bundle != $bundle) {
        return;
      }
    }

    // Note: $item->{$schema['export']['export type string']} should have already been set up by export.inc so
    // we can use it safely.
    switch ($form_state['values']['order']) {
      case 'disabled':
        $this->sorts[$name] = empty($item->disabled) . $name;
        break;
      case 'title':
        $this->sorts[$name] = $item->{$this->plugin['export']['admin_title']};
        break;
      case 'name':
        $this->sorts[$name] = $name;
        break;
      case 'storage':
        $this->sorts[$name] = $item->{$schema['export']['export type string']} . $name;
        break;
      case 'weight':
        $this->sorts[$name] = $item->weight;
        break;
    }

    $this->rows[$name]['data'] = array();
    $this->rows[$name]['class'] = !empty($item->disabled) ? array('ctools-export-ui-disabled') : array('ctools-export-ui-enabled');

    // If we have an admin title, make it the first row.
    if (!empty($this->plugin['export']['admin_title'])) {
      $this->rows[$name]['data'][] = array('data' => check_plain($item->{$this->plugin['export']['admin_title']}), 'class' => array('ctools-export-ui-title'));
    }
    $this->rows[$name]['data'][] = array('data' => check_plain($name), 'class' => array('ctools-export-ui-name'));
    $this->rows[$name]['data'][] = array('data' => check_plain($item->{$schema['export']['export type string']}), 'class' => array('ctools-export-ui-storage'));
    $this->rows[$name]['data'][] = array('data' => l(t('Purchase'), 'ms_product/purchase/' . check_plain($name), array('absolute' => TRUE)), 'class' => array('purchase-link'));
    $this->rows[$name]['data'][] = array('data' => $item->weight, 'class' => array('weight'));
    $ops = theme('links__ctools_dropbutton', array('links' => $operations, 'attributes' => array('class' => array('links', 'inline'))));

    $this->rows[$name]['data'][] = array('data' => $ops, 'class' => array('ctools-export-ui-operations'));

    // Add an automatic mouseover of the description if one exists.
    if (!empty($this->plugin['export']['admin_description'])) {
      $this->rows[$name]['title'] = $item->{$this->plugin['export']['admin_description']};
    }
  }

  /**
   * Provide the table header.
   *
   * If you've added columns via list_build_row() but are still using a
   * table, override this method to set up the table header.
   */
  function list_table_header() {
    $header = array();
    if (!empty($this->plugin['export']['admin_title'])) {
      $header[] = array('data' => t('Title'), 'class' => array('ctools-export-ui-title'));
    }

    $header[] = array('data' => t('ID'), 'class' => array('ctools-export-ui-name'));
    $header[] = array('data' => t('Storage'), 'class' => array('ctools-export-ui-storage'));
    $header[] = array('data' => t('Purchase Link'), 'class' => array('purchase-link'));
    $header[] = array('data' => t('Weight'), 'class' => array('weight'));
    $header[] = array('data' => t('Operations'), 'class' => array('ctools-export-ui-operations'));

    return $header;
  }

  /**
   * Master entry point for handling a list.
   */
  function list_page($js, $input) {
    drupal_add_css(drupal_get_path('module', 'ms_products') . '/css/ms_products.plans_ui.css');
    return parent::list_page($js, $input);
  }
}
