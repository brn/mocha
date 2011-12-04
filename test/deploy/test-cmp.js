(function() {
  var __global_export__ = {},
      __MC_tmp__ = undefined;
  (function() {
    __global_export__['{1-302-567-849-60818395-1384-fmt.js}'] = {};
    (function () {
      var __export__ = __global_export__['{1-302-567-849-60818395-1384-fmt.js}'];
      __export__.fmt = function ( format,args ) {
        for ( var i in args ){
          var reg = new RegExp( ( "\\$\\{"+i+"\\}" ) , "g" );
          format = format.replace( reg,args[i] );
        };
        return format;
      };
    })();
  })();
  (function() {
    var __tmp__0 = __global_export__['{1-302-567-849-60818395-1384-fmt.js}'],
        fmt = ( __tmp__0.fmt )?__tmp__0.fmt : undefined;
    function Monster() {
      Monster.__MC_init_.apply( this , arguments );
      __MC_Runtime_.__fix( this );
    };
    __MC_Runtime_.__unenum(Monster , '__MC_init_' , function constructor( name,health ) {
      this.name = name;
      __MC_Runtime_.__inst_prop_def( this , "health" , health , true , true );
    });
    Monster.prototype.attack = function attack( target ) {
      log( 'The monster attacks '+target );
    };
    Monster.prototype.numAttacks = 0;
    __MC_Runtime_.__proto_member_def( Monster.prototype , "attackMessage" , 'The monster hits you!' , false , true );
    __MC_Runtime_.__proto_member_def_( Monster.prototype. , "isAlive" , function isAlive() {
      return this.health>0;
    } , true );
    __MC_Runtime_.__proto_member_def_( Monster.prototype. , "health" , function health( value ) {
      if ( value<0 ){
        throw new Error( 'Health must be non-negative.' );
      };
      this.health = value;
    } , true );
    ;
  })();
})();
