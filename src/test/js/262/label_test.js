var ret = 0;
TEST_LABEL : {
  ret = 100;
  break TEST_LABEL;
  ret = 200;
};
@assert( true , ret === 100 );

TEST_LABEL2 : ret = 200;
@assert( true , ret === 200 );
