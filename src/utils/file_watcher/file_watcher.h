#ifndef mocha_file_watcher_h_
#define mocha_file_watcher_h_
#include <utils/smart_pointer/scope/scoped_ptr.h>

namespace mocha {

#define CONSTRACT(name) name( const char* filename_ ) : filename( filename_ ){}; const char* filename
namespace watch_traits {
struct Access{ CONSTRACT(Access); };
struct Modify{ CONSTRACT(Modify); };
struct Attrib{ CONSTRACT(Attrib); };
struct Open{ CONSTRACT(Open); };
struct Close{ CONSTRACT(Close); };
struct MoveSelf{ CONSTRACT(MoveSelf); };
struct MoveFrom{ CONSTRACT(MoveFrom); };
struct MoveTo{ CONSTRACT(MoveTo); };
struct Delete{ CONSTRACT(Delete); };
struct DeleteSelf{ CONSTRACT(DeleteSelf); };
struct Create{ CONSTRACT(Create); };
}
#undef CONSTRACT
class IUpdater {
 public :
  virtual ~IUpdater(){};
  virtual void Update( watch_traits::Access* access ){};
  virtual void Update( watch_traits::Modify* access ){};
  virtual void Update( watch_traits::Attrib* access ){};
  virtual void Update( watch_traits::Open* access ){};
  virtual void Update( watch_traits::Close* access ){};
  virtual void Update( watch_traits::MoveSelf* access ){};
  virtual void Update( watch_traits::MoveFrom* access ){};
  virtual void Update( watch_traits::MoveTo* access ){};
  virtual void Update( watch_traits::DeleteSelf* access ){};
  virtual void Update( watch_traits::Delete* access ){};
  virtual void Update( watch_traits::Create* access ){};
};

class FileWatcher {
 public :
  FileWatcher();
  inline ~FileWatcher(){};
  enum {
    kAccess = 0x00000001,
    kModify = 0x00000002,
    kAttrib = 0x00000004,
    kOpen = 0x00000008,
    kClose = 0x00000010,
    kMoveSelf = 0x00000012,
    kMovedFrom = 0x00000020,
    kMovedTo = 0x00000040,
    kDeleteSelf = 0x00000080,
    kDelete = 0x00000100,
    kCreate = 0x00000110,
    kAdd
  };
  void AddWatch( const char* path , IUpdater* updater , int type );
  void UnWatch( const char* path );
  void UnWatchAll();
  void Stop();
  void Start();
  void Exit();
 private :
  class PtrImpl;
  PtrImpl* implementation_;
};

}
#endif
