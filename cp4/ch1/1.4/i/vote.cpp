#include <iostream>

int main() {
    int t;
    
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        int maxCandidate = 1, maxVotes;
        std::cin >> maxVotes;
        int votes;
        int totalVotes = maxVotes;

        for (int j = 2; j <= n; j++) {
            std::cin >> votes;

            if (votes == maxVotes) {
                maxCandidate = -1;
            } else if (votes > maxVotes) {
                maxCandidate = j;
                maxVotes = votes;
            }

            totalVotes += votes;
        }

        if (maxCandidate == -1) {
            std::cout << "no winner" << '\n';
        } else if (maxVotes > (totalVotes / 2)) {
            std::cout << "majority winner " << maxCandidate << '\n';
        } else {
            std::cout << "minority winner " << maxCandidate << '\n';
        }
    }

    return 0;
}