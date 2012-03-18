#ifndef roaster_notificator_h_
#define roaster_notificator_h_
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

template <typename T>
class Dereferrence {
  inline static T& Get(T& t) {
    return t;
  }
};

template <typename T>
class Dereferrence<T*> {
  inline static T& Get(T* t) {
    return *t;
  }
};

template <typename T>
class Dereferrence<T&> {
  inline static T& Get(T& t) {
    return t;
  }
};

#define TEMPLATE template<typename Listener, typename Event>

TEMPLATE
inline Notificator::Notificator(){}

TEMPLATE
inline Notificator::~Notificator(){}

TEMPLATE
inline void Notificator::AddListener(Listener listener) {
  listener_.insert(ListenerSet(Dereferrence::Get(listener).key(), listener));
}

TEMPLATE
inline void Notificator::NotifyAll(Event e) {
  for (Listeners::iterator it = listeners_.begin(); it != listeners_.end(); ++it) {
    Dereferrence::Get((*it)).Recieve(e);
  }
}

TEMPLATE
inline void Notificator::NotifyForKey(const char* key, Event e) {
  ListenersRange range = listeners_.equal_range(key);
  for (Listeners::iterator it = range.first; it != range.second; ++it) {
    Dereferrence::Get((*it)).Recieve(e);
  }
}

#undef TEMPLATE

}

#endif
