#include <vector>
#include <cstring>

using namespace std;

/*
    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

        Each row must contain the digits 1-9 without repetition.
        Each column must contain the digits 1-9 without repetition.
        Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

    Note:

        A Sudoku board (partially filled) could be valid but is not necessarily solvable.
        Only the filled cells need to be validated according to the mentioned rules.
*/

class Solution {

static const int NUM_DIGITS = 9;
    
int count[NUM_DIGITS];

void resetCount() {
    for (int i = 0; i < NUM_DIGITS; i++) {
        count[i] = 0;
    }
}

bool validCount() {
    for (int i = 0; i < NUM_DIGITS; i++) {
        if (count[i] > 1) {
            return false;
        }
    }
    return true;
}

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        char ch;

        // Rows
        for (int r = 0; r < n; r++) {
            resetCount();
            for (int c = 0; c < n; c++) {
                ch = board[r][c];
                if (isdigit(ch)) {
                    count[ch - '1'] += 1;
                }
            }
            if (!validCount()) {
                return false;
            }
        }

        // Columns
        for (int c = 0; c < n; c++) {
            resetCount();
            for (int r = 0; r < n; r++) {
                ch = board[r][c];
                if (isdigit(ch)) {
                    count[ch - '1'] += 1;
                }
            }
            if (!validCount()) {
                return false;
            }
        }

        // Boxes
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) { // box top left coords
                resetCount();
                // process box
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        ch = board[r + i][c + j];
                        if (isdigit(ch)) {
                            count[ch - '1'] += 1;
                        }
                    }
                }
                if (!validCount()) {
                    return false;
                }
            }
        }

        return true;
    }
};

