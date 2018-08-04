#include <iostream>

char edcode(uint8_t wd) {
    uint8_t first = (wd >> 7), last = wd & 1;
    wd = (wd << 1);
    wd = wd >> 2;
    wd = wd << 1;
    wd = (last << 7) | wd;
    wd = wd | first;
    return wd;
}

int main(int argc, char const *argv[]) {
    std::string line;
    uint8_t word;
    bool started = false;
    while (std::getline(std::cin, line)) {
        if (started) std::cout << '\n';
        else started = true;

        for (int i = 0; i < line.size(); i++) {
            word = edcode(line[i]);
            std::cout << word;
        }
    }
    return 0;
}
