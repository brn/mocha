/*
*Module Notification
*/

/**
*@class
*/
Class ( "Notificator" )
  (function ( self , privates ) {
    
    var shift = Array.prototype.shift
    
    /**
    *@private
    */
    var observer = {
      /**
      *@param { String ( subject id ) , ANY ( arguments ) }
      *Run all function added to pool.
      */
      update : function ( id , args ) {
        if ( this.pool [ id ] ){
          for ( var i = 0 , pool = this.pool [ id ] , len = this.pool [ id ].length; i < len; i += 2 ) {
            pool [ i ].apply ( null , args )
          }
        }
      },
      
      updateByKey : function ( id , args ) {
        var key = shift.call ( args );
        if ( this.pool [ id ] ){
          for ( var i = 0 , pool = this.pool [ id ] , len = this.pool [ id ].length; i < len; i += 2 ) {
            if ( pool [ i + 1 ] === key ) {
              pool [ i ].apply ( null , args )
            }
          }
        }
      },
      
      pool : {}
    }
    
    destroy ( function () {
      observer.pool.length = 0;
      delete observer.pool;
    } )
    
    
    /**
    *@constructor
    *Create id.
    */
    self.__init__ = function () {
      /**
      *@private
      *Instance unique ID.
      */
      privates ( this , { _subjectId : guidgen () } );
    }
    
    
    /**
    *@member of Notificator
    *Add function to observer pool.
    */
    self.connect = function ( key , fn ) {
      
      debug : {
        assert.True ( baseTypeOf ( key ) === "String" , "The first arguments of Notificator::connect must be a type of String." );
        assert.True ( baseTypeOf ( fn ) === "Function" , "The second arguments of Notificator::connect must be a type of String." );
      }
      
      level ( observer.pool ,  privates ( this )._subjectId , function ( o , n ) {
        o [ n ] = [];
        return o [ n ]
      }).push ( fn , key )
    }
    
    
    /**
    *@memberOf Notificator
    *Remove function from observer pool.
    */
    self.disconnect = function ( fn ) {
      
      debug : {
        assert.True ( baseTypeOf ( fn ) === "Function" , "The first arguments of Notificator::connect must be a type of String." );
      }
      
      observer.pool [ privates ( this )._subjectId ].splice ( observer.pool.indexOf ( fn ) , 2 )
    }
    
    
    /**
    *@memberOf Notificator
    *@param { ANY ( This arguments give to function of observer.pool. ) }
    *Call observer.update.
    */
    self.notify = function () {
      observer.update ( privates ( this )._subjectId , arguments )
    }
    
    self.notifyForKey = function () {
      observer.updateByKey ( privates ( this )._subjectId , arguments )
    }
    
  })
