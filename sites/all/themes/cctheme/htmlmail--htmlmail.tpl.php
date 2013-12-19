<?php
/**
 * @file
 * Sample template for HTML Mail test messages.
 */
$css_file = realpath(dirname(__FILE__)) . '/css/custom.css';
if (!empty($css_file) && file_exists($css_file)) {
    $css = file_get_contents($css_file);
}
?>
<html>
    <head>
        <style type="text/css">
            <!--
            <?php print $css ?>
            -->
        </style>
    </head>
    <body>
    <h1>Test Mail</h1>
        <div class="htmlmail-body">
            <?php echo $body; ?>
        </div>
        <?php if ($debug): ?>
            <hr />
            <div class="htmlmail-debug">
                <dl>
                    <dt>
                        <p>To customize this test message:</p>
                    </dt>
                    <dd>
                        <ol>
                            <li>
                                <p>
                                    <?php if (empty($theme)): ?>
                                    Visit <u>admin/config/system/htmlmail</u>
                                    and select a theme to hold your custom email template files.
                                </p>
                            </li>
                        </ol>
                    </dd>
                    <dd>
                        <ol>
                            <li>
                                <p>
                                    <?php elseif (empty($theme_path)): ?>
                                    Visit <u>admin/appearance</u>
                                    to enable your selected <u><?php echo ucfirst($theme); ?></u> theme.
                                </p>
                            </li>
                        </ol>
                    </dd>
                    <dd>
                        <ol>
                            <li>
                                <p>
                                    <?php endif; ?>
                                    Open the
                                    <a href="http://drupalcode.org/project/htmlmail.git/blob_plain/refs/heads/7.x-2.x:/htmlmail--htmlmail.tpl.php">
                                        <code>htmlmail--htmlmail.tpl.php</code>
                                    </a>
                                    file in your <u><?php echo ucfirst($theme); ?></u> theme directory
                                    <u>
                                        <code>
                                            <?php echo $theme_path; ?>
                                        </code>
                                    </u>.
                                </p>
                            </li>
                            <li>
                                <p>Edit the file.</p>
                            </li>
                        </ol>
                    </dd>
                </dl>
            </div>
        <?php endif; ?>
    </body>
</html>
