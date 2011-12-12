(function() {
  var __global_export__ = {},
      __MC_tmp__ = undefined;
  (function() {
    __MC_global_alias__.__MC_runtime = ( function __MC_runtime() {
      var __MC_local_export__ = {};
      var instance_prop = {};
      __MC_local_export__.__hide_prop = function __hide_prop( id,prop,value ) {
        if ( !( id in instance_prop ) ){
          instance_prop[id] = {};
        };
        instance_prop[id][prop] = value;
      };
      __MC_local_export__.__hidden = function __hidden() {
        
      };
      return __MC_local_export__;
    })();
  })();
  (function() {
    var Monster = ( function () {
          function attack( target ) {
            log( 'The monster attacks '+target );
          };
          function health( value ) {
            if ( value<0 ){
              throw new Error( 'Health must be non-negative.' );
            };
            this.health = value;
          };
          function isAlive() {
            return this.health>0;
          };
          function Monster() {
            __MC_runtime__.__hidden( this,'__MC_instance_id_', ++ __MC_instance_id_ );
            this.constructor.apply( this,arguments );
          };
          __MC_runtime__.__hidden( Monster,'constructor',function constructor( name,health ) {
            this.name = name;
            __MC_runtime__.__hide_prop( this.__typeid__,'health',health );
          });
          Monster.prototype.numAttacks = 0;
          Monster.prototype.attackMessage = 'The monster hits you!';
          return Monster;
        })();
    ;
  })();
})();
