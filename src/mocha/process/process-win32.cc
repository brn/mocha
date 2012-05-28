#include <stdio.h>
#include <mocha/process/process-win32.h>
#include <mocha/roaster/log/logging.h>

#define BUFSIZE 4096
#define FATAL_ESCAPE(msg) Logging::GetInstance()->Fatal(msg);return false;
namespace mocha {namespace os {
bool Process::Spawn(const char* name, const char* args) {
  result_.clear();
  std::string sh_args;
  SPrintf(&sh_args, "%s %s", name, args);
  FILE *fp;
  if ((fp = _popen(sh_args.c_str(), "r")) == NULL) {
    Logging::GetInstance()->Fatal("Cant open process %s", name);
    return false;
  }
  int ch;
  while ((ch = fgetc(fp)) != EOF) {
    result_ += ch;
  }
  _pclose(fp);
  return true;
  std::string saved_name = name;
  std::string saved_args = args;
  SECURITY_ATTRIBUTES s_attr;
  BOOL f_success;
 
  // Set the bInheritHandle flag so pipe handles are inherited. 
  s_attr.nLength = sizeof(SECURITY_ATTRIBUTES);
  s_attr.bInheritHandle = TRUE;
  s_attr.lpSecurityDescriptor = NULL;
 
  // The steps for redirecting child process's STDOUT: 
  //     1. Save current STDOUT, to be restored later. 
  //     2. Create anonymous pipe to be STDOUT for child process. 
  //     3. Set STDOUT of the parent process to be write handle to 
  //        the pipe, so it is inherited by the child process. 
  //     4. Create a noninheritable duplicate of the read handle and
  //        close the inheritable read handle. 
 
  // Save the handle to the current STDOUT. 
  saved_stdout_ = GetStdHandle(STD_OUTPUT_HANDLE); 
 
  // Create a pipe for the child process's STDOUT. 
  if (!CreatePipe(&child_stdout_rd_, &child_stdout_wr_, &s_attr, 0)) {
    FATAL_ESCAPE("Stdout pipe creation failed");
  }
 
  // Set a write handle to the pipe to be STDOUT. 
  if (!SetStdHandle(STD_OUTPUT_HANDLE, child_stdout_wr_)) {
    FATAL_ESCAPE("Redirecting STDOUT failed");
  }
 
  // Create noninheritable read handle and close the inheritable read 
  // handle. 
  f_success = DuplicateHandle(GetCurrentProcess(), child_stdout_rd_,
                              GetCurrentProcess(), &child_stdout_rd_dup_ , 0,
                              FALSE,
                              DUPLICATE_SAME_ACCESS);
  if(!f_success) {
    FATAL_ESCAPE("DuplicateHandle failed");
  }
  CloseHandle(child_stdout_rd_);

  // The steps for redirecting child process's STDIN: 
  //     1.  Save current STDIN, to be restored later. 
  //     2.  Create anonymous pipe to be STDIN for child process. 
  //     3.  Set STDIN of the parent to be the read handle to the 
  //         pipe, so it is inherited by the child process. 
  //     4.  Create a noninheritable duplicate of the write handle, 
  //         and close the inheritable write handle. 
 
  // Save the handle to the current STDIN. 
  saved_stdin_ = GetStdHandle(STD_INPUT_HANDLE); 
 
  // Create a pipe for the child process's STDIN. 
  if (!CreatePipe(&child_stdin_rd_, &child_stdin_wr_, &s_attr, 0)) {
    FATAL_ESCAPE("Stdin pipe creation failed");
  }
 
  // Set a read handle to the pipe to be STDIN. 
  if (!SetStdHandle(STD_INPUT_HANDLE, child_stdin_rd_)) {
    FATAL_ESCAPE("Redirecting Stdin failed");
  }
 
  // Duplicate the write handle to the pipe so it is not inherited. 
  f_success = DuplicateHandle(GetCurrentProcess(), child_stdin_wr_, 
                              GetCurrentProcess(), &child_stdin_wr_dup_, 0, 
                              FALSE,                  // not inherited 
                              DUPLICATE_SAME_ACCESS); 
  if (!f_success) {
    FATAL_ESCAPE("DuplicateHandle failed");
  }
  CloseHandle(child_stdin_wr_); 
  // Now create the child process. 
  if (!SpawnChildProcess(saved_name.c_str(), saved_args.c_str())) {
    FATAL_ESCAPE("Create process failed");
  }
 
  // After process creation, restore the saved STDIN and STDOUT. 
  if (!SetStdHandle(STD_INPUT_HANDLE, saved_stdin_)) {
    FATAL_ESCAPE("Re-redirecting Stdin failed");
  }
  if (!SetStdHandle(STD_OUTPUT_HANDLE, saved_stdout_)) {
    FATAL_ESCAPE("Re-redirecting Stdout failed");
  }
 
  // Read from pipe that is the standard output for child process.
  return ReadFromPipe();
} 
 
BOOL Process::SpawnChildProcess(const char* name, const char* args) { 
  PROCESS_INFORMATION process_info;
  STARTUPINFO startup_info;

  // Set up members of STARTUPINFO structure. 
 
  memset(&process_info, 0, sizeof(process_info));
  memset(&startup_info, 0, sizeof(startup_info));
  startup_info.cb = sizeof(STARTUPINFO); 
  startup_info.dwFlags =
      STARTF_USEFILLATTRIBUTE | 
      STARTF_USECOUNTCHARS | 
      STARTF_USESTDHANDLES |
      STARTF_USESHOWWINDOW;
  startup_info.hStdOutput = child_stdout_rd_dup_;
  // Create the child process.
  std::string args_string = name;
  args_string += " ";
  args_string += args;
  LPSTR arg_val = new char[args_string.size() + 1];
  strcpy(arg_val, args_string.c_str());
  BOOL ret = CreateProcess(name, arg_val,
                           NULL,          // process security attributes 
                           NULL,          // primary thread security attributes 
                           TRUE,          // handles are inherited 
                           0,             // creation flags 
                           NULL,          // use parent's environment 
                           NULL,          // use parent's current directory 
                           &startup_info,  // STARTUPINFO pointer 
                           &process_info);  // receives PROCESS_INFORMATION
  if (ret != FALSE) {
    WaitForInputIdle(process_info.hProcess, INFINITE);
    WaitForSingleObject(process_info.hProcess, INFINITE);
  } else {
    std::string buf;
    os::GetLastError(&buf);
    Logging::GetInstance()->Fatal("%s", buf.c_str());
  }
  delete []arg_val;
  return ret;
}
 
bool Process::ReadFromPipe() {
  DWORD read;
  CHAR buf[BUFSIZE]; 
  HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  // Close the write end of the pipe before reading from the 
  // read end of the pipe.
  if (!CloseHandle(child_stdout_wr_)) {
    FATAL_ESCAPE("Closing handle failed");
  }
  if (!CloseHandle(child_stdin_rd_)) {
    FATAL_ESCAPE("Closing handle failed");
  }
  // Read output from the child process, and write to parent's STDOUT. 
  for (;;) {
    if(!ReadFile(child_stdout_rd_dup_, buf, BUFSIZE, &read, NULL) || read == 0) {
      break;
    }
    result_ += buf;
  }
  return true;
}
}}
