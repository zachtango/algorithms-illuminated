#include <iostream>
#include <string>


int main() {

    // 1. Inputting strings
    std::string T;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.substr(0, 7) == ".......") {
            break;
        }

        T += line + ' ';
    }

    if (T.size()) {
        T.pop_back();
    }

    std::string P {"book"};
    // 2. Finding substrings
    auto found = T.find(P);
    if (found == std::string::npos) {
        std::cout << -1 << '\n';
    } else {
        while (found != std::string::npos) {
            std::cout << found << ' ';
            found = T.find(P, found + P.size());
        }
        std::cout << '\n';
    }

    // 3. 
    
    return 0;
}