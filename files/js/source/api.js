@include 'jQuery.color';
@include 'jQuery.easing';
import {api} from './consts'.consts
import {agent} from './agent';
class LeftNav {
  constructor -> {
    private _leftBlock = api.LEFT_BLOCK;
    var active = $('#leftBlock li.active'),
        rightActive = $('#rightBlock div.active');
    active.find('div').eq(0).css({
      opacity : 0.4,
      left : -295
    }).end().end().find('a').css({color : '#eedd00'});
    rightActive
      .find('pre.prettyprint code')
      .each((i, item)->item.innerHTML = prettyPrintOne($(item).html()))
      .end().attr('data-prettified', 1);
  }

  public addEvent -> {
    $(document.body).on('click', api.LEFT_A_SELECTOR, private(this).clickHandler.bind(this));
    $(document.body).on('click', 'a.collapseHead', private(this).collapseHandler.bind(this));
    $(document.body).on('mouseenter', api.LEFT_A_SELECTOR, private(this).hoverHandler.bind(this));
    $(document.body).on('mouseleave', api.LEFT_A_SELECTOR, private(this).hoverHandler.bind(this));
  }

  private clickHandler(e) -> {
    var elem = $(e.target),
        div = elem.parent().find('div').eq(0);
    if !elem.parent().hasClass('active') {
      div.animate({left : -295}, {duration : 500, easing : 'easeInOutCirc'});
      elem.parents('ul')
        .find('li.active').removeClass('active')
        .find('a').animate({color : '#FFFFFF'}, 300).end()
        .find('div').eq(0).css('opacity', 1).animate({left : 0}, {duration : 500, easing : 'easeInOutCirc'});
      elem.parent().addClass('active');
      private(this).toggleHandler(elem);
    }
  }

  private toggleHandler(elem) -> {
    $('#rightBlock').find('div.active').removeClass('active');
    var target = $('#' + elem.attr('data-toggle')).addClass('active'),
        prettified = target.attr('data-prettified'),
        colorized;
    if prettified === undefined && !agent.agent.legacy {
      var codes = target.find('pre.prettyprint code')
      target.attr('data-prettified', 1);
      loop(item, current)->{
        var target = item.eq(current);
        target.html(prettyPrintOne(target.html()));
        if item.size() > current + 1 {
          setTimeout(loop.bind(null, item, current + 1), 16);
        }
      }
      loop(codes, 0);
    }
  }

  private collapseHandler({target}) -> {
    var elem = $(target),
        id = "#" + elem.attr('data-collapse'),
        slideTarget = $(id);
    elem.toggleClass('active');
    slideTarget.slideToggle(300);
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
  //prettyPrint();
  var leftNav = new LeftNav;
  leftNav.addEvent();
})
