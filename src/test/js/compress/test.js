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