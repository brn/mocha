#include <compiler/scanner/token_stream.h>
#include <compiler/tokens/token_info.h>
#include <utils/pool/managed_handle.h>
#include <utils/int_types.h>

namespace mocha {

static const int max_element = 6;

class TokenContainer {
 public :
  TokenContainer( const char* token , int type , long line )
      :  size( 0 ) , next( 0 ) , prev( 0 ) {
    Push( token , type , line );
  }

  void Push( const char* token , int type , long line ) {
    TokenInfo* info = ManagedHandle::Retain( new TokenInfo( token , type , line ) );
    array[ size ] = reinterpret_cast<uintptr_t>( info );
    size++;
  }

  TokenInfo* Get( int index ) {
    return reinterpret_cast<TokenInfo*>( array[ index ] );
  }
  
  int size;
  TokenContainer* next;
  TokenContainer* prev;

 private :
  uintptr_t array[ max_element ];
};


TokenStream* TokenStream::Create() {
  return ManagedHandle::Retain( new TokenStream );
}

TokenStream::TokenStream() : cursor_( 0 ) , current_( 0 ) , head_( 0 ) , tail_( 0 ){};
TokenStream::~TokenStream() {
  TokenContainer *next = head_;
  while ( next ) {
    TokenContainer* tmp = next->next;
    delete next;
    next = tmp;
  }
};


TokenInfo* TokenStream::Advance( int index ) {
  if ( index < 1 ) return 0;
  int count = cursor_;
  TokenContainer* tmp = current_;
  TokenInfo* ret;
  for ( int i = 0; i < index; i++ ) {
    if ( count == current_->size ) {
      current_ = current_->next;
      if ( current_ == 0 ) {
        current_ = tmp;
        return kEmpty;
      } else {
        count = 0;
      }
    }
    ret = current_->Get( count );
    count++;
  }
  cursor_ = count;
  return ret;
}



void TokenStream::Append( const char* token , int type , long line ) {
  if ( head_ == 0 ) {
    head_ = new TokenContainer( token , type , line );
    current_ = tail_ = head_;
  } else {
    if ( head_->size < max_element ) {
      tail_->Push( token , type , line );
    } else {
      TokenContainer* tmp = new TokenContainer( token , type , line );
      tail_->next = tmp;
      tmp->prev = tail_;
      tail_ = tmp;
    }
  }
  size_++;
}


TokenInfo* TokenStream::Undo( int index ) {
  if ( index < 0 ) return kEmpty;
  int count = cursor_;
  TokenContainer* tmp = current_;
  TokenInfo* ret;
  for ( int i = 0; i < index; i++ ) {
    if ( count < 0 ) {
      current_ = current_->prev;
      if ( current_ == 0 ) {
        current_ = tmp;
        return kEmpty;
      } else {
        count = current_->size;
      }
    }
    count--;
    ret = current_->Get( count );
  }
  cursor_ = count;
  return ret;
}


TokenInfo* TokenStream::Seek( int index ) {
  int cursor = cursor_;
  TokenContainer* tmp = current_;
  TokenInfo* info = ( index > 0 )? Advance( index ) : Undo( ( -1 * index ) );
  current_ = tmp;
  cursor_ = cursor;
  return info;
}


int TokenStream::Size() const { return size_; }

TokenInfo* TokenStream::First() const {
  if ( head_ ) {
    return head_->Get( 0 );
  }
  return 0;
}

TokenInfo* TokenStream::Last() const {
  if ( tail_ ) {
    return tail_->Get( tail_->size - 1 );
  }
  return 0;
}

TokenInfo* TokenStream::kEmpty = 0;

}
