#include <iostream>

int main() {
    int minDay = 0;
    int minJunk;

    int n;

    std::cin >> n >> minJunk;

    int junk;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> junk;

        if (junk < minJunk) {
            minJunk = junk;
            minDay = i + 1;
        }
    }

    std::cout << minDay << '\n';

    return 0;
}