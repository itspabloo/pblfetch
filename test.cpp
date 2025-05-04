#include "sysinfo.hpp"
#include <iostream>

int32_t main() {
    SysInfo data;
    std::cout << MAIN_COLOR << BOLD << data.username() << DEFAULT << BOLD <<
    "@" << MAIN_COLOR << data.hostname() << "\n\n";
    std::cout << "Uptime: " << DEFAULT << data.uptime() << '\n';
    std::cout << MAIN_COLOR << BOLD << "Os: " << DEFAULT << data.os() << '\n';
    std::cout << MAIN_COLOR << BOLD << "Kernel: " << DEFAULT << data.kernel() << '\n';
    std::cout << MAIN_COLOR << BOLD << "Desktop: " << DEFAULT << data.desktop() << '\n';
    std::cout << MAIN_COLOR << BOLD << "Shell: " << DEFAULT << data.shell() << '\n';
    std::cout << MAIN_COLOR << BOLD << "Terminal: " << DEFAULT << data.terminal() << '\n';
    std::cout << MAIN_COLOR << BOLD << "CPU: " << DEFAULT << data.cpu() << '\n';
    std::cout << MAIN_COLOR << BOLD << "Memory: " << DEFAULT << data.meminfo() << '\n';
    return 0;
}
