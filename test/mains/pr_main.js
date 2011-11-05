
var RollController = require ( "../3rd-modules/RollController" ).RollController,
    Base = require ( "../3rd-modules/Base" ).Base,
    Info = require ( "../3rd-modules/Info" ).Info;


function main () {
  
  Info ();
  
  ready( function () {
    Base.init ();
    
    var controller = RollController (),
        prev = $( "#prev" ),
        next = $( "#next" );
    
    prev.bind ( "click" , controller.prev.bind ( controller ) );
    next.bind ( "click" , controller.next.bind ( controller ) );
    
  })
}

exports.main = main;
var x = 100;