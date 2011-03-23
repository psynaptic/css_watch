# CSS WATCH

CSS watch allows themers to live edit theme CSS files. When a css file is saved, the file is reloaded on the page without a page refresh. This can save thousands of refreshes and may end up saving you considerable time.

It works by using JavaScript to poll the server for theme css files and ask if it has been modified. If yes, it will reload the stylesheet.

Only css files declared in your theme and base theme's .info file are polled, potentially saving the overhead of polling 30+ stylesheets.

IE has a hard limit of 31 stylsheets per page. Many Drupal sites will exceed this. This requires CSS aggregation to be enabled to do theme work for IE.

This module will remove CSS preprocessing for css files declared in .info file. This way, you can enable CSS aggregation and can still live edit.

Here is a 4:24 screencast on what it does and how it works
http://www.youtube.com/watch?v=FSDxm50_obI&hd=1

USAGE
-----------

Enable the module.  Disable when watching is no longer needed

OPTIONS
-----------

Visit admin/settings/css-watch

CHANGELOG
-----------

See commit log

CREDITS
-----------

Developed by Dustin Currie at Levelten Interactive <dustin@onlinedesert.com>.
