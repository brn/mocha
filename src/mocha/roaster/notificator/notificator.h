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
#ifndef roaster_notificator_h_
#define roaster_notificator_h_
#include <mocha/roaster/notificator/listener_adapter.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {

/**
 * @class
 * The event observer implementation.
 */
template<typename Event>
class Notificator {
  // The unordered_multimap entry type.
  typedef std::pair<const char*, ListenerAdapterBase<Event>*> ListenerSet;
  typedef roastlib::unordered_multimap<std::string, ListenerAdapterBase<Event>*> Listeners;
  typedef typename Listeners::iterator ListenersIterator;
  // The unordered_multimap equal_range type.
  typedef std::pair<ListenersIterator, ListenersIterator> ListenersRange;

 public :
  
  template <typename Fn, typename Class>
  class MemBind {
   public :
    MemBind(Fn fn, Class cl);
    MemBind(const MemBind&);
    void operator()(Event e);
   private :
    Class cls_;
    Fn fn_;
  };

  Notificator();
  virtual ~Notificator(){};

  /**
   * @public
   * @param {const char*} key
   * @param {Listener} listener
   * Add listener to the observer.
   * The added listener is identified by the string key.
   */
  template <typename Listener>
  void AddListener(const char* key, Listener listener);

  void RemoveListener(const char* key);
  
  /**
   * @public
   * @param {Event} e
   * Notify event to the all listeners.
   */
  void NotifyAll(Event e);

  /**
   * @public
   * @param {const char*} key
   * @param {Event} e
   * Notify event to the observer that is identified by key.
   */
  void NotifyForKey(const char* key, Event e);

  /**
   * @public
   * @returns {int}
   * Return registered listener number.
   */
  int size() const {return listeners_.size();}
  template <typename Fn, typename Class>

  //VC bug. The complex template type cannot write the out of
  //class definition.
  static MemBind<Fn, Class> Bind(Fn fn, Class cls) {
    return MemBind<Fn, Class>(fn, cls);
  }
 private :
  memory::Pool pool_;
  Listeners listeners_;
};
}
#include <mocha/roaster/notificator/notificator-impl.h>

#endif
