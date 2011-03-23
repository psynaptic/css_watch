(function ($) {
  Drupal.behaviors.cssWatch = {
    attach: function () {
      var domain = Drupal.settings.cssWatch.domain;
      var paths = Drupal.settings.cssWatch.paths;
      var poll = Drupal.settings.cssWatch.pollInterval;
      var queryString;
      var worker = function() {
        $.each(paths, function(i, path){
          $.ajax({
            url: domain + path,
            ifModified: true,
            success: function(data, textStatus, jqXHR) {
              if (textStatus != 'notmodified') {
                console.log('Reloading ' + path);
                queryString = '?'  + new Date().getTime();
                $('link[href^="' + domain + path + '"]').attr("href", domain + path.replace(/\?.*|$/, queryString));
              }
            }
          });
        });
      };
      setInterval(worker, poll);
    }
  };
})(jQuery);
