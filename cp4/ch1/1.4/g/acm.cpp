#include <iostream>
#include <string>

constexpr const int NUM_PROBLEMS {26};
constexpr const int TIME_PENALTY {20};

int main() {
    
    int numSolved = 0;
    int totalTimePenalty = 0;
    int numAttempts[NUM_PROBLEMS];

    for (int i = 0; i < NUM_PROBLEMS; i++) {
        numAttempts[i] = 0;
    }

    int time;
    char problem;
    std::string s;

    while (std::cin >> time, time != -1) {
        std::cin >> problem >> s;

        if (s == "right") {
            totalTimePenalty += time + numAttempts[problem - 'A'] * TIME_PENALTY;
            numSolved += 1;
        } else {
            numAttempts[problem - 'A'] += 1;
        }
    }

    std::cout << numSolved << ' ' << totalTimePenalty << '\n';

    return 0;
}