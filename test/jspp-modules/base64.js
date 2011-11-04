
/**
 * @fileOverview
 * Base64 encoding
 * http://www.ietf.org/rfc/rfc2045.txt
 */

var hasBtoa = (function () {
      try {
        var a = btoa ("aaa");
        return true;
      }catch (e) {
        return false
      }
    })();

if( !hasBtoa ){
  
  var enc_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".split(""),
      dec_table = [  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
      -1, -1, -1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
      -1, -1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1,
      63,52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1,
      -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
      16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26,
      27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
      44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1 ];
  
  function btoa( str ) {
    
      var out, i, len,
          c1, c2, c3,
          iter

      len = str.length;
      i   = 0;
      iter= -1;
      out = [];
      while( i < len ) {
        c1 = str.charCodeAt( i++ ) & 0xff;
        if(i === len){
            out[ ++iter ] = enc_table[ (c1 >> 2) ];
            out[ ++iter ] = enc_table[ ((c1 & 0x3) << 4) ];
            out[ ++iter ] = "==";
            break;
        }
        c2 = str.charCodeAt( i++ );
        if( i === len ){
            out[ ++iter ] = enc_table[ (c1 >> 2) ];
            out[ ++iter ] = enc_table[ (((c1 & 0x3)<< 4) | ((c2 & 0xF0) >> 4)) ];
            out[ ++iter ] = enc_table[ ((c2 & 0xF) << 2) ];
            out[ ++iter ] = "=";
            break;
        }
        c3 = str.charCodeAt( i++ );
        out[ ++iter ] = enc_table[ (c1 >> 2) ];
        out[ ++iter ] = enc_table[ (((c1 & 0x3)<< 4) | ((c2 & 0xF0) >> 4)) ];
        out[ ++iter ] = enc_table[ (((c2 & 0xF) << 2) | ((c3 & 0xC0) >>6)) ];
        out[ ++iter ] = enc_table[ (c3 & 0x3F) ];
      }
      return out.join( "" );
  }

  function atob(str) {
      
      var c1, c2, c3, c4,
          i, len, out,
          iter

      len = str.length;
      i = 0,
      iter = -1;
      out = [];
      
      while( i < len ) {
        /* c1 */
        do {
            c1 = dec_table[str.charCodeAt( i++ ) & 0xff];
        } while( i < len && c1 === -1 );
        if( c1 === -1 )
            break;

        /* c2 */
        do {
            c2 = dec_table[ str.charCodeAt(i++) & 0xff ];
        } while( i < len && c2 === -1 );
        if(c2 === -1)
            break;

        out[ ++iter ] = String.fromCharCode((c1 << 2) | ((c2 & 0x30) >> 4));

        /* c3 */
        do {
            c3 = str.charCodeAt(i++) & 0xff;
            if( c3 === 61 )
          return out.join( "" );
            c3 = dec_table[ c3 ];
        } while(i < len && c3 === -1);
        if(c3 === -1)
            break;

        out[ ++iter ] = String.fromCharCode( ((c2 & 0XF) << 4) | ((c3 & 0x3C) >> 2) );

        /* c4 */
        do {
            c4 = str.charCodeAt( i++ ) & 0xff;
            if( c4 == 61 )
          return out;
            c4 = dec_table[ c4 ];
        } while( i < len && c4 === -1 );
        if( c4 === -1 )
            break;
        out[ ++iter ] = String.fromCharCode(((c3 & 0x03) << 6) | c4);
      }
      return out.join( "" );
  }

  exports.atob = atob
  exports.btoa = btoa

}else{
  exports.atob = function( str ){ return atob ( str ) };
  exports.btoa = function( str ){ return btoa ( str ) };
}

