(function($) {
  var konamiListeners = [];
  var progress = [];

  $.extend({
    konami: function(callback, sequence) {
      sequence = typeof(sequence) != 'undefined' ? sequence : [38, 38, 40, 40, 37, 39, 37, 39, 66, 65];
      konamiListeners.push({'callback': callback, 'sequence': sequence});
    }
  });

  $(document).bind("keyup", function(event) {
    progress.push(event.keyCode);
    $.each(konamiListeners, function(index, listener) {
      // Only compare if it's a possible full match.
      if (progress.length >= listener.sequence.length) {
        // Create a target sequence that is the same length as the progress.
        var target = progress.slice(progress.length - listener.sequence.length);
        // Check if the result is the same.
        var equals = true;
        for (var i = 0; i < target.length; i++) {
          if (target[i] != listener.sequence[i]) {
            equals = false;
            break;
          }
        }
        if (equals) {
          // Reset the progress and invoke the listener.
          progress = [];
          listener.callback();
          return false;
        }
      }
    });
    // Keep the progress length sane.
    if (progress.length > 40) {
      progress = progress.slice(25);
    }
  });
})(jQuery);

/**
 * Register the Konami Code action behavior.
 */
Drupal.behaviors.konamicode = {
  attach: function (context, settings) {
    // Multiple actions can take place. It defaults to just Image Attack.
    jQuery.each(settings.konamicode || {imageattack:true}, function(action, code) {
      var sequence = (code == true) ? [38, 38, 40, 40, 37, 39, 37, 39, 66, 65] : code;
      // Register the Konami Code event.
      jQuery('body').once('konamicode' + action, function() {
        jQuery.konami(function() {
          // Activate the event.
          Drupal['konamicode_' + action]();
        }, sequence);
      });
    });
  }
};

/**
 * The Image Attack Konami Code action.
 */
Drupal.konamicode_imageattack = function() {
  // Subtract Druplicon width and height to ensure that he is only spawned
  // inside the window area and does not cause it to scroll.
  var width = jQuery(document).width() - 175;
  var height = jQuery(document).height() - 200;
  Drupal.konamicode_imageattackimages = Drupal.settings.konamicodeImages || ['https://drupal.org/files/druplicon-small.png'];
  // Select a random image.
  var max = Drupal.settings.konamicodeImagesMax || 500;
  var count = 0;
  konamiCodeSpawnImage(width, height, max, count);
};

/**
 * Spawn an image randomly on the screen.
 */
function konamiCodeSpawnImage(width, height, max, count) {
  // Generate random location.
  var x = Math.floor(Math.random() * width);
  var y = Math.floor(Math.random() * height);
  var image = Drupal.konamicode_imageattackimages[Math.floor(Math.random() * Drupal.konamicode_imageattackimages.length)];

  // Append Druplicon image tag to HTML body.
  jQuery('body').append('<img src="' + image + '" style="position: absolute; z-index: 1000; left: ' + x + 'px; top: ' + y + 'px;"/>');
  count++;

  // Queue another Druplicon.
  if (count < max) {
    setTimeout('konamiCodeSpawnImage(' + width + ', ' + height + ', ' + max + ', ' + count + ')', 10);
  }
}

/**
 * The Redirect Konami Code action.
 */
Drupal.konamicode_redirect = function() {
  window.location = Drupal.settings.konamicodeDestination || 'https://youtu.be/dQw4w9WgXcQ';
};

/**
 * The Alert Konami Code action.
 */
Drupal.konamicode_alert = function() {
  alert(Drupal.settings.konamicodeAlert || Drupal.t('Konami Code Is Geek!'));
};

/**
 * The Flip Text Konami Code action.
 */
Drupal.konamicode_fliptext = function() {
  jQuery('body').fliptext();
};

/**
 * The Cornify Konami Code action.
 */
Drupal.konamicode_cornify = function() {
  jQuery.getScript('https://www.cornify.com/js/cornify.js', function(data, textStatus) {
    cornify_add();
  });
};

/**
 * The Geocities-izer Konami Code action.
 */
Drupal.konamicode_geocitiesizer = function() {
  var theme = Drupal.settings.konamicodeGeo || 0;
  if (theme !== 0) {
    theme = '&theme=' + theme;
  }
  else {
    theme = '';
  }
  window.location = 'http://wonder-tonic.com/geocitiesizer/content.php?url=' + window.location + theme;
};

/**
 * The Asteroids Konami Code action.
 */
Drupal.konamicode_asteroids = function() {
  // Or: https://cdn.jsdelivr.net/gh/erkie/erkie.github.com/asteroids.js.
  jQuery.getScript('https://hi.kickassapp.com/kickass.js');
};

/**
 * The Place Kitten Konami Code action.
 */
Drupal.konamicode_placekitten = function() {
  jQuery('img').each(function() {
    var w = jQuery(this).width();
    var h = jQuery(this).height();
    jQuery(this).attr('src', 'https://placekitten.com/' + w + '/' + h);
  });
};

/**
 * The Raptorize Konami Code action.
 */
Drupal.konamicode_raptorize = function() {
  // Load the Raptorize plugin via jQuery.
  jQuery.getScript(Drupal.settings.konamicodeR + '/raptorize/jquery.raptorize.1.0.js', function() {
    // Display the Raptor's wrath.
    jQuery('body').raptorize({
      'enterOn': 'timer',
      'delayTime': 50
    });
  });
};

/**
 * The Katamari Hack Konami Code action.
 */
Drupal.konamicode_katamari = function() {
  //jQuery.getScript('http://kathack.com/js/kh.js');
  jQuery.getScript('https://cdn.jsdelivr.net/gh/seancron/kathack/kh.js');
};

/**
 * The Snowfall Konami Code action.
 */
Drupal.konamicode_snowfall = function() {
  // Load the Snowfall jQuery plugin.
  var path = Drupal.settings.basePath + Drupal.settings.snowfall.path + '/snowfall/snowfall.jquery.js';
  jQuery.getScript(path, function() {
    // Invoke the plugin on the document object.
    jQuery(document).snowfall(Drupal.settings.snowfall);
  });
};

/**
 * The Snowfall Konami Code action.
 */
Drupal.konamicode_gg = function() {
  // Only add the Konami Code GG once.
  if (jQuery('#konamicode-gg').length == 0) {
    var path = Drupal.settings.basePath + Drupal.settings.gg + '/gg/gg.';
    var extension = ['ogg', 'mp3', 'wav'];
    var markup = '<audio id="konamicode-gg" preload="auto">';
    for (var i = 0; i < 3; i++) {
      markup = markup + '<source src="' + path + extension[i] + '" />';
    }
    markup = markup + '</audio>';
    jQuery('body').append(markup);
  }
  jQuery('#konamicode-gg')[0].play();
};

/**
 * The Browser Ponies Code action.
 */
Drupal.konamicode_browserponies = function() {
  (function (config) {
    BrowserPonies.setBaseUrl(Drupal.settings.browserponies.baseurl);
    BrowserPonies.loadConfig(BrowserPoniesBaseConfig);
    BrowserPonies.loadConfig(config);
  })
  (Drupal.settings.browserponies);
};
