module testModule1 {

  export testExport1()->1;

}

module testModule2 {
  module testInnerModule3 {
    export testExport2()->2;
    export testExport3 = {test:200};
  }
}

module testModule4 {
  export testExport4()->3;
}
module testExport5 = ->4;


