#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

constexpr const int BOARD_LENGTH {8};

void printSquare(char p, bool whiteSquare) {
    char c = whiteSquare ? '.' : ':';
    if (p == ' ') {
        p = c;
    }
    std::cout << c << p << c << '|';
}

void printRow() {
    for (int i = 0; i < 8; i++) {
        std::cout << "+---";
    }
    std::cout << '+' << '\n';
}

std::vector<std::string> tokenize(std::string s, char delim) {
    std::stringstream ss(s);

    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    
    char board[BOARD_LENGTH][BOARD_LENGTH];

    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            board[i][j] = ' ';
        }   
    }

    std::string white, black;

    std::getline(std::cin, white);
    std::getline(std::cin, black);

    std::vector<std::string> tokens = tokenize(white, ' ');
    if (tokens.size() == 2) {
        tokens = tokenize(tokens[1], ',');

        for (const auto &token : tokens) {
            if (token.size() == 2) {
                board[7 - (token[1] - '1')][token[0] - 'a'] = 'P';
            } else {
                board[7 - (token[2] - '1')][token[1] - 'a'] = token[0];
            }
        }
    }
    
    tokens = tokenize(black, ' ');
    if (tokens.size() == 2) {
        tokens = tokenize(tokens[1], ',');

        for (const auto &token : tokens) {
            if (token.size() == 2) {
                board[7 - (token[1] - '1')][token[0] - 'a'] = 'p';
            } else {
                board[7 - (token[2] - '1')][token[1] - 'a'] = std::tolower(token[0]);
            }
        }
    }

    printRow();
    for (int i = 0; i < BOARD_LENGTH; i++) {
        std::cout << '|';
        for (int j = 0; j < BOARD_LENGTH; j++) {
            printSquare(board[i][j], i % 2 == j % 2);
        }
        std::cout << '\n';
        printRow();
    }

    return 0;
}