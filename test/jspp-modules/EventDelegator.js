/*
*Module EventDelegator
*/

Class ( "EventDelegator" )
  ( function ( self , privates ) {
    
    var events = {
      mousemove : "mousemove",
      mousedown : "mousedown",
      mouseup   : "mouseup",
      click     : "click"
    },
    
    addEvent = ( document.addEventListener )?
      
      function ( obj , type , fn ) {
        obj.addEventListener ( type , fn , false )
      }:
      
      (function () {
      
        var _eventObject = function ( e ) {
          if( !this.preventDefault ){
            return new _eventObject ( e )
          }
          
          this.isPreventDefault = false,
          this.isStopPropagation = false,
          this.oevent = e;
          this.type = e.type
          this.timeStamp = +new Date()
          _addProps ( this , e )
          
        },
        
        e_props = "altKey attrChange attrName bubbles button cancelable charCode clientX clientY ctrlKey currentTarget data detail eventPhase fromElement handler keyCode layerX layerY metaKey newValue offsetX offsetY originalTarget pageX pageY prevValue relatedNode relatedTarget screenX screenY shiftKey srcElement target toElement view wheelDelta which".split ( " " ),
        
        _addProps = function ( e , o ) {
          var iter = e_props.length,
              DOC = document,
              ROOT = DOC.htmlElement,
              body = DOC.body,
              tp;
          while( ( tp = e_props[--iter] ) ) {
            e[ tp ] = o[ tp ];
          }
          
          e.attrName = o.attrName || o.propertyName || null;
          
          if ( !e.target ) {
            e.target = e.srcElement || DOC;
          }
          
          if ( e.target.nodeType === 3 ) {
            e.target = e.target.parentNode;
          }
          
          if ( !e.relatedTarget && e.fromElement ) {
            e.relatedTarget = e.fromElement === e.target ? e.toElement : e.fromElement;
          }
          
          if ( e.pageX === null && e.clientX !== null ) {
            e.pageX = e.clientX + (ROOT && ROOT.scrollLeft || body && body.scrollLeft || 0) - (ROOT && ROOT.clientLeft || body && body.clientLeft || 0);
            e.pageY = e.clientY + (ROOT && ROOT.scrollTop  || body && body.scrollTop  || 0) - (ROOT && ROOT.clientTop  || body && body.clientTop  || 0);
          }
          
          if ( e.pageX === null && e.clientX !== null ) {
            e.pageX = e.clientX + (ROOT && ROOT.scrollLeft || body && body.scrollLeft || 0) - (ROOT && ROOT.clientLeft || body && body.clientLeft || 0);
            e.pageY = e.clientY + (ROOT && ROOT.scrollTop  || body && body.scrollTop  || 0) - (ROOT && ROOT.clientTop  || body && body.clientTop  || 0);
          }
          
          if ( !e.metaKey && e.ctrlKey ) {
            e.metaKey = e.ctrlKey;
          }
          
          if ( !e.which && e.button !== undefined ) {
            e.which = (e.button & 1 ? 1 : ( e.button & 2 ? 3 : ( e.button & 4 ? 2 : 0 ) ));
          }
          
        }
        
        _eventObject.prototype = {
          preventDefault : function () {
            this.oevent.returnValue = false;
            this.isPreventDefault = true;
            return false;
          },
          stopPropagation : function () {
            this.oevent.cancelBubble = true;
            this.isStopPropagation = true;
            return false;
          }
        };
        
        return function ( obj , type , fn ) {
          if ( !obj.eventCache || !( type in obj.eventCache ) ) {
            var event = function ( e ) {
                  var cache = obj.eventCache [ type ];
                  for ( var i = 0,len = cache.length; i < len; ++i ) {
                    cache [ i ].call ( obj , _eventObject ( e ) )
                  }
                }
            obj.eventCache = {}
            obj.eventCache [ type ] = [ fn ]
            
            obj.attachEvent ( "on" + type , event )
            
            destroy ( function () {
              obj.detachEvent ( "on" + type , event )
              obj.eventCache [ type ].length = 0;
              obj = null;
              event = null;
            } )
            
          }else{
            obj.eventCache [ type ].push ( fn )
          }
          
        }
      }) (),
    
    delegatorUtil = {
      iodata : {
        "id"    : {},
        "class" : {}
      },
      /**
      *@private
      *@param { Element }
      *対象要素が指定されたID,CLASSを持っているか確認。
      */
      hasTargetAttributes : function PRI_hasTargetAttributes( elem ){
        
        if ( !elem ) {
          return 0x004;
        }
        
        var is_id     = delegatorUtil.hasAttribute ( elem , "id" ),
            is_class  = delegatorUtil.hasAttribute ( elem , "class" );
            
        if( is_id && is_class ){
          return 0x001;
        }else if( is_id ){
          return 0x002
        }else if( is_class ){
          return 0x003
        }else{
          return 0x004;
        }
        
      },
      hasAttribute : ( "hasAttribute" in document.getElementsByTagName ("head") [0] )? function ( elem , attr ) {
        return elem.hasAttribute ( attr );
      } : 
      function ( elem , attr ) {
        return elem [ attr ] !== null || elem [ attr ].length > 0
      },
      procRegistry : {},
      /**
      *@private
      *@param { Element , EventObject }
      *@returns { Boolean < 実行されたかどうか > }
      *対象要素が持っているIDをdataと照らし合わせて確認。
      *あれば設定されたリスナーを実行
      */
      checkID : function ( elem , e , that ){
        var elem_id = elem.id,
            dat     = delegatorUtil.iodata.id,
            type    = null,
            fns     = null,
            is_run  = null;
            
        if( ( type = dat[ elem_id ] ) ){
          if( ( fns = type[ e.type ] ) ){
            fns.forEach( function( fn ){
              if ( fn[ 1 ] === that.guid ){
                fn[ 0 ].call( elem , e );
                is_run = true;
              }
            } )
          }
        }
        
        return is_run;
        
      },
      /**
      *@private
      *@param { Element , EventObject }
      *@returns { Boolean < リスナーが実行されたかどうか > }
      *対象要素が持つクラスをdataと照らし合わせる。
      *あればリスナーを実行。
      */
      checkClass : function ( elem , e , that ){
        var elem_class = elem.className,
            dat        = delegatorUtil.iodata[ "class" ],
            type       = null,
            fns        = null,
            is_run     = null;
        
        elem_class = elem_class.split( " " );
        
        for( var i = 0, len = elem_class.length; i < len; ++i ){
          if( ( type = dat[ ( elem_class[ i ].trim() ) ] ) ){
            if( ( fns = type[ e.type ] ) ){
              fns.forEach( function( fn ){
                if( fn[ 1 ] === that.guid ){
                  e.stopPropagation ();
                  fn[ 0 ].call( elem , e );
                  is_run = true;
                }
              } )
            }
          }
        }
        
        return is_run;
        
      },
      /**
      *@private
      *IDとCLASS両方を確認。
      */
      runBothEvent : function ( target , e , that ){
        delegatorUtil.checkID ( target , e , that );
        delegatorUtil.checkClass ( target , e , that );
      },
      /**
      *@private
      *@param { EventObject }
      *マッチしたタイプによって処理を分ける。
      */
      recieveEvent : function ( e ) {
        var target = e.target,
            types  = delegatorUtil.hasTargetAttributes ( target ),
            ret;
        
        switch( types ){
          //IDとCLASS両方がマッチした場合
          case 0x001 : delegatorUtil.runBothEvent ( target , e , this );
                       break;
          //IDがマッチした場合
          case 0x002 : delegatorUtil.checkID ( target , e , this );
                       break;
          //CLASSがマッチした場合
          case 0x003 : delegatorUtil.checkClass ( target , e , this );
                       break;
           default : return;
        }
      },
      entry : {},
      postExit : function postExit () {
    
        var cache = delegatorUtil.eventCache;
        
        cache.forEach ( function ( fn ) {
        
          fn ();
        
        } )
        
        delegatorUtil.iodata [ "class" ] = null
        delegatorUtil.iodata [ "id" ] = null
        delegatorUtil = null
        
        if ( document.addEventListener ) {
          window.removeEventListener ( "unload" , postExit , false )
        }
        
      },
      eventCache : []
    },
    
    addDelegator = function ( type , elem ) {
      if ( !elem.guid ){
        //ユニークIDの設定
        elem.guid = guidgen ();
      }
      
      //イベントの監視を行う
      addEvent ( elem , type , delegatorUtil.recieveEvent , false )
      
      if ( document.addEventListener ) {
        delegatorUtil.eventCache.push ( function(){
          elem.removeEventListener ( type , delegatorUtil.recieveEvent , false )
        } )
      }
    }
    
    destroy ( function () {
      delegatorUtil.postExit ();
    } )
    
    /**
    *@param{ String < イベントのタイプ > , ElementjQuery|NodeList }
    *指定した要素に子要素のイベントのキャッチ機能を与える
    */
    self.__init__ = function setup ( type , elems ){
      
      if ( typeOf ( type ) === "Array" ){
        return type.forEach ( function ( d ) {
          setup.call ( this , d , elems );
        }.bind ( this ) )
      }
      
      //要素がNodeListではないとき
      if( elems.nodeType ){
      
        addDelegator ( type , elems )
        
        privates ( this , { target : [ elems ] } );
        
      }else{
        
        Array.prototype.forEach.call ( elems , function ( elem ){
          addDelegator ( type , elem )
        })
        
        privates ( this , { target : elems } );
        
      }
    },
    /**
    *param{ Object ( type < class or "id" > , name < マッチさせる文字列 > , eventType < イベントのタイプ > , uiEvent < キャッチ時に実行するリスナー > , target < 捕捉する要素 > ) }
    *実際にキャッチするイベントの設定
    */
    self.addDelegator = function PB_addReciever ( proc_obj ){
      Array.prototype.forEach.call ( privates ( this ).target , function ( d , i ) {
        level ( delegatorUtil.iodata[ proc_obj.type ] , proc_obj.name + "." + proc_obj.eventType , function ( obj , prop ){
          
          obj[ prop ] = []
          return obj[ prop ];
        
        } ).push ( [ proc_obj.reciever , d.guid ] );
      })
    }
    
  } )
