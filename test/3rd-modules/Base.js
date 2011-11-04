
Class ( "Base" )(
  
  function ( self , privates ) {
    
    self.__static__.init = function () {
      
      $ ( "img[src*=_off]" )
        .bind ( "mouseover" , function () {
          this.src = this.src.replace ( "_off" , "_on" );
        })
      
        .bind ( "mouseout" , function () {
          this.src = this.src.replace ( "_on" , "_off" );
        })
      
    }
    
  }
  
)