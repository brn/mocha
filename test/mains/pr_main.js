
var RollController = require ( "../3rd-modules/RollController" ).RollController,
    Base = require ( "../3rd-modules/Base" ).Base,
    Info = require ( "../3rd-modules/Info" ).Info;


const main = fun ->{

        Info ();

        ready( fun->{
          Base.init ();

          let controller = RollController(),
              prev = $( "#prev" ),
              next = $( "#next" );

          prev.bind ( "click" , controller.prev.bind ( controller ) );
          next.bind ( "click" , controller.next.bind ( controller ) );

        })
      }

exports.main = main;