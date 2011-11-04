
Class ( "JppTestUnit" )(
  function ( self , privates ) {
    
    var driverPool = {};
    
    self.__singleton__ = true;
    
    self.__init__ = function ( global , dom ) {
      
    }
    
    self.addTestDriver = function ( driver ) {
      
      #ifdebug
      assert.True ( isType ( driver , Object ) , "The arguments of JppTestUnit::addTestDriver is must be a type of Object." );
      #endif
      
      extend ( driverPool , driver );
      
    } 
    
    self.runTest = function ( testName ) {
            
      var driver = driverPool [ testName ],
          methodCache = [];
      
      if ( typeof driver === "string" ) {
        
        var method = require ( driver )
        for ( var name in method ) {
          methodCache [ methodCache.lebgth ] = name;
        };
        
        (function loop () {
          if ( methodCache.length > 0 ) {
            var name = methodCache.shift ();
            try{
              method [ name ] ();
            }catch(e){
              console.warn ( name + " Error!  description : " + e );
            }
            setTimeout ( loop , 64 );
          }
        })()
        
      }
      
    }
    
    self.runAllTest = function () {
      var driverNames = [];
      for ( var i in driverPool ) {
        driverNames [ driverNames.length ] = i;
      };
      
      (function loop () {
        if ( driverNames.length > 0 ) {
          var name = driverNames.shift ();
          try{
            driverPool [ name ] ();
          }catch(e){
            console.warn ( name + " Error!  description : " + e )
          }
          setTimeout ( loop , 64 );
        }
      })();
      
    }
    
  }
)
