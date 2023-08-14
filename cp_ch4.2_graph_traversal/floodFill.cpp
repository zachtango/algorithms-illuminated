#include <vector>
using std::vector;
#include <utility>
using std::pair;

vector<pair<int, int>> d {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    // Diagnol fills if allowed
    {1, 1},
    {1, -1},
    {-1, -1},
    {-1, 1}
};

constexpr const int R = 10, C = 10;
char grid[R][C];

// Flood fill usually done on 2D grid graphs
// Returns size of CC
int floodFill(int r, int c, char c1, char c2) {
    if ((r < 0) || (r >= R) || 
        (c < 0) || (c >= C) ||
        grid[r][c] != c1) {
        return 0;
    }

    int ans = 1;
    grid[r][c] = c2;
    for (const auto &[dx, dy] : d) {
        ans += floodFill(r + dx, c + dy, c1, c2);
    }

    return ans;
}


