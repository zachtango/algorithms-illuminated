#include <iostream>
#include <vector>

struct Order {
    int x, y;
    Order() {}
    Order(int x, int y) : x(x), y(y) {}
};

bool hit(std::vector<std::vector<char>> &grid, int x, int y) {
    char &c = grid[grid.size() - y - 1][x];

    if (c == '#') {
        c = '_';
        return true;
    }

    return false;
}

void solve() {
    int w, h, n;
    std::cin >> w >> h >> n;

    std::vector<std::vector<char>> p1, p2;
    int p1Ships = 0;
    int p2Ships = 0;

    for (int i = 0; i < h; i++) {
        std::vector<char> row(w);
        for (int j = 0; j < w; j++) {
            std::cin >> row[j];
            if (row[j] == '#') {
                p1Ships += 1;
            }
        }
        p1.push_back(row);
    }
    for (int i = 0; i < h; i++) {
        std::vector<char> row(w);
        for (int j = 0; j < w; j++) {
            std::cin >> row[j];
            if (row[j] == '#') {
                p2Ships += 1;
            }
        }
        p2.push_back(row);
    }

    std::vector<Order> orders(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        orders[i] = Order(x, y);
    }
    
    bool playerOneTurn = true;
    int i = 0;
    while (i < n) {
        if (playerOneTurn) {
            while (hit(p2, orders[i].x, orders[i].y)) {
                p2Ships -= 1;
                if (p2Ships == 0) {
                    break;
                }                
                i += 1;
            }
            i += 1;
            playerOneTurn = false;
        } else {
            while (hit(p1, orders[i].x, orders[i].y)) {
                p1Ships -= 1;
                i += 1;
            }

            if (p1Ships == 0 || p2Ships == 0) {
                break;
            }
            
            i += 1;
            playerOneTurn = true;
        }
    }
    
    if ((p1Ships && p2Ships) || (!p1Ships && !p2Ships)) {
        std::cout << "draw" << '\n';
    } else if (p1Ships) {
        std::cout << "player one wins" << '\n';
    } else {
        std::cout << "player two wins" << '\n';
    }

}

int main() {
    int t;

    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}