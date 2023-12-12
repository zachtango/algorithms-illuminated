#include <iostream>
#include <vector>

int main() {
    int t;

    std::cin >> t;

    while (t--) {
        int n, m;

        std::cin >> n >> m;

        int k;

        std::vector<std::vector<int>> prizeTickets;
        std::vector<int> prizeCash(n);
        for (int i = 0; i < n; i++) {
            std::cin >> k;

            std::vector<int> tickets(k);
            for (int j = 0; j < k; j++) {
                std::cin >> tickets[j];
            }

            prizeTickets.push_back(tickets);

            std::cin >> prizeCash[i];
        }

        std::vector<int> totalTickets(m);

        for (int i = 0; i < m; i++) {
            std::cin >> totalTickets[i];
        }
        
        int totalCash = 0;
        // get min num tickets you have for each prize
        for (int i = 0; i < n; i++) {
            int minTickets = totalTickets[prizeTickets[i][0] - 1];

            for (int j = 1; j < prizeTickets[i].size(); j++) {
                minTickets = std::min(totalTickets[prizeTickets[i][j] - 1], minTickets);
            }
            
            totalCash += minTickets * prizeCash[i];
        }

        std::cout << totalCash << '\n';
    }

    return 0;
}