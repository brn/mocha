#ifndef roaster_notificator_impl_h_
#define roaster_notificator_impl_h_
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

namespace mocha {

#define TEMPLATE template<typename Event>

TEMPLATE
template <typename Fn, typename Class>
inline Notificator<Event>::MemBind<Fn, Class>::MemBind(Fn fn, Class cls)
    : cls_(cls),
      fn_(fn){}

TEMPLATE
template <typename Fn, typename Class>
inline Notificator<Event>::MemBind<Fn, Class>::MemBind(const MemBind& membind) {
  cls_ = membind.cls_;
  fn_ = membind.fn_;
}

TEMPLATE
template <typename Fn, typename Class>
inline void Notificator<Event>::MemBind<Fn, Class>::operator()(Event e) {
  (Dereferrence<Class>::Get(cls_).*fn_)(e);
}

TEMPLATE
inline Notificator<Event>::Notificator(){}

TEMPLATE
template <typename Listener>
inline void Notificator<Event>::AddListener(const char* key, Listener listener) {
  //Listener adapter is allocated as the heap object,
  //because this object treat as the base class type ListenerAdapterBase.
  //Object lifetime is controlled by Notificator::pool_
  ListenerAdapter<Listener,Event>* adapter = new(&pool_) ListenerAdapter<Listener,Event>(listener);
  listeners_.insert(ListenerSet(key, adapter));
}


TEMPLATE
inline void Notificator<Event>::NotifyAll(Event e) {
  for (ListenersIterator it = listeners_.begin(); it != listeners_.end(); ++it) {
    (*it).second->Invoke(e);
  }
}

TEMPLATE
inline void Notificator<Event>::NotifyForKey(const char* key, Event e) {
  ListenersRange range = listeners_.equal_range(key);
  //Call all liteners that identified by same key.
  for (ListenersIterator it = range.first; it != range.second; ++it) {
    (*it).second->Invoke(e);
  }
}


TEMPLATE
template <typename Fn, typename Class>
inline typename Notificator<Event>::template MemBind<Fn, Class> Notificator<Event>::Bind(Fn fn, Class cls) {
  return MemBind<Fn, Class>(fn, cls);
}


#undef TEMPLATE

}

#endif
