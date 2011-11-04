
Class ( "publicClass" ) (
  function ( self , privates ) {
    self.__init__ = function () {}
  }
)

Class ( "__privateScope" ) (
  function ( self , privates ) {
    self.__init__ = function () {};
  }
)

exports.publicMember = true;

