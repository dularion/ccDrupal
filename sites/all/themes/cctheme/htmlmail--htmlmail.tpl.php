<?php

/**
 * @file
 * Sample template for HTML Mail test messages.
 */
?>
<h1>Test Mail</h1>
<div class="htmlmail-body">
    <?php echo $body; ?>
    <p>Hallo Welt!</p>
</div>
<?php if ($debug): ?>
<hr />
<div class="htmlmail-debug">
    <dl><dt><p>
        To customize this test message:
    </p></dt><dd><ol><li><p><?php if (empty($theme)): ?>
        Visit <u>admin/config/system/htmlmail</u>
        and select a theme to hold your custom email template files.
    </p></li></ol></dd></dt><dd><ol><li><p><?php elseif (empty($theme_path)): ?>
        Visit <u>admin/appearance</u>
        to enable your selected <u><?php echo ucfirst($theme); ?></u> theme.
    </p></li></ol></dd></dt><dd><ol><li><p><?php endif; ?>
        Copy the
        <a href="http://drupalcode.org/project/htmlmail.git/blob_plain/refs/heads/7.x-2.x:/htmlmail--htmlmail.tpl.php"><code>htmlmail--htmlmail.tpl.php</code></a>
        file to your <u><?php echo ucfirst($theme); ?></u> theme directory
        <u><code><?php echo $theme_path; ?></code></u>.
    </p></li><li><p>
        Edit the copied file.
    </p></li></ol></dd></dl>
</div>
<?php endif;
