/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
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

#ifndef ScannerState_H
#define ScannerState_H

#include "uncopyable.h"
#include "define.h"

namespace mocha {

  class ScannerState : private Uncopyable {

  public:
    
    inline ScannerState () {};
    inline ~ScannerState () {};
    
    inline JPM_CONST bool IsRegExpAfter () const {
      
      return isRegExpAfter_ == 1;
    
    }
    
    inline void RegExpAfter () {
      isRegExpAfter_ = 1;
    }

    inline void NotRegExpAfter () {
      isRegExpAfter_ = 0;
    }
    
    inline JPM_CONST bool IsNumericAfter () const { 
      return isNumericAfter_ == 1;
    }

    inline void NumericAfter () {
      isNumericAfter_ = 1;
    }
    
    inline void NotNumericAfter () {
      isNumericAfter_ = 0;
    }
    
    void Reset ();

  private:
    
    unsigned isRegExpAfter_ : 1;
    unsigned isNumericAfter_ : 1;
    char stringType_;
    
  };

}

#endif

