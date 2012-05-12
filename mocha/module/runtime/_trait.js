/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */

Runtime.{
  traitMixin( dest , source , with_ , without ) {
    if ( !dest._mochaTraitMark || !source._mochaTraitMark ) {
      Runtime.throwException( "mixin only used for trait." );
    } else {
      var destTraitPrivate = dest._mochaTraitPrivate,
          sourceTraitPrivate = source._mochaTraitPrivate,
          destTraitPublic = dest._mochaTraitPublic,
          sourceTraitPublic = source._mochaTraitPublic,
          sourceRequires = source._mochaRequires,
          destRequires = dest._mochaRequires,
          tmp;
      for ( var i in sourceTraitPrivate ) {
        if ( !without[ i ] ) {
          tmp = ( !with_[ i ] )? i : with_[ i ];
          destTraitPrivate[ tmp ] = sourceTraitPrivate[ i ];
        }
      }
      for ( i in sourceTraitPublic ) {
        if ( !without[ i ] ) {
          tmp = ( !with_[ i ] )? i : with_[ i ];
          destTraitPublic[ tmp ] = sourceTraitPublic[ i ];
        }
      }
      for ( i in sourceRequires ) {
        destRequires[ i ] = sourceRequires[ i ];
      }
    }
  },
  
  classMixin({prototype : constructorProto}, {prototype : privateProto},
             {_mochaTraitMark : mark, _mochaTraitPublic : traitPublic, _mochaTraitPrivate : traitPrivate},
             with_, without)
  {
    if ( !mark ) {
      Runtime.throwException( "mixin only used for trait." );
    } else {
      var tmp;
      for ( var i in traitPublic ) {
        if ( !without[ i ] ) {
          tmp = ( !with_[ i ] )? i : with_[ i ];
          constructorProto[ tmp ] = traitPublic[ i ];
        }
      }
      for ( i in traitPrivate ) {
        if ( !without[ i ] ) {
          tmp = ( !with_[ i ] )? i : with_[ i ];
          privateProto[ tmp ] = traitPrivate[ i ];
        }
      }
    }
  },
  
  checkRequirements( {prototype:proto1}, {prototype:proto2} , traits , file , line ) {
    for ( var i = 0,len = traits.length; i < len; i++ ) {
      var {_mochaRequires} = traits[ i ];
      for ( var prop in _mochaRequires ) {
        if ( !( prop in proto1 ) && !( prop in proto2 ) ) {
          Runtime.throwException( "Class dose not meet the traits requirement. traits require implementation of property "
                                  + prop + "\nin file " + file + " at line " + line );
        }
      }
    }
  }
};

