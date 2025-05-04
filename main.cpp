#include "sysinfo.hpp"
#include <iostream>

void PrintArt(std::ifstream &in) {
    std::cout << " ";
    std::string line;
    std::getline(in, line);
    std::cout << line;
    return;
}

int32_t main() {
    SysInfo data;
    const char* HOME = std::getenv("HOME");
    const std::string homedir(HOME);
    std::ifstream readFile(homedir + "/.config/pblfetch/art.txt");
    std::cout << "\n";
    PrintArt(readFile);
    std::cout << MAIN_COLOR << BOLD << data.username() << DEFAULT << BOLD <<
    "@" << MAIN_COLOR << data.hostname() << DEFAULT << '\n';
    PrintArt(readFile);
    std::cout << '\n';
    PrintArt(readFile);
    std::cout << MAIN_COLOR << BOLD << "Uptime: " << DEFAULT << data.uptime() << '\n';
    PrintArt(readFile);
    std::cout << MAIN_COLOR << BOLD << "Os: " << DEFAULT << data.os() << '\n';
    PrintArt(readFile);
    std::cout << MAIN_COLOR << BOLD << "Kernel: " << DEFAULT << data.kernel() << '\n';
    PrintArt(readFile);
    std::cout << MAIN_COLOR << BOLD << "Desktop: " << DEFAULT << data.desktop() << '\n';
    PrintArt(readFile);
    std::cout << MAIN_COLOR << BOLD << "Shell: " << DEFAULT << data.shell() << '\n';
    PrintArt(readFile);
    std::cout << MAIN_COLOR << BOLD << "Terminal: " << DEFAULT << data.terminal() << '\n';
    std::cout << " ";
    std::cout << MAIN_COLOR << BOLD << "CPU: " << DEFAULT << data.cpu() << '\n';
    std::cout << " ";
    std::cout << MAIN_COLOR << BOLD << "Memory: " << DEFAULT << data.meminfo() << '\n';
    return 0;
}
