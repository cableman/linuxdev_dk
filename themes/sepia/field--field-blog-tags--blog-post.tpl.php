<?php
/**
 * @file field--fences-ul.tpl.php
 * Wrap each field value in the <li> element and all of them in the <ul> element.
 *
 * @see http://developers.whatwg.org/grouping-content.html#the-ul-element
 */
?>
<span class="<?php print $classes; ?>">
    <h3 class="field-label"<?php print $title_attributes; ?>>
      <?php print $label; ?>
    </h3>

    <?php foreach ($items as $delta => $item): ?>
      <span<?php print $item_attributes[$delta]; ?>>
        <?php print render($item); ?>
      </span>
    <?php endforeach; ?>
</span>