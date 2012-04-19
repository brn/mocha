module testModule3_1 {

  export testExport3_1()->1;

}

module testModule3_2 {
  module testInnerModule3_3 {
    export testExport3_2()->2;
    export testExport3_3 = {test:200};
  }
}

module testModule3_4 {
  export testExport3_4()->3;
}
module testExport3_5 = ->4;
