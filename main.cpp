#include "sysinfo.hpp"
#include "art_drawer.hpp"
#include <iostream>

int32_t main() {
    SysInfo data;
    Art art;
    std::cout << "\n";
    art.PrintLine();
    std::cout << MAIN_COLOR << BOLD << data.username() << DEFAULT << BOLD <<
    "@" << MAIN_COLOR << data.hostname() << DEFAULT << '\n';
    art.PrintLine();
    std::cout << '\n';
    art.PrintLine();
    std::cout << MAIN_COLOR << BOLD << "Uptime: " << DEFAULT << data.uptime() << '\n';
    art.PrintLine();
    std::cout << MAIN_COLOR << BOLD << "Os: " << DEFAULT << data.os() << '\n';
    art.PrintLine();
    std::cout << MAIN_COLOR << BOLD << "Kernel: " << DEFAULT << data.kernel() << '\n';
    art.PrintLine();
    std::cout << MAIN_COLOR << BOLD << "Desktop: " << DEFAULT << data.desktop() << '\n';
    art.PrintLine();
    std::cout << MAIN_COLOR << BOLD << "Shell: " << DEFAULT << data.shell() << '\n';
    art.PrintLine();
    std::cout << MAIN_COLOR << BOLD << "Terminal: " << DEFAULT << data.terminal() << '\n';
    art.PrintLine();
    std::cout << MAIN_COLOR << BOLD << "CPU: " << DEFAULT << data.cpu() << '\n';
    art.PrintLine();
    std::cout << MAIN_COLOR << BOLD << "Memory: " << DEFAULT << data.meminfo() << '\n';
    while (art.NeedMore()) {
        art.PrintLine();
        std::cout << '\n';
    }
    return 0;
}
