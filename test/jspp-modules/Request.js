
var Notificator = require ( "./Notificator" ).Notificator,
    Mutex = require ( "./Mutex" ).Mutex

/**
*@class
*@arguments Mutex
*/
Class( "Request" , Mutex )
  (function ( self , privates ) {
  
    var rxml = /xml/i,
        rjson = /json/i,
        rget = /get/i,
        rpost = /post/i,
        NOOP = function(){};
    
    self.__init__ = Request_new;
    self.send = Request_send;
    self.addListener = Request_addListener
    self.abort = abort;
    self.dispose = dispose;
    
    /**
    *@constructor
    */
    function Request_new () {
      this.__super__ ();
      privates ( this , {
        ioNotificator : Notificator (),
        connectionObject : JSPP_XMLHttpRequest ()
      } )
      
      
    }
    
    self.COMPLETE = "complete";
    self.PROGRESS = "progress";
    self.ERROR    = "error";
    
    /**
    *@param { String }
    *@param { Function }
    *Regist callback function.
    */
    function Request_addListener ( name , fn ) {
      var privateVar = privates ( this );
      privateVar [ name ] = true;
      privateVar.ioNotificator.connect ( name , fn );
    }
    
    /**
    *@param {Object} url : target url, type : method of request. , data : type of recieved message.
    *Send a request to server.
    *Each request treat as queue.
    */
    function Request_send ( obj ) {
      var privateVar = privates ( this )
      
      if( this.isLocked () ){
        return this.wait( obj )
      }
      
      var req         =   privateVar.connectionObject,
          send_type   =   obj.type || "POST",
          data        =   ( obj.data )? serializeHelper.call ( this , obj.data ) : null,
          url         =   ( obj.url || "/" ),
          get_param   =   ( rget.test( send_type ) && data )? ( "?" + data ) : "";
      
      req.abort();    
      req.open( send_type , url + get_param , ( isDef ( obj.asyncc ) )? obj.async : true );
      
      if( obj.mime && req.overrideMimeType ){
        req.overrideMimeType( obj.mime );
      }
      
      if( obj.header && req.setRequestHeader ){
        req.setRequestHeader.apply( req , obj.header  )
      }
      
      if( "onprogress" in req && privateVar.progress ){
        req.onprogress = function( e ){
          privateVar.ioNotificator.notifyForKey ( "progress" , e.position , e.totalSize , ( e.position / e.totalSize ) * 100 )
        }.bind( this )
      }
      
      if( "onload" in req && privateVar.complete ){
        req.onload = function( e ){
          req.onload = null
          callbackHelper.call( this , obj , req )
        }.bind( this )
        
        if( "onerror" in req ){
          req.onerror = function(){
            req.onerror = NOOP;
            callHelper.call ( this , obj , req )
          }.bind( this )
        }
        
      }else if( privateVar.complete ){
        
        req.onreadystatechange = function( e ){
          
          if( req.readyState === 4 ){
            
            req.onreadystatechange = NOOP;
            
            callbackHelper.call ( this , obj , req )

          }
        }.bind( this )
        
      }
      
      this.scopeLock()
      
      if( rpost.test( send_type ) && obj.data ){
        req.setRequestHeader('Content-Type' ,'application/x-www-form-urlencoded')
        req.send( data )
      }else{
        req.send( "" )
      }
      
    }
    
    /**
    *Abort request.
    */
    function abort () {
      var privateVar = privates ( this );
      privateVar.connectionObject.abort();
      privateVar.mutexQueue.length = 0;
    }
    
    /**
    *Abort request and delete XMLHttpRequest object and empty queue.
    */
    function dispose () {
      var privateVar = privates ( this );
      privateVar.connectionObject.abort();
      privateVar.connectionObject = null;
      privateVar.mutexQueue.length = 0;
    }
    
    /**
    *@param {Object|String} parameter.
    *Seriallize javascript object to url parameter.
    */
    function serializeHelper ( param ) {
      
      var type = typeof param,
          param_arr,
          tp,
          tv,
          param_str = "";
          
      if( type === "string" ){
        param_arr = param.split( "&" );
        for( var i=0,len=param_arr.length; i < len; ++i ){
          tp = param_arr[ i ].split( "=" );
          if( tp[ 1 ] ){
            tv = encodeURIComponent( tp[ 1 ] )
          }else{
            tv = "";
          }
          param_str += "&" + tp[ 0 ] + "=" + tv;
        }
        return param_str.slice( 1 , param_str.length );
      }else if( type === "object" ){
        for( var i in param ){
          param_str += "&" + i + "=" + encodeURIComponent( param[i] );
        }
        return param_str.slice( 1 , param_str.length );
      }
    }
    
    /**
    *@param {Object}
    *@param XMLHttpRequest
    *Run each callback function.
    */
    function callbackHelper ( obj , req ) {
      if( req.status === 200 ){
        var privateVar = privates ( this );
        if( obj.name ){
          privateVar.ioNotificator.notifyForKey ( obj.name , ( !obj.dataType )? req.responseText : 
                                                                               ( rxml.test( obj.dataType ) )? req.responseXML :
                                                                                 ( rjson.test( obj.dataType ) )? JSON.parse( req.responseText ) : req.responseText )
        }else{
          privateVar.ioNotificator.notifyForKey ( this.COMPLETE , ( !obj.dataType )? req.responseText : 
                                                                               ( rxml.test( obj.dataType ) )? req.responseXML :
                                                                                 ( rjson.test( obj.dataType ) )? JSON.parse( req.responseText ) : req.responseText )
        }
      }else{
        privateVar.ioNotificator.notifyForKey ( this.ERROR , obj , ( !obj.dataType )? req.responseText : 
                                                                               ( rxml.test( obj.dataType ) )? req.responseXML :
                                                                                 ( rjson.test( obj.dataType ) )? JSON.parse( req.responseText ) : req.responseText )
      }
      ioQueueHelper.call ( this );
    }
    
    /**
    *Call next send method.
    */
    function ioQueueHelper () {
      var wait = this.scopeUnlock();
      if( wait ){
        this.send( wait );
      }
    }
  
  });
