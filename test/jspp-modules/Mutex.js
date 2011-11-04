/*
*Module Mutex.
*Author Taketoshi Aono
*export <Mutex>
*/

/**
*@class
*Controller of the critcal session for async call.
*/
Class( "Mutex" )
 (function ( self , privates ) {
  
  self.__init__    = Mutex_new
  self.scopeLock   = Mutex_scopeLock;
  self.scopeUnlock = Mutex_scopeUnLock;
  self.wait        = Mutex_wait;
  self.isLocked    = Mutex_isLocked;
  
  /**
  *@constructor
  *Add the "mutexQueue" , "_scoped_lock" property to instance.
  *A mutexQueue is an array that pool running queue.
  *A _scoped_lock is a Boolean that distinct the current session is locked or not.
  */
  function Mutex_new () {
    privates ( this , {
      mutexQueue : [],
      _scoped_lock : false
    } )
  }
  
  /**
  *@memberOf lib.std.mutex
  *Lock current session.
  */
  function Mutex_scopeLock () {
    privates ( this )._scoped_lock = true
  }
  
  /**
  *@memberOf lib.std.mutex
  *@returns {ANY} Return the mutexQueue head.
  *unlock current session, and return queue head.
  */
  function Mutex_scopeUnLock () {
    var privateVar = privates ( this )
    privateVar._scoped_lock = false
    return ( privateVar.mutexQueue.length > 0 )? privateVar.mutexQueue.shift () : null
  }
  
  /**
  *@memberOf lib.std.mutex
  *@param {Function}
  *add a function to the mutexQueu tail.
  */
  function Mutex_wait ( arg ) {
    privates ( this ).mutexQueue.push ( arg )
  }
  
  /**
  *@memberOf lib.std.mutex
  *@returns {Boolean} Return _scoped_lock
  *Check current session is now locked or not;
  */
  function Mutex_isLocked () {
    return privates ( this )._scoped_lock;
  }
});
