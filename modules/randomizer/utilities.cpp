#include "utilities.hpp"

namespace SCL
{
  size_t Utilities::GetFreeMemory()
  {
    size_t freeMemory = 0;

    #ifdef _WIN32
      MEMORYSTATUSEX status;
      status.dwLength = sizeof(status);
      GlobalMemoryStatusEx(&status);
      freeMemory = status.ullAvailPhys;
    #elif defined(__linux__)
      long pages = sysconf(_SC_AVPHYS_PAGES);
      long pageSize = sysconf(_SC_PAGESIZE);
      freeMemory = pages * pageSize;
    #elif defined(__APPLE__)
      struct mach_task_basic_info info;
      mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;
      if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO, reinterpret_cast<task_info_t>(&info), &infoCount) == KERN_SUCCESS)
      {
        freeMemory = info.resident_size;
      }
    #endif

    return freeMemory;
  }

  #ifdef _WIN32
    DWORD Utilities::GetProcessIDSum()
    {
      DWORD idSum = 0;

      HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
      if (snapshot != INVALID_HANDLE_VALUE)
      {
        PROCESSENTRY32 processEntry;
        processEntry.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(snapshot, &processEntry))
        {
          do
            {
              idSum += processEntry.th32ProcessID;
            } while (Process32Next(snapshot, &processEntry));
        }

        CloseHandle(snapshot);
      }

      return idSum;
    }

    DWORD Utilities::GetProcessSum()
    {
      DWORD Sum = 0;

      HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
      if (snapshot != INVALID_HANDLE_VALUE)
      {
        PROCESSENTRY32 processEntry;
        processEntry.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(snapshot, &processEntry))
        {
          do
            {
              Sum ++;
            } while (Process32Next(snapshot, &processEntry));
        }

        CloseHandle(snapshot);
      }

      return Sum;
    }
  #elif __linux__
    pid_t Utilities::GetProcessIDSum()
    {
      pid_t idSum = 0;

      DIR* dir = opendir("/proc");
      if (dir != nullptr)
      {
        struct dirent* entry;

        while ((entry = readdir(dir)) != nullptr)
        {
          pid_t pid = atoi(entry->d_name);
          if (pid > 0)
          {
            idSum += pid;
          }
        }

        closedir(dir);
      } 

      return idSum;
    }

    pid_t Utilities::GetProcessSum()
    {
      pid_t Sum = 0;

      DIR* dir = opendir("/proc");
      if (dir != nullptr)
      {
        struct dirent* entry;

        while ((entry = readdir(dir)) != nullptr)
        {
          pid_t pid = atoi(entry->d_name);
          if (pid > 0)
          {
            Sum ++;
          }
        }

        closedir(dir);
      } 

      return Sum;
    }
  #elif __APPLE__
    pid_t Utilities::GetProcessSum()
    {
      pid_t idSum = 0;
      proc_bsdinfo info;
      int count = proc_listpids(PROC_ALL_PIDS, 0, nullptr, 0);
      pid_t pids[count];

      count = proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
      for (int i = 0; i < count; ++i)
      {
        if (proc_pidinfo(pids[i], PROC_PIDTBSDINFO, 0, &info, sizeof(info)) == sizeof(info))
        {
          idSum += pids[i];
        }
      } 

      return idSum;
    }

    pid_t Utilities::GetProcessIDSum()
    {
      pid_t Sum = 0;
      proc_bsdinfo info;
      int count = proc_listpids(PROC_ALL_PIDS, 0, nullptr, 0);
      pid_t pids[count];

      count = proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
      for (int i = 0; i < count; ++i)
      {
        if (proc_pidinfo(pids[i], PROC_PIDTBSDINFO, 0, &info, sizeof(info)) == sizeof(info))
        {
          Sum ++;
        }
      } 

      return Sum;
    }
  #endif
}