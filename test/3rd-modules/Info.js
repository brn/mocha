
var Request = require ( "Request" ).Request;

Class ( "Info" )(
  
  function ( self , privates ) {
    
    function send ( req , privateVar ) {
      
      req.addListener ( "complete" , function ( data ) {
          privateVar.info = data;
      })
      
      req.addListener ( "error" , function () {
        if ( privateVar.tried < 5 ) {
          privateVar.tried++;
          send ( req , privateVar );
        }
      })
      
      req.send ({
        url : "src/info.json",
        dataType : "json",
        type : "GET"
      });
      
    };
    
    
    self.__singleton__ = true;
    
    self.__init__ = function () {
      
      privates ( this , {} );
      
      var req = Request (),
          privateVar = privates ( this );
      
      privateVar.tried = 0;
      send ( req , privateVar );
      
    }
    
    self.get = function () {
      return privates ( this ).info;
    }
    
  }
  
)