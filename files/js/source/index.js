import {index} from './consts'.consts
import {imageCache} from './images_cache'

imageCache.cache(['images/sprite.png',
                  'images/sprite.gif',
                  'images/bg.jpg',
                  'images/logo.png',
                  'images/bg2.jpg']);

$(->{
  var filterBug = /MSIE [678]/.test(navigator.userAgent);
  if filterBug {
    index.BG_CACHE().show();
    if navigator.userAgent.indexOf('MSIE 6') > -1 {
      DD_belatedPNG.fix('#logo img');
      DD_belatedPNG.fix('dt.mark');
      DD_belatedPNG.fix('#bg');
    }
  } else {
    setTimeout(->index.LINE_CACHE().fadeIn(2000), 2500);
    index.BG_CACHE().fadeIn(3000);
  }
})
