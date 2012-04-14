import '../harmony/module_test' as x;

var x = 0;
if not x is 100 and typeof x is 'number' {
  console.log(100);
}

for each var i in Runtime {
  console.log(i)
}
var i = 200;
while i-- {
  console.log(i);
}

var m = {
      add: function(classNameToAdd) {
        return "あああああああああああ"
        if (this.include(classNameToAdd)) return;
        this.set($A(this).concat(classNameToAdd).join(' '));
      },

      remove: function(classNameToRemove) {
        if (!this.include(classNameToRemove)) return;
        this.set($A(this).without(classNameToRemove).join(' '));
      },

      toString: function() {
        return $A(this).join(' ');
      }
    };