#include <iostream>
#include <string>
#include <algorithm>

int swap1(std::string &s1, const std::string &s2) {
    int numSwaps = 0;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '?' || s1[i] == s2[i]) {
            continue;
        }

        for (int j = i + 1; j < s1.size(); j++) {
            if (s1[i] != s1[j] && s1[j] != '?' && s1[j] != s2[j]) {
                std::swap(s1[i], s1[j]);
                numSwaps += 1;
                break;
            }
        }
    }

    return numSwaps;
}

int swap2(std::string &s1, const std::string &s2) {
    int numSwaps = 0;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '0' || s1[i] == s2[i]) {
            continue;
        }

        for (int j = i + 1; j < s1.size(); j++) {
            if (s1[j] == '0' || s1[i] == s1[j] || s1[j] == s2[j]) {
                continue;
            }
            
            std::swap(s1[i], s1[j]);
            numSwaps += 1;
            break;
        }
    }

    return numSwaps;
}

int main() {
    /*
        1. Perform swapping of 1s and 0s
        2. Perform swapping of ?s and others
        3. Iterate through remaining string and count
            a. 0s or 1s not in their right place (it should only be counting one char type [all 0s or all 1s]), + 2 moves for these
            b. ? marks, + 1 moves for these
    */

    int n;
    std::cin >> n;

    std::string s1, s2;
    for (int i = 0; i < n; i++) {
        std::cin >> s1 >> s2;

        // Validate transition is possible
        int s1Zeros = 0;
        int s1Ones = 0;
        int s1Qs = 0;
        int s2Zeros = 0;
        int s2Ones = 0;

        for (auto c : s1) {
            switch (c) {
                case '0':
                    s1Zeros += 1;
                    break;
                case '1':
                    s1Ones += 1;
                    break;
                case '?':
                    s1Qs += 1;
            }
        }

        for (auto c : s2) {
            switch (c) {
                case '0':
                    s2Zeros += 1;
                    break;
                case '1':
                    s2Ones += 1;
                    break;
            }
        }

        if (s1Qs < (s2Zeros - s1Zeros)) {
            std::cout << "Case " << (i + 1) << ": " << -1 << '\n';
            continue;
        }

        // Swap 1s and 0s
        int moves = swap1(s1, s2);

        // Swap ?s and others
        moves += swap2(s1, s2);
        
        for (int j = 0; j < s1.size(); j++) {
            if (s1[j] == '?' || (s1[j] == '0' && s2[j] == '1')) {
                moves += 1;
            }
        }
        
        std::cout << "Case " << (i + 1) << ": " << moves << '\n';
    }

    return 0;

}