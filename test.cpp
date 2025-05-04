#include "sysinfo.hpp"
#include <iostream>

int32_t main() {
    SysInfo data;
    std::cout << "\033[95m\033[1m" << data.username() <<
    "\033[39m\033[1m@\033[95m" << data.hostname() << "\n\n";
    std::cout << "\033[95m\033[1mUptime: \033[0m" << data.uptime() << '\n';
    std::cout << "\033[95m\033[1mOs: \033[0m" << data.os() << '\n';
    std::cout << "\033[95m\033[1mKernel: \033[0m" << data.kernel() << '\n';
    std::cout << "\033[95m\033[1mDesktop: \033[0m" << data.desktop() << '\n';
    std::cout << "\033[95m\033[1mShell: \033[0m" << data.shell() << '\n';
    std::cout << "\033[95m\033[1mTerminal: \033[0m" << data.terminal() << '\n';
    std::cout << "\033[95m\033[1mCPU: \033[0m" << data.cpu() << '\n';
    std::cout << "\033[95m\033[1mMemory: \033[0m" << data.meminfo() << '\n';
    return 0;
}
