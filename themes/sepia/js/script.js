(function ($) {
  $(document).ready(function () {
    $('.js-topbar-link .js-menu').click(function(){
      $('header .main-menu').toggle();
      $(this).toggleClass('active').parent().toggleClass('active');
    });
  });
})(jQuery);
