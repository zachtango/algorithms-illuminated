#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

int getValue(char c) {
    if (c >= '0' && c <= '9') {
        return static_cast<int>(c - '0');
    }

    if (c >= 'a' && c <= 'z') {
        return static_cast<int>(c - 'a' + 10);
    }

    if (c >= 'A' && c <= 'Z') {
        return static_cast<int>(c - 'A' + 10 + 26);
    }

    return -1;
}

char getChar(int v) {
    if (v >= 0 && v <= 9) {
        return static_cast<char>(v + '0');
    }

    if (v >= 10 && v < 36) {
        return static_cast<char>(v + 'a');
    }

    if (v >= 36 && v < 62) {
        return static_cast<char>(v + 'A');
    }

    return -1;
}

struct Position {
    int r = -1;
    int c = -1;

    Position() {}
    Position(int r, int c) : r(r), c(c) {}
};

void solve() {
    std::unordered_map<int, Position> positions;
    std::vector<std::vector<char>> grid;
    int maxValue = 0;
    int rows = 0;

    std::string line;

    if (!std::getline(std::cin, line)) {
        return;
    }

    do {
        std::vector<char> row;
        for(int c = 0; c < line.size(); c++) {
            row.push_back(line[c]);
            if (line[c] == '.') {
                continue;
            }
            int v = getValue(line[c]);
            positions[v] = Position(rows, c);
            maxValue = std::max(maxValue, v);
        }
        grid.push_back(row);
        rows += 1;
    } while (std::getline(std::cin, line) && line.size() != 0);

    int cols = grid[0].size();

    for (int v = 1; v <= maxValue; v++) {
        if (positions[v - 1].r == positions[v].r) {
            // horizontal
            int dc = ((positions[v].c - positions[v - 1].c) > 0) ? 1 : -1;

            int currRow = positions[v - 1].r;
            int currCol = positions[v - 1].c;
            while (currCol != positions[v].c) {
                if (grid[currRow][currCol] == '|') {
                    grid[currRow][currCol] = '+';
                } else if (grid[currRow][currCol] == '.') {
                    grid[currRow][currCol] = '-';
                }
                currCol += dc;
            }
        } else {
            // vertical
            int dr = ((positions[v].r - positions[v - 1].r) > 0) ? 1 : -1;

            int currRow = positions[v - 1].r;
            int currCol = positions[v - 1].c;
            while (currRow != positions[v].r) {
                if (grid[currRow][currCol] == '-') {
                    grid[currRow][currCol] = '+';
                } else if (grid[currRow][currCol] == '.') {
                    grid[currRow][currCol] = '|';
                }
                currRow += dr;
            }
        }
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            std::cout << grid[r][c];
        }
        std::cout << '\n';
    }

}

int main() {
    /*
        Store positions of all dots

        Start at position of 0 and traverse grid to max dot

        While traversing, if going horizontal and encounters |, replace with +
                            if going vertical and encounters -, replace with +
    */
    while(!std::cin.eof()) {
        solve();
        std::cout << '\n';
    }

    return 0;
}