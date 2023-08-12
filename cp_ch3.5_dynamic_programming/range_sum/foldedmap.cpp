#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
using std::min;

/*
    Can get the number of X's in a rectangular region in O(1) time

    Given the tile size Tr by Tc, try all possible tile placements O(Tr * Tc)
        Trying a possible tile placement is bound by O(Ar / Tr * Ac / Tc)

    Therefore, the total running time is O(Ar * Ac)


*/

constexpr const int MAX_L = 1000;
int P[MAX_L][MAX_L];

void solve(int Ar, int Ac, int Tr, int Tc) {
    int minTiles = 1e9;
    for (int i = 0; i < Tr; i++) {
        for (int j = 0; j < Tc; j++) { // bottom right coord of top right starting tile
            int numTiles = 0;

            for (int x = i; x < Ar + Tr - 1; x += Tr) {
                for (int y = j; y < Ac + Tc - 1; y += Tc) {
                    int count = P[min(x, Ar - 1)][min(y, Ac - 1)];

                    if (x - Tr >= 0) {
                        count -= P[x - Tr][min(y, Ac - 1)];
                    }
                    if (y - Tc >= 0) {
                        count -= P[min(x, Ar - 1)][y - Tc];
                    }
                    if (x - Tr >= 0 && y - Tc >= 0) {
                        count += P[x - Tr][y - Tc];
                    }

                    if (count > 0) {
                        numTiles += 1;
                    }
                }
            }
            minTiles = min(numTiles, minTiles);
        }
    }

    cout << minTiles << '\n';
}


int main() {

    int Ar, Ac, Tr, Tc;

    while(cin >> Ar) {
        cin >> Ac >> Tr >> Tc;
        char c;
        
        for (int i = 0; i < Ar; i++) {
            for (int j = 0; j < Ac; j++) {
                cin >> c;
                if (c == 'X') {
                    P[i][j] = 1;
                } else {
                    P[i][j] = 0;
                }

                if (i > 0) {
                    P[i][j] += P[i - 1][j];
                }

                if (j > 0) {
                    P[i][j] += P[i][j - 1];
                }

                if (i > 0 && j > 0) {
                    P[i][j] -= P[i - 1][j - 1];
                }
            }
        }

        solve(Ar, Ac, Tr, Tc);
    }

    return 0;
}