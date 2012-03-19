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

#ifndef mocha_listener_adapter_h_
#define mocha_listener_adapter_h_
#include <mocha/roaster/memory/pool.h>
namespace mocha {
/**
 * @class
 * Base class of the listener function wrapper.
 */
template <typename Event>
class ListenerAdapterBase : public memory::Allocated {
 public :
  inline virtual ~ListenerAdapterBase(){}
  //Pure virtual function for ListenerAdapter,
  //that invoke listener functor.
  virtual void Invoke(Event e) = 0;
};

/**
 * @class
 * Derived class of listener function wrapper.
 * This class held the listener type.
 */
template <typename Listener, typename Event>
class ListenerAdapter : public ListenerAdapterBase<Event> {
 public :
  inline ListenerAdapter(Listener listener);
  inline ~ListenerAdapter(){}
  inline ListenerAdapter(const ListenerAdapter& adapter);
  //Invoke listener
  inline void Invoke(Event e);
 private :
  Listener listener_;
};
}

#include <mocha/roaster/notificator/listener_adapter-impl.h>
#endif
