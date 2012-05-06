@include '../lib/jQuery'
@include '../lib/jQuery.color'
do{
  @include '../lib/prettify'
}
import {api} from './consts'.consts

class LeftNav {
  constructor -> {
    private _leftBlock = api.LEFT_BLOCK;
    var active = $('#leftBlock li.active');
    active.find('div').eq(0).css({
      opacity : 0.4,
      left : -295
    }).end().end().find('a').css({color : '#eedd00'});
  }
  public addEvent -> {
    $(document.body).on('click', api.LEFT_A_SELECTOR, private(this).clickHandler.bind(this));
    $(document.body).on('mouseenter', api.LEFT_A_SELECTOR, private(this).hoverHandler.bind(this));
    $(document.body).on('mouseleave', api.LEFT_A_SELECTOR, private(this).hoverHandler.bind(this));
  }
  private clickHandler(e) -> {
    var elem = $(e.target),
        div = elem.parent().find('div').eq(0);
    if !elem.parent().hasClass('active') {
      div.animate({left : -295}, 500);
      elem.parents('ul')
        .find('li.active').removeClass('active')
        .find('a').animate({color : '#FFFFFF'}, 300).end()
        .find('div').eq(0).css('opacity', 1).animate({left : 0}, 500);
      elem.parent().addClass('active');
      private(this).toggleHandler(elem);
    }
  }
  
  private toggleHandler(elem) -> {
    $('#rightBlock').find('div.active').removeClass('active');
    $('#' + elem.attr('data-toggle')).addClass('active');
  }
  
  private hoverHandler(e) -> {
    var elem = $(e.target),
        div = elem.parent().find('div').eq(0);
    if !elem.parent().hasClass('active') {
      if e.type === 'mouseenter' {
        elem.animate({color : '#eedd00'}, 300);
        div.fadeTo(300, 0.4);
      } else {
        elem.animate({color : '#FFFFFF'}, 300);
        div.fadeTo(300, 1);
      }
    }
  }
}

$(->{
  if navigator.userAgent.indexOf('MSIE 6') > -1 {
    DD_belatedPNG.fix('#logo img');
  }
  prettyPrint();
  var leftNav = new LeftNav;
  leftNav.addEvent();
})



