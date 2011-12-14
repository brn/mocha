try{
  throw new SyntaxError("C:\Users\game/.mocha/module/runtime/mocha_runtime.js No such file or directory")
}catch(e){
  throw new Error(e);
}
;(function() {
  var __global_export__ = {},
      __MC_tmp__ = undefined;
  ( function () {
    _mochaGlobalExport['{15204446-473-60818019-1008-fmt.js}'] = {};
    var _mochaGlobalAlias = _mochaGlobalExport['{15204446-473-60818019-1008-fmt.js}'];
    var x = function (  ) {
          var rest = Runtime.toArray( arguments,0 );
          var _mochaLocalTmp0 = [0,1,2,3],
              x = ( _mochaLocalTmp0.x && _mochaLocalTmp0.x[0] )?_mochaLocalTmp0.x[0] : undefined,
              m = ( _mochaLocalTmp0.x )?Runtime.toArray( _mochaLocalTmp0,1 ) : undefined;
        };
  })();
  ( function () {
    _mochaGlobalExport['{15204446-473-60818019-1008-test.js}'] = {};
    var _mochaGlobalAlias = _mochaGlobalExport['{15204446-473-60818019-1008-test.js}'];
    var _mochaLocalTmp0 = _mochaGlobalExport['{15204446-473-60818019-1008-fmt.js}'],
        fmt = _mochaLocalTmp0.fmt;
    ( function () {
      var _mochaLocalExport = _mochaGlobalAlias;
      _mochaLocalExport.Monster = ( function () {
        var _mochaPrivateHolder = function () {
              
            };
        function Monster() {
          Runtime.createUnenumProp( this,'__private__',new _mochaPrivateHolder );
          Monster.constructor.apply( this,arguments );
        };
        Runtime.createUnenumProp( Monster,'constructor',function constructor( name,health ) {
          this.name = name;
          var _mochaLocalTmp2 =  {
                x : 200
              };
          Runtime.constant( this.__private__,'name',( _mochaLocalTmp2.x && _mochaLocalTmp2.x[0] )?_mochaLocalTmp2.x[0] : undefined );
          Runtime.constant( this.__private__,'age',( _mochaLocalTmp2.x && _mochaLocalTmp2.x[1] )?_mochaLocalTmp2.x[1] : undefined );
          Runtime.constant( this.__private__,'hobby',( _mochaLocalTmp2.x && _mochaLocalTmp2.x[2] && _mochaLocalTmp2.x[2].hobby )?_mochaLocalTmp2.x[2].hobby : undefined );
          Runtime.constant( this.__private__,'_tmpName',name );
        });
        Monster.prototype.numAttacks = 0;
        Runtime.constant( Monster.prototype,'attackMessage','The monster hits you!' );
        _mochaPrivateHolder.prototype.isAlive = function isAlive() {
          return this._health>0;
        };
        _mochaPrivateHolder.prototype.health = function health( value ) {
          if ( value<0 ){
            throw new Error( 'Health must be non-negative.' );
          };
          this._health = value;
          return this.value+"tmpName";
        };
        _mochaPrivateHolder.prototype.attack = function attack( target ) {
          log( 'The monster attacks '+target );
        };
        Runtime.constant( Monster,'constant',200 );
        var _mochaLocalTmp3 = human;
        Monster.name = ( _mochaLocalTmp3.human && _mochaLocalTmp3.human.name )?_mochaLocalTmp3.human.name : undefined;
        Monster.age = ( _mochaLocalTmp3.human && _mochaLocalTmp3.human.age )?_mochaLocalTmp3.human.age : undefined;
        Monster.h1 = ( _mochaLocalTmp3.human && _mochaLocalTmp3.human.hobby && _mochaLocalTmp3.human.hobby[0] )?_mochaLocalTmp3.human.hobby[0] : undefined;
        Monster.h2 = ( _mochaLocalTmp3.human && _mochaLocalTmp3.human.hobby && _mochaLocalTmp3.human.hobby[1] )?_mochaLocalTmp3.human.hobby[1] : undefined;
        Monster.h3 = ( _mochaLocalTmp3.human && _mochaLocalTmp3.human.hobby && _mochaLocalTmp3.human.hobby[2] )?_mochaLocalTmp3.human.hobby[2] : undefined;
        var _mochaLocalTmp4 = human_;
        Monster.name_ = ( _mochaLocalTmp4.human_ && _mochaLocalTmp4.human_.name_ )?_mochaLocalTmp4.human_.name_ : undefined;
        Monster.age_ = ( _mochaLocalTmp4.human_ && _mochaLocalTmp4.human_.age_ )?_mochaLocalTmp4.human_.age_ : undefined;
        Monster.h1_ = ( _mochaLocalTmp4.human_ && _mochaLocalTmp4.human_.hobby_ && _mochaLocalTmp4.human_.hobby_[0] )?_mochaLocalTmp4.human_.hobby_[0] : undefined;
        Monster.h2_ = ( _mochaLocalTmp4.human_ && _mochaLocalTmp4.human_.hobby_ && _mochaLocalTmp4.human_.hobby_[1] )?_mochaLocalTmp4.human_.hobby_[1] : undefined;
        Monster.h3_ = ( _mochaLocalTmp4.human_ && _mochaLocalTmp4.human_.hobby_ && _mochaLocalTmp4.human_.hobby_[2] )?_mochaLocalTmp4.human_.hobby_[2] : undefined;
        return Monster;
      })();
      return _mochaLocalExport;
    })();
  })();
})();
