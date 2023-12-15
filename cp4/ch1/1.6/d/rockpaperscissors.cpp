#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Record {
    int wins = 0;
    int losses = 0;

    Record() {}
};

int move(const std::string &m1, const std::string &m2) {
    if (m1 == m2) {
        return 0;
    }

    if ((m1 == "rock" && m2 == "scissors") ||
        (m1 == "scissors" && m2 == "paper") ||
        (m1 == "paper" && m2 == "rock")) {
        return 1;
    }

    return 2;
}

void solve(int n, int k) {
    int numGames = (k * n * (n - 1)) / 2;

    std::vector<Record> players(n);
    for (int i = 0; i < numGames; i++) {
        int p1, p2;
        std::string m1, m2;

        std::cin >> p1 >> m1 >> p2 >> m2;
        
        int winner = move(m1, m2);

        switch (winner) {
            case 1:
                players[p1 - 1].wins += 1;
                players[p2 - 1].losses += 1;
                break;
            case 2:
                players[p2 - 1].wins += 1;
                players[p1 - 1].losses += 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (players[i].wins == 0 && players[i].losses == 0) {
            std::cout << '-' << '\n';
        } else {
            std::cout << std::fixed << std::setprecision(3) << (static_cast<double>(players[i].wins) / (static_cast<double>(players[i].wins) + players[i].losses)) << '\n';
        }
    }

    std::cout << '\n';
}

int main() {

    int n, k;
    
    while (std::cin >> n, n) {
        std::cin >> k;
        solve(n, k);
    }

    return 0;
}