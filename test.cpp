#include "sysinfo.hpp"
#include <iostream>

int32_t main() {
    SysInfo data;
    std::cout << data.username() << "@" << data.hostname() << "\n\n";
    std::cout << "Uptime: " << data.uptime() << '\n';
    std::cout << "Os: " << data.os() << '\n';
    std::cout << "Kernel: " << data.kernel() << '\n';
    std::cout << "Desktop: " << data.desktop() << '\n';
    std::cout << "Shell: " << data.shell() << '\n';
    std::cout << "Terminal: " << data.terminal() << '\n';
    std::cout << "CPU: " << data.cpu() << '\n';
    std::cout << "Memory: " << data.meminfo() << '\n';
    return 0;
}
