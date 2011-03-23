(function ($) {
  Drupal.behaviors.cssWatch = {
    attach: function () {
      var domain = Drupal.settings.cssWatch.domain;
      var paths = Drupal.settings.cssWatch.paths;
      var poll = Drupal.settings.cssWatch.pollInterval;
      var queryString;

      setInterval(function() {
        for (i = 0; i < paths.length; i++) {
          var path = paths[i];
          console.log('Polling for changes...');
          jQuery.ajax({
            url: domain + path,
            async: false, // nothing works without this
            ifModified: true,
            success: function(data, textStatus, jqXHR) {
              if (textStatus != 'notmodified') {
                console.log('Reloading ' + domain + path);
                queryString = '?'  + new Date().getTime();
                $('link[href^="' + domain + path + '"]').attr("href", domain + path.replace(/\?.*|$/, queryString));
              }
            }
          });
        }
      }, poll);
    }
  };
}(jQuery));
