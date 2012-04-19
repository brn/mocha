import {
  testModule1:{
    testExport1
  },
  testModule2:{
    testInnerModule3:{
      testExport2,
      testExport3
    }
  },
  testModule4:{
    testExport4
  },
  testExport5
} from "./module_test";

import './module_test2' as moduleTest2;
import '*' from './module_test3'

@assert( true , testExport1() === 1 );
@assert( true , testExport2() === 2 );
@assert( true , testExport3.test === 200 );
@assert( true , testExport4() === 3 );
@assert( true , testExport5() === 4 );

module testModule {
  export foo()->"ok";
}

import {foo} from testModule;
@assert( true ,foo() === "ok" );
