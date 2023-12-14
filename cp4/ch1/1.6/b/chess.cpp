#include <iostream>
#include <algorithm>

void printPosition(int x, int y) {
    std::cout << static_cast<char>(x + 'A' - 1) << ' ' << y;
}

bool isDiag(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) == std::abs(y1 - y2);
}

bool isOut(int x, int y) {
    return x < 1 || x > 8 || y < 1 || y > 8;
}

int main() {
    /*
        case 0:
            end position = start position
        case 1:
            end position on same diagnol start position is
        case 2:
            if end position is above,
                move diag up left or right until on same diag of end position, move to end position
            if end position is down
                move diag down left or right until same diag of end potiion, move to end position
        case impossible:
            end position on diff color squares
    */

    int t;
    std::cin >> t;
    
    int dir[4][2] {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < t; i++) {
        char x;
        int y;

        std::cin >> x >> y;

        int startX = x - 'A' + 1;
        int startY = y;

        std::cin >> x >> y;

        int endX = x - 'A' + 1;
        int endY = y;

        if (!((startX % 2 == startY % 2 && endX % 2 == endY % 2) ||
            (startX % 2 != startY % 2 && endX % 2 != endY % 2))) {
            std::cout << "Impossible" << '\n';
        } else if (startX == endX && startY == endY) {
            std::cout << "0 ";
            printPosition(startX, startY);
            std::cout << '\n';
        } else if (isDiag(startX, startY, endX, endY)) {
            std::cout << "1 ";
            printPosition(startX, startY);
            std::cout << " ";
            printPosition(endX, endY);
            std::cout << '\n';
        } else {
            // Go in all 4 directions until out of bounds or on same diag as end
            for (auto d : dir) {
                int currX = startX;
                int currY = startY;
                while (!isOut(currX, currY) && !isDiag(currX, currY, endX, endY)) {
                    currX += d[0];
                    currY += d[1];
                }
                if (!isOut(currX, currY) && isDiag(currX, currY, endX, endY)) {
                    std::cout << "2 ";
                    printPosition(startX, startY);
                    std::cout << ' ';
                    printPosition(currX, currY);
                    std::cout << ' ';
                    printPosition(endX, endY);
                    std::cout << '\n';
                    break;
                }
            }

        }

    }

    return 0;
}