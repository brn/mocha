
Class ( "NonBlockingIterator" )
  (function ( self , privates ) {
    
    self.__init__ = function ( fn , time ) {
      privates ( this , {
        queue : [],
        last : { isStop : false }
      } )
    }
    
    self.start = function ( options ) {
      var privateVar = privates ( this ),
          last = { isStop : false };
      
      privateVar.last = last;
      
      privateVar.queue.push (function loop() {
        if ( last.isStop ) {
          return;
        }
        if ( options.condition () ) {
          for ( var i = 0; i < 5; ++i ) {
            if ( !options.condition () ){
              return setTimeout ( loop , options.time );
            }
            options.callback ();
          }
          return setTimeout ( loop , options.time );
        }else{
          var next = privateVar.queue.shift ();
          if ( next ) {
            next ();
          }
        }
      });
      if ( privateVar.queue.length === 1 ) {
        privateVar.queue.shift ()();
      }
    }
    
    self.stop = function () {
      privates ( this ).last.isStop = true;
      privates ( this ).queue.length = 0;
    }
    
    var globalQueue = [];
    
    self.__static__.start = function ( options ) {
      globalQueue.push (function loop() {
        if ( options.condition () ) {
          for ( var i = 0; i < 10; ++i ) {
            if ( !options.condition () ){
              return setTimeout ( loop , options.time );
            }
            options.callback ();
          }
          return setTimeout ( loop , options.time );
        }else{
          globalQueue.shift ();
          if ( globalQueue.length > 0 ) {
            globalQueue [ 0 ] ();
          }
        }
      });
      if ( globalQueue.length === 1 ) {
        globalQueue [ 0 ] ()
      }
    }
    
  })
