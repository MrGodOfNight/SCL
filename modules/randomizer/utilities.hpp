#include <ctime>
#ifdef _WIN32
#include <windows.h>
#include <tlhelp32.h>
#elif defined(__linux__)
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#elif defined(__APPLE__)
#include <mach/mach.h>
#include <libproc.h>
#include <iostream>
#include <unistd.h>
#endif

namespace SCL
{
  class Utilities
  {
    public:
      /**
       * method for measuring free RAM
       * @return size_t
      */
      size_t GetFreeMemory();

      #ifdef _WIN32
        /**
         * method to get the sum of IDs of running processes for Win
         * @return DWORD
        */
        DWORD GetProcessIDSum();

        /**
         * method for obtaining the number of running processes
         * @return DWORD
        */
        DWORD GetProcessSum();

        /**
         * retrieve the current process ID
         * @return DWORD
        */
        DWORD processId = GetCurrentProcessId();
      #elif
        /**
         * method to get the sum of IDs of running processes for Linux/MacOS
         * @return pid_t
        */
        pid_t GetProcessIDSum();
        
        /**
         * method for obtaining the number of running processes
         * @return pid_t
        */
        pid_t GetProcessSum();

        /**
         * retrieve the current process ID
         * @return pid_t
        */
        pid_t processId = getpid();
      #endif

      long long entropy = time(0) + GetFreeMemory() + (GetProcessIDSum() % GetProcessSum()) + processId;
  };
}