#include <iostream>

constexpr const int GRID_LENGTH {3};

bool win(char grid[GRID_LENGTH][GRID_LENGTH], char c) {
    // rows and cols
    for (int i = 0; i < GRID_LENGTH; i++) {
        bool row = true;
        bool col = true;
        for (int j = 0; j < GRID_LENGTH; j++) {
            // row
            if (grid[i][j] != c) {
                row = false;
            }

            // col
            if (grid[j][i] != c) {
                col = false;
            }
        }
        if (row || col) {
            return true;
        }
    }

    // diags
    bool leftDiag = true;
    bool rightDiag = true;
    for (int i = 0; i < GRID_LENGTH; i++) {
        if (grid[i][i] != c) {
            leftDiag = false;
        }
        if (grid[GRID_LENGTH - i - 1][i] != c) {
            rightDiag = false;
        }
        
    }

    return leftDiag || rightDiag;
}

int main() {
    /*
        Game is valid if Xs == Os or Xs == Os + 1
        Can only have one winner, (can't be 3 in a row from both X and O)
        2 Diags are possible if the diags share
        2 Diags where diags don't share squares, impossible but don't need to check for bc these cases have uneven number of Xs and Os
    */

    int n;
    std::cin >> n;
    
    char grid[GRID_LENGTH][GRID_LENGTH];

    while (n--) {
        std::string row;
        std::getline(std::cin, row);
        for (int i = 0; i < GRID_LENGTH; i++) {
            std::getline(std::cin, row);
            for (int j = 0; j < GRID_LENGTH; j++) {
                grid[i][j] = row[j];
            }
        }

        int numXs = 0;
        int numOs = 0;
        for (int i = 0; i < GRID_LENGTH; i++) {
            for (int j = 0; j < GRID_LENGTH; j++) {
                if (grid[i][j] == 'X') {
                    numXs += 1;
                } else if (grid[i][j] == 'O') {
                    numOs += 1;
                }
            }
        }

        if (!(numXs == numOs || numXs == numOs + 1)) {
            std::cout << "no" << '\n';
            continue;
        }

        bool xWin = win(grid, 'X');
        bool oWin = win(grid, 'O');
        if (xWin && oWin) {
            std::cout << "no" << '\n';
            continue;
        }

        if (xWin && numXs == numOs) {
            std::cout << "no" << '\n';
            continue;
        }

        if (oWin && (numXs == numOs + 1)) {
            std::cout << "no" << '\n';
            continue;
        }

        std::cout << "yes" << '\n';

    }

    return 0;
}