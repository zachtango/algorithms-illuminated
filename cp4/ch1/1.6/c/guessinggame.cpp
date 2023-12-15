#include <iostream>
#include <string>

void solve(int firstGuess) {
    bool number[11];
    for (int i = 1; i <= 10; i++) {
        number[i] = true;
    }

    std::string response;

    while (std::cin >> response >> response) {
        if (response == "high") {
            for (int i = firstGuess; i <= 10; i++) {
                number[i] = false;
            }
        } else if (response == "low") {
            for (int i = 1; i <= firstGuess; i++) {
                number[i] = false;
            }
        } else {
            if (number[firstGuess]) {
                std::cout << "Stan may be honest" << '\n';
            } else {
                std::cout << "Stan is dishonest" << '\n';
            }
            break;
        }
        std::cin >> firstGuess;
    }

}

int main() {

    int firstGuess;
    while(std::cin >> firstGuess, firstGuess != 0) {
        solve(firstGuess);
    }

    return 0;
}