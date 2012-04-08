/**
 * Facebook page resize
 */
$(function() {
	$('body').append('<div id="fb-root"></div>');
	FB.init({
		appId  : '155634877838735', // *** your facebook app id ***
		status : true, // check login status
		cookie : true, // enable cookies
		xfbml  : true,  // parse XFBML
		logging : true
	});
	FB.Canvas.setAutoResize();
	$('#content').bind('render.invisible',function(){
		FB.Canvas.setAutoResize();
	});
});
