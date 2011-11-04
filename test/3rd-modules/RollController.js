
var EventDelegator = require ( "EventDelegator" ).EventDelegator,
    Info = require ( "./Info" ).Info;
    
Class ( "RollController" )(
  function ( self , privates ) {
    
    var LIST_SIZE = 440,
        LARGE_SIZE = 490,
        SEMI_LARGE_SIZE = 460,
        DIFF = ( SEMI_LARGE_SIZE - LIST_SIZE ) + ( ( LARGE_SIZE - LIST_SIZE ) / 2 ),
        ADD = ( SEMI_LARGE_SIZE - LIST_SIZE ) * 2 + ( LARGE_SIZE - LIST_SIZE ),
        LARGE_CLASS = "large",
        SEMI_LARGE_CLASS = "semiLarge",
        NO_IMAGE = "src/img/noimage.jpg";
    
    var calcCenter = function () {
          var privateVar = privates ( this ),
              centerSize = LARGE_SIZE + ( SEMI_LARGE_SIZE * 2 ),
              isEven = privateVar.listCounts % 2 === 0,
              max = ( isEven )? privateVar.maxWidth : privateVar.maxWidth - LIST_SIZE,
              ulNegate = ( privateVar.windowWidth - max ) / 2 + LIST_SIZE / 2;
          privateVar.centerConstNum = ( privateVar.windowWidth - LIST_SIZE ) / 2 + LIST_SIZE;
          privateVar.rollList.css ( "marginLeft" , ulNegate + "px" );
          addClassToCenter ( privateVar , ulNegate , max );
        },
        addClassToCenter = function ( privateVar , ulNegate , max ) {
          var index = ( max - ( -1 * parseFloat ( privateVar.rollList.css ( "marginLeft" ) ) ) - privateVar.centerConstNum ) / LIST_SIZE;
          
          privateVar.rollList.css ( { "marginLeft" : ( ulNegate - DIFF ) + "px" , width : privateVar.maxWidth + ADD + 20 } );
          
          
          privateVar.defNegate = ulNegate;
          setCenterClass ( index - 1 );
          privateVar.currentLarge = toInteger ( index - 1 );
          setText ( privateVar );
          
        },
        setCenterClass = function ( index ) {
          $ ( "#rollList li" )
            .eq ( index ).addClass ( LARGE_CLASS ).end ()
            .eq ( index - 1 ).addClass ( SEMI_LARGE_CLASS ).end ()
            .eq ( index + 1 ).addClass ( SEMI_LARGE_CLASS ).end ();
        },
        setText = function ( privateVar ) {
          
          var text = $ ( ( "#rollList li." + LARGE_CLASS ) ).attr ( "info-data" ),
              sptext = text.split ( ":" );

          privateVar.title.text (  sptext [ 0 ] );
          privateVar.tools.text (  sptext [ 1 ] );
          
          
        },
        loadImage = function ( data , callback ) {
          var image = new Image ();
          image.onload = function () {
            callback ( image );
          }
          if ( data.src === "no" ) {
            data.src = NO_IMAGE;
            image.className = "noImage";
          }
          image.className += " imageData";
          image.src = data.src;
          image.alt = ( data.alt )? data.alt : "";
          
        }
    
    self.__singleton__ = true;
    
    self.__init__ = function () {
      var rollList = $( "#rollList" ),
          lists = $( "li" , rollList ),
          that = this,
          showCaseEvent,
          privateVar;
      
      privates ( this , {
        rollList : rollList,
        lists : lists,
        listCounts : lists.length,
        maxWidth : LIST_SIZE * lists.length,
        windowWidth : $( window ).width (),
        prevent : false,
        title : $( "#title" ),
        tools : $( "#tools" ),
        showCase : $( "#showCase" ),
        bigImage : $( "#bigImage" ),
        pbar : $( "#progressBar" ),
        name : $( "#infoName" ),
        about : $( "#infoAbout" ),
        use : $( "#infoUse" )
      })
      
      calcCenter .call ( this );
      
      privateVar = privates ( this );
      
      $ ( window ).bind ( "resize" , function () {
        privateVar.windowWidth = $( window ).width ();
        privateVar.rollList.removeClass ( LARGE_CLASS ).removeClass ( SEMI_LARGE_CLASS );
        calcCenter.call ( this );
        
      }.bind ( this ) )
      
      showCaseEvent = EventDelegator ( "click" , privateVar.rollList );
      
      $( "#close" )
        .bind ( "click" , function () {
          privateVar.showCase.fadeOut ( 600 );
          privateVar.bigImage.find ( "img.imageData" ).remove ();
        })
      
      showCaseEvent.addDelegator ({
        type : "class",
        name : "showDetail",
        eventType : "click",
        reciever : function ( e ) {
          e.preventDefault ();
          that.showDetail ( $ ( this ) )
        }
      })
      
    };
    
    self.prev = function ( mul ) {
      
      mul = ( typeof ( mul ) === "number" )? mul : 1;
      
      var privateVar = privates ( this ),
          index = privateVar.currentLarge,
          left = parseFloat ( privateVar.rollList.css ( "marginLeft" ) ) + ( LIST_SIZE * mul ),
          that = this;
      
      if ( privateVar.prevent === true ) {
        return false;
      }
      
      $ ( "#rollList li" ).removeClass ( LARGE_CLASS ).removeClass ( SEMI_LARGE_CLASS );
      
      privateVar.prevent = true;
      
      privateVar.rollList.animate ( { "marginLeft" : left } , 500 , function () {
        
        privateVar.rollList.css ( "marginLeft" , left - ( mul * LIST_SIZE ) );
        
        
        setCenterClass ( ( index - mul ) );
        
        
        for ( var i = 0; i < mul; ++i ) {
          privateVar.rollList.prepend ( $ ( "#rollList li" ).eq ( privateVar.listCounts - 1 ) );
        }
        
        setText ( privateVar );
        
        privateVar.prevent = false;
        
        
      });

    }
    
    self.next = function ( mul ) {
      
      mul = ( typeof ( mul ) === "number" )? mul : 1;
      
      var privateVar = privates ( this ),
          index = privateVar.currentLarge,
          left = parseFloat ( privateVar.rollList.css ( "marginLeft" ) ) - ( mul * LIST_SIZE ),
          that = this;
      
      if ( privateVar.prevent === true ) {
        return false;
      }
      
      $ ( "#rollList li" ).removeClass ( LARGE_CLASS ).removeClass ( SEMI_LARGE_CLASS );
      
      privateVar.prevent = true;
      
      privateVar.rollList.animate ( { "marginLeft" : left } , 500 , function () {
        
        privateVar.rollList.css ( "marginLeft" , left + ( mul * LIST_SIZE ) );
        
        setCenterClass ( ( index + mul ) );
        privateVar.currentLarge = index;
        
        for ( var i = 0; i < mul; ++i ) {
          privateVar.rollList.append ( $ ( "#rollList li" ).eq ( 0 ) );
        }
        
       
        setText ( privateVar );
      
        privateVar.prevent = false;
        
      });
    };
    
    
    self.showDetail = function ( target ) {
      
      target = ( target [ 0 ].nodeName === "LI" )? target : target.parents ( "li" );
      
      if ( target.hasClass ( LARGE_CLASS ) ) {
        
        var privateVar = privates ( this ),
            urlData = target.attr ( "url-data" ).split (","),
            info = Info().get () [ urlData [ 1 ] ];
        
        privateVar.name.html ( info.name );
        privateVar.about.html ( info.about );
        privateVar.use.html ( info.use );
        
        privateVar.pbar.show ();
        
        privateVar.showCase.height ( $( document ).height () - 150 ).fadeIn ( 600 , function () {
          loadImage ( {src : urlData [ 0 ]} , function ( image ) {
            privateVar.pbar.fadeOut ( 200 , function () {
              image.style.display = "none";
              privateVar.bigImage.append ( image );
              $( image ).fadeIn ( 200 );
            })
          })
        })
               
      }else{
        
        var privateVar = privates ( this ),
            index = target.index (),
            diff = privateVar.currentLarge - index;
        
        if ( diff < 0 ) {
          diff = diff * -1;
          this.next ( diff );
        }else{
          this.prev ( diff );
        }
      }
      
    }
    
  }
);
