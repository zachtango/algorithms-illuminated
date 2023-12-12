#include <iostream>
#include <string>

int main() {
    std::string s;

    std::getline(std::cin, s);

    std::cout << "Thank you, " << s << ", and farewell!" << '\n';

    return 0;
}