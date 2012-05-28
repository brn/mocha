
exports.makeClassTester = function () {
  
  Class ( "testClass1" ) (
    function ( self , privates ) {
      
      self.__init__ = function ( name , name2 , name3 ) {
        privates ( this , {
          name : name,
          name2 : name2,
          name3 : name3
        })
      }
      
      self.name = "testDriver-makeClassTester";
      
      self.getName1 = function () {
        return privates ( this ).name;
      }
      
      self.getName2 = function () {
        return privates ( this ).name2;
      }
      
      self.getName3 = function () {
        return privates ( this ).name3;
      }
      
    }
  )
  
  var test = testClass1 ( "test" , "test2" , "test3" );
  
  assert.True ( test.getName1 () === "test" )
  assert.True ( test.getName2 () === "test2" );
  assert.True ( test.getName3 () === "test3" );  
}

exports.ClassInheritTest = function () {
  
  Class ( "Super" ) (
    function ( self , privates ) {
      self.__init__ = function () {
        privates ( this , {
          superProp : "Super-prop"
        })
      }
      
      self.__virtual__.getProp = function () {
        return privates ( this ).superProp;
      }
    }
  )
  
  Class ( "Child1" , Super ) (
    function ( self , privates , virtual ) {
      self.__init__ = function () {
        this.__super__ ();
        privates ( this , {
          child1 : "Child-prop",
          child2 : "Child-prop2"
        })
      }
      
      self.__override__.getProp = function () {
        return privates ( this ).child1;
      }
      
      self.__virtual__.getProp2 = function () {
        return privates ( this ).child2;
      }
      
      self.getSuperProp = function () {
        return virtual.getProp.call ( this );   
      }
      
    }
  )
  
  Class ( "child2" , Child1 ) (
    function ( self , privates , virtual ) {
      self.__init__ = function () {
        this.__super__ ();
      }
      self.getPropChild2 = function () {
        return "last-child";
      }
    }
  )
  
  var _child1 = Child1 (),
      _child2 = child2 ();
  
  assert.True ( _child1.getProp () === "Child-prop" );
  assert.True ( _child1.getProp2 () === "Child-prop2" );
  assert.True ( _child1.getSuperProp () === "Super-prop" );
  
  assert.True ( _child2.getProp () === "Child-prop" );
  assert.True ( _child2.getProp2 () === "Child-prop2" );
  assert.True ( _child2.getSuperProp () === "Super-prop" );
  assert.True ( _child2.getPropChild2 () === "last-child" );
  
}

exports.multiInheritanceTester = function () {
  
  Class ( "Super1" ) (
    function ( self, privates ) {
      self.__init__ = function () {
        privates ( this , {
          s : 100
        })
      }
    }
  )
  
  Class ( "Super2" ) (
    function ( self , privates ) {
      self.test = function () {
        return 200;
      }
    }
  )
  
  Class ( "Super3" ) (
    function ( self , privates ) {
      self.test2 = function () {
        return 300;
      }
    }
  )
  
  Class ( "Child" , Super1 , Super2 , Super3 ) (
    function ( self , privates ) {
      self.__init__ = function () {
        this.__super__ ();
      }
      self.getSuperProto = function () {
        return privates ( this ).s;
      }
    }
  )
  
  var child = Child ();
  
  assert.True ( child.getSuperProto () === 100 );
  assert.True ( child.test () === 200 );
  assert.True ( child.test2 () === 300 );
    
}
