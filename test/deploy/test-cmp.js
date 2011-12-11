(function() {
  var __global_export__ = {},
      __MC_tmp__ = undefined;
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
