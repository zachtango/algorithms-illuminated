#include <iostream>
#include <string>

int main() {
    std::string month;
    int day;

    std::cin >> month >> day;

    std::string OCT {"OCT"}, DEC {"DEC"};

    if ((month == OCT && day == 31) ||
        (month == DEC && day == 25)) {
        std::cout << "yup" << '\n';
    } else {
        std::cout << "nope" << '\n';
    }

    return 0;
}