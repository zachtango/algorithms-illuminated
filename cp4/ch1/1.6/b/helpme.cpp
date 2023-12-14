#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <algorithm>

constexpr const int BOARD_LENGTH {8};

struct Position {
    char piece;
    int row = -1;
    int col = -1;

    Position(char piece, int row, int col) : piece(piece), row(row), col(col) {}
};

void printPiece(const Position &p) {
    if (p.piece != 'P') {
        std::cout << p.piece;
    }
    std::cout << static_cast<char>(p.col + 'a') << p.row + 1;
}

int main() {

    std::string line;

    std::unordered_map<char, std::vector<Position>> piecePositions;

    for (int i = 0; i < BOARD_LENGTH; i++) {
        std::getline(std::cin, line);
        std::getline(std::cin, line);
        
        for (int j = 0; j < BOARD_LENGTH; j++) {
            char c = line[j * 4 + 2];
            if (c == '.' || c == ':') {
                continue;
            }
            piecePositions[c].push_back(Position(std::toupper(c), 7 - i, j));
        }
    }

    std::vector<char> pieces {'k', 'q', 'r', 'b', 'n', 'p'};

    std::cout << "White: ";
    std::vector<Position> whitePieces;
    for (auto p : pieces) {
        p = std::toupper(p);

        if (!piecePositions.count(p)) {
            continue;
        }

        std::sort(piecePositions[p].begin(), piecePositions[p].end(), [](const Position &p1, const Position &p2) {
            if (p1.row == p2.row) {
                return p1.col < p2.col;
            }
            return p1.row < p2.row;
        });

        for (const auto &position : piecePositions[p]) {
            whitePieces.push_back(position);
        }
    }
    if (whitePieces.size()) {
        printPiece(whitePieces[0]);
    }
    for (int i = 1; i < whitePieces.size(); i++) {
        std::cout << ',';
        printPiece(whitePieces[i]);
    }
    std::cout << '\n';

    std::cout << "Black: ";
    std::vector<Position> blackPieces;
    for (auto p : pieces) {
        if (!piecePositions.count(p)) {
            continue;
        }

        std::sort(piecePositions[p].begin(), piecePositions[p].end(), [](const Position &p1, const Position &p2) {
            if (p1.row == p2.row) {
                return p1.col < p2.col;
            }
            return p1.row > p2.row;
        });

        for (const auto &position : piecePositions[p]) {
            blackPieces.push_back(position);
        }
    }
    if (blackPieces.size()) {
        printPiece(blackPieces[0]);
    }
    for (int i = 1; i < blackPieces.size(); i++) {
        std::cout << ',';
        printPiece(blackPieces[i]);
    }
    std::cout << '\n';

    return 0;
}