@include '_module'
module utility {

  export isDefined = ( obj ) -> obj !== undefined && obj !== null;

  const rnd = Math.random();

  export guidgen = -> ( "{" + [
    rnd().toString(16).slice(2, 10),
    rnd().toString(16).slice(2, 6),
    (rnd() * .0625 /* 0x.1 */ + .25 /* 0x.4 */).toString(16).slice(2, 6),
    (rnd() * .25 /* 0x.4 */ + .5 /* 0x.8 */).toString(16).slice(2, 6),
    rnd().toString(16).slice(2, 14)
  ].join('-') + "}" );

}