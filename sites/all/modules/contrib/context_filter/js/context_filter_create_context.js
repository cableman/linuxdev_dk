(function ($) {
  Drupal.behaviors.contextFilterCreateContext = {
    attach: function() {
      $('div.toolbar-drawer:not(.context-filter-create-context-processed)').each(function() {
        // Append the link and add click handler to reload the page.
        $(this).append('<a class="context-filter-links context-filter-create-context" href="#">Create context</a>');
        $('.context-filter-create-context').click(function(e){
          var settings = Drupal.settings.context_filter;
          $.get('/context_filter/create', {path : settings.currentPath}, function() {
            window.location.reload();
          });
          e.preventDefault();
          return false;
        });
      }).addClass('context-filter-create-context-processed');
    },
    detach: function() { }
  };
})(jQuery);
