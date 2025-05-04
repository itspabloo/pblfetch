#include <fstream>
#include <cstdint>
#include <unistd.h>
#include "consts.hpp"

std::string GetUsername();
std::string GetHostname();
std::string GetUptime();
std::string GetOsName();
std::string GetKernelVersion();
std::string GetShell();
std::string GetTerminal();
std::string GetDesktop();
std::string GetCPU();
std::string GetMemory();


class SysInfo {
public:

    SysInfo() : username_(GetUsername()), hostname_(GetHostname()),
                uptime_(GetUptime()), os_(GetOsName()),
                kernel_(GetKernelVersion()), shell_(GetShell()),
                terminal_(GetTerminal()), desktop_(GetDesktop()),
                cpu_(GetCPU()), meminfo_(GetMemory()) {}
    
    std::string username() {
        return username_;
    }

    std::string hostname() {
        return hostname_;
    }

    std::string uptime() {
        return uptime_;
    }

    std::string os() {
        return os_;
    }

    std::string kernel() {
        return kernel_;
    }

    std::string shell() {
        return shell_;
    }

    std::string terminal() {
        return terminal_;
    }

    std::string desktop() {
        return desktop_;
    }

    std::string cpu() {
        return cpu_;
    }

    std::string meminfo() {
        return meminfo_;
    }
    
private:
    std::string username_;
    std::string hostname_;
    std::string uptime_;
    std::string os_;
    std::string kernel_;
    std::string shell_;
    std::string terminal_;
    std::string desktop_;
    std::string cpu_;
    std::string meminfo_; 
};

std::string GetUsername() {
    const char* USERNAME = std::getenv("USER");
    if (!USERNAME) return UNKNOWN;
    return std::string(USERNAME);
}

std::string GetHostname() {
    char HOSTNAME[256];
    if (!gethostname(HOSTNAME, sizeof(HOSTNAME))) {
        return std::string(HOSTNAME);
    } else {
        return UNKNOWN;
    }
}

std::string GetUptime() {
    std::ifstream readFile("/proc/uptime");
    long double inp;
    if (readFile.is_open()) {
        readFile >> inp;
        int64_t seconds = static_cast<int64_t>(inp);
        int64_t minutes = seconds / 60;
        seconds %= 60;
        int64_t hours = minutes / 60;
        minutes /= 60;
        int64_t days = hours / 24;
        hours %= 24;
        std::string result = "";
        if (days) result += std::to_string(days) + " days ";
        if (!result.empty() || hours) result += std::to_string(hours) + " hours ";
        if (!result.empty() || minutes) result += std::to_string(minutes) + " minutes";
        if (result.empty()) result += std::to_string(seconds) + " seconds";
        return result;
    } else {
        return UNKNOWN;
    }
}

std::string GetOsName() {
    std::ifstream readFile("/etc/os-release");
    if (readFile.is_open()) {
        std::string helper;
        std::string result;
        while (std::getline(readFile, helper)) {
            if (helper.find("PRETTY_NAME")) {
                 size_t start = helper.find('"') + 1;
                 size_t end = helper.find('"', start);
                 result += helper.substr(start, end - start);
                 break;
            }
        }
        if (!result.empty()) {
            return result;
        } else {
            return UNKNOWN;
        }
    } else {
        return UNKNOWN;
    }
}

std::string GetKernelVersion() {
    std::ifstream readFile("/proc/version");
    if (readFile.is_open()) {
        std::string helper;
        readFile >> helper; // skipping "Linux"
        readFile >> helper; // skipping "version"
        readFile >> helper; // result
        return helper;
    } else {
        return UNKNOWN;
    }
}

std::string GetShell() {
    const char* SHELL = std::getenv("SHELL");
    if (SHELL) {
        std::string fullPath(SHELL);
        size_t lastDir = fullPath.find_last_of('/');
        if (lastDir != std::string::npos) {
            return fullPath.substr(lastDir + 1);
        } else {
            return fullPath;
        }
    } else {
        return UNKNOWN;
    }
}

std::string GetTerminal() {
    const char* TERMINAL = std::getenv("TERM");
    if (TERMINAL) {
        std::string fullName(TERMINAL);
        if (fullName.find("xterm-") != std::string::npos) {
            return fullName.substr(6);
        } else {
            return fullName;
        }
    } else {
        return UNKNOWN;
    }
}

std::string GetDesktop() {
    const char* DESKTOP = std::getenv("XDG_CURRENT_DESKTOP");
    if (DESKTOP) {
        return std::string(DESKTOP);
    } else {
        return UNKNOWN;
    }
}

std::string GetCPU() {
    std::ifstream readFile("/proc/cpuinfo");
    if (readFile.is_open()) {
        std::string helper;
        std::string result;
        while (std::getline(readFile, helper)) {
            if (helper.find("model name") != std::string::npos) {
                size_t start = helper.find(':');
                if (start != std::string::npos) {
                    result = helper.substr(start + 2);
                    break;
                }
            }
        }
        if (!result.empty()) {
            return result;
        } else {
            return UNKNOWN;
        }
    } else {
        return UNKNOWN;
    }
}

std::string GetMemory() {
    std::ifstream readFile("/proc/meminfo");
    if (readFile.is_open()) {
        std::string helper;
        std::string result;
        int64_t total = -1;
        int64_t available = -1;
        while (std::getline(readFile, helper)) {
            if (helper.find("MemTotal") != std::string::npos) {
                std::sscanf(helper.c_str(), "MemTotal: %ld kB", &total);
            } else if (helper.find("MemAvailable") != std::string::npos) {
                std::sscanf(helper.c_str(), "MemAvailable: %ld kB", &available);
            }
        }
        if (total == -1 || available == -1) {
            return UNKNOWN;
        }
        int64_t used = total - available;
        result = std::to_string(used / 1024 / 1024) + "," +
                 std::to_string(static_cast<int64_t>(
                 static_cast<double>(used) / 1024 / 10.24) % 100) +
                 " GiB / " + std::to_string(total / 1024 / 1024) + "," +
                 std::to_string(static_cast<int64_t>(
                 static_cast<double>(total) / 1024 / 10.24) % 100) + " GiB";
        return result;
    } else {
        return UNKNOWN;
    }
}
