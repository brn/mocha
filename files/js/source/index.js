import {index} from './consts'.consts
import {imageCache} from './images_cache'
import {agent} from './agent'.agent

imageCache.cache(['images/stripes.gif',
                  'images/spot.png',
                  'images/line.png',
                  'images/bg.jpg',
                  'images/logo.png',
                  'images/bg2.jpg']);

class BinaryLinks {
  constructor(@_binLink = $('#download')){}
  public addEvent() -> {
    var {userAgent} = navigator;
    if (userAgent.indexOf('Win') > -1) {
      @_binLink.on('click', -> location.href = '../bin/win32/mocha.zip');
    } else if (userAgent.indexOf('Mac') > -1) {
      @_binLink.on('click', -> location.href = '../bin/macos/mocha.zip');
    } else {
      @_binLink.on('click', -> alert('Sorry, the binary file is not provided for your os. Please build from the sources.'));
    }
  }
};

$(->{
  if agent.legacy {
    index.BG_CACHE().show();
    index.LINE_CACHE().show();
    if agent.IE6 {
      DD_belatedPNG.fix('#logo img');
      DD_belatedPNG.fix('dt.mark');
      DD_belatedPNG.fix('#bg');
      DD_belatedPNG.fix('#line');
    }
  } else {
    setTimeout(->index.LINE_CACHE().fadeIn(2000), 2500);
    index.BG_CACHE().fadeIn(3000);
  }
  var binaryLinks = new BinaryLinks;
  binaryLinks.addEvent();
})
