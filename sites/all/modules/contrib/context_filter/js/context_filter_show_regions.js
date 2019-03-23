(function ($) {
  Drupal.behaviors.contextFilterShowRegions = {
    attach: function() {
      $('div.toolbar-drawer:not(.context-filter-show-regions-processed)').each(function() {
        // Find the right text for the toggle link.
        var text = Drupal.t('Show empty regions');
        if (Drupal.settings.context_filter.isShown) {
          text = Drupal.t('Hide empty regions');
        }

        // Append the link and add click handler to reload the page.
        $(this).append('<a class="context-filter-links context-filter-show-regions" href="#">' + text + '</a>');
        $('.context-filter-show-regions').click(function(e){
          $.get('/context_filter/regions', function() {
            // Reload the page to toggle the empty regions.
            window.location.reload();            
          });
          e.preventDefault();
          return false;
        });
      }).addClass('context-filter-show-regions-processed');
    },
    detach: function() { }
  };
})(jQuery);
