
var object = {
      value1 : 100,
      value2 : {
        value3 : 100
      },
      value4 : [100,200,300],
      value5 : {
        value6 : [{value7 : 100}]
      },
      "@value" : {
        strvalue : 100
      }
    },
    array = [{value1 : 100},200,{value2:100},{"value3" : 100},{value4:{value5:[100,200]}}];

(function () {
  var {value1,value2:{ value3 },value4 : [ value5_,value6_,value7_ ],value5 : { value6 : [{value7}] },"@value":{strvalue}} = object;
  @assert( true , value1 === 100 );
  @assert( true , value3 === 100 );
  @assert( true , value5_ === 100 );
  @assert( true , value6_ === 200 );
  @assert( true , value7_ === 300 );
  @assert( true , value7 === 100 );
  @assert( true , strvalue === 100 );
  
  ({value1,value2:{ value3 },value4 : [ value5_,value6_,value7_ ],value5 : { value6 : [{value7}] },"@value":{strvalue}}) = object;
  @assert( true , value1 === 100 );
  @assert( true , value3 === 100 );
  @assert( true , value5_ === 100 );
  @assert( true , value6_ === 200 );
  @assert( true , value7_ === 300 );
  @assert( true , value7 === 100 );
  @assert( true , strvalue === 100 );
  
})();

(function () {
  var [{value1},arr_value1,{value2},{"value3":value3},{value4:{value5:[arr_value2,arr_value3]}}] = array;
  @assert( true , value1 === 100 );
  @assert( true , arr_value1 === 200 );
  @assert( true , value2 === 100 );
  @assert( true , value3 === 100 );
  @assert( true , arr_value2 === 100 );
  @assert( true , arr_value3 === 200 );
  [{value1},arr_value1,{value2},{"value3":value3},{value4:{value5:[arr_value2,arr_value3]}}] = array;
  @assert( true , value1 === 100 );
  @assert( true , arr_value1 === 200 );
  @assert( true , value2 === 100 );
  @assert( true , value3 === 100 );
  @assert( true , arr_value2 === 100 );
  @assert( true , arr_value3 === 200 );
})();

(function () {
  var [{value1},arr_value1,{value2},{"value3":value3},{value4:{value5:[...arr_value2]}}] = array;
  @assert( true , value1 === 100 );
  @assert( true , arr_value1 === 200 );
  @assert( true , value2 === 100 );
  @assert( true , value3 === 100 );
  @assert( true , arr_value2[0] === 100 );
  @assert( true , arr_value2[1] === 200 );
  var arr_value4;
  [{value1},arr_value1,{value2},{"value3":value3},{value4:{value5:[...arr_value4]}}] = array;
  @assert( true , value1 === 100 );
  @assert( true , arr_value1 === 200 );
  @assert( true , value2 === 100 );
  @assert( true , value3 === 100 );
  @assert( true , arr_value4[0] === 100 );
  @assert( true , arr_value4[1] === 200 );
})();

(function ({value1,value2:{ value3 },value4 : [ value5_,value6_,value7_ ],value5 : { value6 : [{value7}] },"@value":{strvalue}}) {
  @assert( true , value1 === 100 );
  @assert( true , value3 === 100 );
  @assert( true , value5_ === 100 );
  @assert( true , value6_ === 200 );
  @assert( true , value7_ === 300 );
  @assert( true , value7 === 100 );
  @assert( true , strvalue === 100 );
})( object );


(function ([{value1},arr_value1,{value2},{"value3":value3},{value4:{value5:[arr_value2,arr_value3]}}]) {
  @assert( true , value1 === 100 );
  @assert( true , arr_value1 === 200 );
  @assert( true , value2 === 100 );
  @assert( true , value3 === 100 );
  @assert( true , arr_value2 === 100 );
  @assert( true , arr_value3 === 200 );
})( array );


(function ([{value1},arr_value1,{value2},{"value3":value3},{value4:{value5:[...arr_value2]}}]) {
  @assert( true , value1 === 100 );
  @assert( true , arr_value1 === 200 );
  @assert( true , value2 === 100 );
  @assert( true , value3 === 100 );
  @assert( true , arr_value2[0] === 100 );
  @assert( true , arr_value2[1] === 200 );
})( array );
