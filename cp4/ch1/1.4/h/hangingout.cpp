#include <iostream>
#include <string>

int main() {
    int L, x;

    std::cin >> L >> x;

    std::string action;
    int p;

    int numDenials = 0;
    int numPeople = 0;
    for (int i = 0; i < x; i++) {
        std::cin >> action >> p;

        if (action == "enter") {
            if ( (numPeople + p) > L ) {
                numDenials += 1;
            } else {
                numPeople += p;
            }
        } else {
            numPeople -= p;
        }
    }

    std::cout << numDenials << '\n';

    return 0;
}