#include <csetjmp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Art {
public:
    Art() {
        maxLen_ = 0;
        nextIndex_ = 0;
        const char* HOME = std::getenv("HOME");
        const std::string homedir(HOME);
        std::ifstream readFile(homedir + "/.config/pblfetch/art.txt");
        std::string helper;
        while (std::getline(readFile, helper)) {
            while (!helper.empty() && helper.back() == ' ') helper.pop_back();
            maxLen_ = std::max(maxLen_, static_cast<int32_t>(helper.size()) + 1);
            art_.push_back(helper);
        }
        for (auto &x : art_) {
            if (static_cast<int32_t>(x.size()) < maxLen_) {
                x += std::string(maxLen_ - static_cast<int32_t>(x.size()), ' ');
            }
        }
    }

    void PrintLine() {
        std::cout << ' ';
        if (NeedMore()) {
            std::cout << art_[nextIndex_];
            nextIndex_++;
        }
        return;
    }

    bool NeedMore() {
        return nextIndex_ < static_cast<int32_t>(art_.size());
    }
    
private:
      int32_t maxLen_, nextIndex_;
      std::vector<std::string> art_;
};
