#include <iostream>
#include <string>
#include <algorithm>

bool isCombo(int i, const std::string &moves) {
    
    if ((i + 2) >= moves.size()) {
        return false;
    }

    auto end = moves.begin() + i + 3;

    auto R = std::find(moves.begin() + i, end, 'R');
    auto B = std::find(moves.begin() + i, end, 'B');
    auto L = std::find(moves.begin() + i, end, 'L');

    return R != end && B != end && L != end;
}

int main() {
    std::string moves;

    std::cin >> moves;

    for (int i = 0; i < moves.size(); i++) {
        if (isCombo(i, moves)) {
            std::cout << 'C';
            i += 2;
        } else {
            switch(moves[i]) {
                case 'R':
                    std::cout << 'S';
                    break;
                case 'B':
                    std::cout << 'K';
                    break;
                case 'L':
                    std::cout << 'H';
                    break;
            }
        }
    }

    std::cout << '\n';

    return 0;
}