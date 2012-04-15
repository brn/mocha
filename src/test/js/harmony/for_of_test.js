import {iterator} from "iterators".iterators;
var item = function ( obj ) {
      return {
        [iterator] : function () {
          for each ( var i in obj ) {
            yield i;
          }
        }
      }
    },
    key = function ( obj ) {
      return {
        [iterator] : function () {
          for ( var i in obj ) {
            yield i;
          }
        }
      }
    },
    iter = {
      arr : [],
      add : function ( value ) {
        this.arr.push( value );
      },
      [iterator] : function () {
        var arr = this.arr;
        return {
          index : 0,
          next : function () {
            if ( arr.length > this.index ) {
              var ret = arr[ this.index ];
              this.index++;
              return ret;
            } else {
              throw StopIteration;
            }
          }
        }
      }
    }

var testObj = {
      value1 : 100,
      value2 : 200,
      value3 : 300,
      value4 : 400
    }
var ret = [];
for ( var i of item( testObj ) ) {
  ret.push( i );
}
@assert( true , ret[ 0 ] === 100 );
@assert( true , ret[ 1 ] === 200 );
@assert( true , ret[ 2 ] === 300 );
@assert( true , ret[ 3 ] === 400 );

ret = [];
for( var x of key( testObj ) ) {
  ret.push( x );
}
@assert( true , ret[ 0 ] === "value1" );
@assert( true , ret[ 1 ] === "value2" );
@assert( true , ret[ 2 ] === "value3" );
@assert( true , ret[ 3 ] === "value4" );

ret = [];
iter.add( 100 );
iter.add( 200 );
iter.add( 300 );
iter.add( 400 );
for ( i of iter ) {
  ret.push( i );
}
@assert( true , ret[ 0 ] === 100 );
@assert( true , ret[ 1 ] === 200 );
@assert( true , ret[ 2 ] === 300 );
@assert( true , ret[ 3 ] === 400 );
