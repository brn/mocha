
module testModule1 {

  export testExport1()->arguments;
  
}

module testModule2 {
  module testInnerModule3 {
    export testExport2()->arguments;
    export testExport3 = {test:200};
  }
}

module {
  module testInnerModule4 {
    export testExport4()->arguments;
  }
  export testExport5()->arguments;
}


