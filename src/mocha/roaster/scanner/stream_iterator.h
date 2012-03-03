#ifndef mocha_stream_iterator_h_
#define mocha_stream_iterator_h_
namespace mocha {

class StreamIteratorBase {
 public :
  StreamIteratorBase( DataContainer* container );
  ~StreamIteratorBase();
 protected :
  enum {
    kNoReach,
    kEnd,
    kBegin
  };
  bool HasItemTowardsToBeginPoint();
  bool HasItemTowardsToEndPoint();
  DataContainer* TowardsToBeginPoint();
  DataContainer* TowardsToEndPoint();
  
  int index_;
  int is_reach_;
  TokenContainer* container_;
};
}
