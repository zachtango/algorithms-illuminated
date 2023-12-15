#include <iostream>

constexpr const int GRID_LENGTH {8};

int changeDir(int d, char c) {
    if (c == 'R') {
        d += 1;
    } else {
        d -= 1;
    }
    if (d == -1) {
        d = 3;
    } else if (d == 4) {
        d = 0;
    }
    return d;
}

bool moveForward(char grid[GRID_LENGTH][GRID_LENGTH], int &r, int &c, int d) {
    switch (d) {
        case 0:
            c += 1;
            break;
        case 1:
            r -= 1;
            break;
        case 2:
            c -= 1;
            break;
        case 3:
            r += 1;
            break;
    }

    if (r < 0 || r >= GRID_LENGTH || c < 0 || c >= GRID_LENGTH || grid[r][c] == 'C' || grid[r][c] == 'I') {
        return false;
    }

    return true;
}

bool fireLaser(char grid[GRID_LENGTH][GRID_LENGTH], int r, int c, int d) {
    switch (d) {
        case 0:
            c += 1;
            break;
        case 1:
            r -= 1;
            break;
        case 2:
            c -= 1;
            break;
        case 3:
            r += 1;
            break;
    }

    if (r < 0 || r >= GRID_LENGTH || c < 0 || c >= GRID_LENGTH || grid[r][c] != 'I') {
        return false;
    }

    grid[r][c] = '.';

    return true;
}

int main() {
    
    char grid[GRID_LENGTH][GRID_LENGTH];

    int endR, endC;

    for (int i = 0; i < GRID_LENGTH; i++) {
        for (int j = 0; j < GRID_LENGTH; j++) {
            std::cin >> grid[GRID_LENGTH - i - 1][j];
            if (grid[GRID_LENGTH - i - 1][j] == 'D') {
                endR = GRID_LENGTH - i - 1;
                endC = j;
            }
        }
    }

    std::string moves;
    std::cin >> moves;

    int r = 0, c = 0, d = 0;

    for (auto move : moves) {
        switch (move) {
            case 'F':
                if (!moveForward(grid, r, c, d)) {
                    std::cout << "Bug!" << '\n';
                    return 0;
                }
                break;
            case 'R':
                d = changeDir(d, 'R');
                break;
            case 'L':
                d = changeDir(d, 'L');
                break;
            case 'X':
                if (!fireLaser(grid, r, c, d)) {
                    std::cout << "Bug!" << '\n';
                    return 0;
                }
                break;
        }
    }

    std::cout << (grid[r][c] == 'D' ? "Diamond!" : "Bug!") << '\n';

    return 0;
}
