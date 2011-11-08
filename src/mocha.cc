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
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include "useconfig.h"
#include "mocha.h"
#include "compiler.h"
#include "thread.h"
#include "icommandline_runner.h"
#include "help_runner.h"
#include "compile_runner.h"
#include "observer_runner.h"
#include "file_system.h"
#include "setting.h"
namespace mocha {

class Mocha::PtrImpl {
 public :
  PtrImpl( ICommandLineRunner* runner ) : runner_( runner ){}
  ~PtrImpl() { delete runner_; }
  ICommandLineRunner* GetRunner() {
    return runner_;
  }
 private :
  ICommandLineRunner* runner_;
};

Mocha::Mocha ( Options* options ) {
  ICommandLineRunner *runner;
  if ( options->IsShowHelp() ) {
    runner = new HelpRunner( options );
  } else if ( options->IsCommandLineCompile() && options->IsPath() ) {
    runner = new CompileRunner( options );
    Setting::GetInstance()->Log( "start commandline compile mode." );
  } else if ( options->IsWatchXML() ) {
    runner = new ObserverRunner( options );
    Setting::GetInstance()->Log( "start watching xml mode." );
  }
  implementation_( new PtrImpl( runner ) );
}

void Mocha::Run() {
  implementation_->GetRunner()->Run();
}

}
