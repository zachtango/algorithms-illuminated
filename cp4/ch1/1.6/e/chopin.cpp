#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>



int main() {
    std::vector<std::pair<std::string, std::string>> names {
        {"A#", "Bb"}, {"C#", "Db"}, {"D#", "Eb"}, {"F#", "Gb"}, {"G#", "Ab"}
    };

    std::unordered_map<std::string, std::string> alternateNames;

    for (auto p : names) {
        alternateNames[p.first] = p.second;
        alternateNames[p.second] = p.first;
    }

    int i = 1;
    std::string a, b;
    while (std::cin >> a >> b) {
        std::cout << "Case " << i << ": ";
        if (alternateNames.count(a)) {
            std::cout << alternateNames[a] << ' ' << b;
        } else {
            std::cout << "UNIQUE";
        }
        std::cout << '\n';
        i += 1;
    }

    return 0;
}
