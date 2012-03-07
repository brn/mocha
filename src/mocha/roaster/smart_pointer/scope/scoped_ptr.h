/**
 *@author Taketoshi Aono
 *@fileOverview
 *Declaration file of class mocha::ScopedPtr, mocha::ScopedArray, mocha::ScopedAllocator.
 *Copyright (c) 2011 Taketoshi Aono
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


#ifndef mocha_scoped_ptr_h_
#define mocha_scoped_ptr_h_
#include <useconfig.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/smart_pointer/common/ptr_deleter.h>
#include <mocha/roaster/smart_pointer/common/ptr_handle.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>

namespace mocha {

/**
 * @class
 * Controll pointer lifetime.
 * Release pointer when class was destructed.
 * Not copyable, but can convert to mocha::Handle.
 */
template <typename T >
class ScopedPtr : private Uncopyable {
 public :

  /**
   * @constructor
   * param {<Class>} ptr -> Manage target.
   * param {<Deleter>} deleter -> Pointer destructor function.
   * Constructor with deleter.
   */
  template <typename Class, typename Deleter>
  inline ScopedPtr(Class* ptr,  Deleter deleter);

  /**
   * @constructor
   * param {<Class>} ptr -> Manage target.
   * Simple constructor.
   * If not select a deleter, the deleter is selected as mocha::PtrDeleter<T>::deleter.
   */
  template <typename Class>
  inline ScopedPtr(Class* ptr);

  /**
   * @constructor
   * Default constructor to keep ScopedPtr as class member or,
   * container member like stl.
   */
  inline ScopedPtr();

  /**
   * Destructor.
   * Call PtrHandle::dispose if ScopedPtr::ToHandle is not called.
   */
  inline ~ScopedPtr();

  /**
   * @public
   * param {<Class>} ptr -> Manage target.
   * param {<Deleter>} deleter -> Pointer destructor function.
   * Lazy initializer with deleter.
   */
  template <typename Class, typename Deleter>
  inline void operator () (Class* ptr, Deleter deleter);

  /**
   * @public
   * param {<Class>} ptr -> Manage target.
   * param {<Deleter>} deleter -> Pointer destructor function.
   * Lazy simple initializer.
   */
  template <typename Class>
  inline void operator () (Class* ptr);

  /**
   * @public
   * Pointer access operator.
   * This operator need for treat ScopedPtr as real pointer. 
   */
  inline T* operator -> ();

  /**
   * @public
   * @const
   * Pointer access operator for const.
   * This operator need for treat ScopedPtr as real pointer. 
   */
  inline const T* operator -> () const;

  /**
   * @public
   * @const
   * @returns {const <T*>}
   * Pointer access operator with const.
   * This operator need for treat ScopedPtr as real pointer. 
   */
  inline const T& operator * () const;

  /**
   * @public
   * @returns {<T*>}
   * Pointer access operator.
   */
  inline T& operator * ();

  /**
   * @public
   * @returns {<T*>}
   * Resource getter.
   * It's an ugly, but need.
   */
  inline T* Get();

  /**
   * @public
   * @returns {<T*>}
   * Resource getter for const.
   */
  inline const T* Get() const;


  /**
   * @public
   * @returns {SharedPtr<T>}
   * Convert to mocha::Handle.
   */
  inline SharedPtr<T> ToSharedPtr();
 private :

  /**
   * @private
   * Called from operator ().
   */
  inline void LazyInitialize_(PtrHandleBase* base, T* ptr);

  /**
   * @private
   * Refference getter.
   */
  inline T& GetReference_();

  /**
   * @private
   * Check an initialization.
   */
  inline void CheckInit_ (const char* message) const;

  //Is ToHandle called?
  bool is_renounced_;
  T* ptr_;
  PtrHandleBase* handle_;
};

/**
 * @class
 * ScopedPtr for new [].
 */
template <typename T>
class ScopedArray : public ScopedPtr<T> {
 public :
  /**
   * @constructor
   * ScopedArray has only simple constructor.
   * Deleter is selected as PtrDeleter::deleterArray.
   */
  template <typename Class>
  inline ScopedArray(Class* ptr);

  /**
   * @constructor
   * Constructor for container or class member.
   */
  inline ScopedArray();

  /**
   * @constructor
   * Operator for lazy initialization.
   */
  template <typename Class>
  inline void operator () (Class* ptr);
};


/**
 * @class
 * ScopedPtr for malloc.
 */
template <typename T>
class ScopedAllocater : public ScopedPtr<T> {
 public :
  /**
   * @constructor
   * @param {<Class*>} ptr
   * ScopedAllocater has only simple constructor.
   * Deleter is selected as PtrDeleter::freePtr.
   */
  template <typename Class>
  inline ScopedAllocater(Class* ptr);

  /**
   * @constructor
   * Constructor for container or class member.
   */
  inline ScopedAllocater();

  /**
   * @public
   * @param {<Class*>} ptr
   * Operator for lazy initialization.
   */
  template <typename Class>
  inline void operator () (Class* ptr);
};

}

#include <mocha/roaster/smart_pointer/scope/scoped_ptr-impl.h>

namespace mocha {
//Default type definition.
typedef ScopedArray<const char> ScopedStr;
typedef ScopedArray<const wchar_t> ScopedWStr;
typedef ScopedAllocater<const char> ScopedCStr;
typedef ScopedAllocater<const wchar_t> ScopedWCStr;
}

#endif
