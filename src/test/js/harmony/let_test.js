
var x = 0,
    ret = [];
for ( var i = 0; i < 10; i++ ) {
let ( i = i ) {
      ret.push( -> i )
    }
}

ret.forEach(( item , index ) -> {
  @assert( true , item() === index );
})

