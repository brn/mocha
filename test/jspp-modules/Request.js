
var Notificator = require ( "./Notificator" ).Notificator,
    Mutex = require ( "./Mutex" ).Mutex

/**
*@class
*@arguments Mutex
*/
Class( "Request" , Mutex )
  (fun self privates -> {
  
    let rxml = /xml/i,
        rjson = /json/i,
        rget = /get/i,
        rpost = /post/i,
        NOOP = fun->{};
    
    self.__init__ = Request_new;
    self.send = Request_send;
    self.addListener = Request_addListener
    self.abort = abort;
    self.dispose = dispose;
    
    /**
    *@constructor
    */
    let Request_new = fun-> {
      @.__super__();
      privates ( @ , {
        ioNotificator : new Notificator(),
        connectionObject : new JSPP_XMLHttpRequest()
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
    let Request_addListener = fun -> name fn {
      var privateVar = privates @;
      privateVar[ name ] = true;
      privateVar.ioNotificator.connect name fn;
    }
    
    /**
    *@param {Object} url : target url, type : method of request. , data : type of recieved message.
    *Send a request to server.
    *Each request treat as queue.
    */
    let Request_send = fun-> obj {
      var privateVar = privates @;
      
      if( this.isLocked() ) {
        return this.wait obj;
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
        req.onprogress = fun e => @ {
          privateVar.ioNotificator.notifyForKey "progress" e.position e.totalSize ( e.position / e.totalSize ) * 100;
        }
      }
      
      if( "onload" in req && privateVar.complete ){
        req.onload = fun e => @ {
          req.onload = null
          callbackHelper.call( this , obj , req )
        }.bind( this )
        
        if( "onerror" in req ){
          req.onerror = fun e => @ {
            req.onerror = NOOP;
            callHelper.call ( this , obj , req )
          }
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
    let abort = fun -> {
      let privateVar = privates @;
      privateVar.connectionObject.abort();
      privateVar.mutexQueue.length = 0;
    }
    
    /**
    *Abort request and delete XMLHttpRequest object and empty queue.
    */
    let dispose = fun-> {
      let privateVar = privates @;
      privateVar.connectionObject.abort();
      privateVar.connectionObject = null;
      privateVar.mutexQueue.length = 0;
    }
    
    /**
    *@param {Object|String} parameter.
    *Seriallize javascript object to url parameter.
    */
    let serializeHelper = fun param -> {
      
      let type = typeof param,
          param_arr,
          tp,
          tv,
          param_str = "";
          
      if( type === "string" ){
        param_arr = param.split "&";
        for( let i = 0,len = param_arr.length; i < len; ++i ){
          tp = param_arr[ i ].split "=";
          if( tp[ 1 ] ){
            tv = encodeURIComponent tp[ 1 ];
          }else{
            tv = "";
          }
          param_str += "&" + tp[ 0 ] + "=" + tv;
        }
        return param_str.slice 1 param_str.length;
      }else if( type === "object" ){
        for( let i in param ){
          param_str += "&" + i + "=" + encodeURIComponent param[i];
        }
        return param_str.slice 1 , param_str.length;
      }
    }
    
    /**
    *@param {Object}
    *@param XMLHttpRequest
    *Run each callback function.
    */
    let callbackHelper = fun obj req -> {
      if( req.status === 200 ){
        var privateVar = privates this;
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
