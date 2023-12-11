#include <iostream>
#include <string>
#include <limits>
#include <sstream>

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

int main() {
    /*
        student begins post-secondary studies in 2010 or later --> eligible
        student born in 1991 or later --> eligible
        none of above and student has more than 8 semesters of full time study --> ineligible
        none of above --> petition for extension

        5 courses = 1 semester
    */

    int n;
    std::cin >> n;

    std::string name;

    int postSecondaryYear, bornYear, courses;

    for (int i = 0; i < n; i++) {
        std::cin >> name >> postSecondaryYear;
        
        std::cin.ignore(max_size, ' ');

        std::cin >> bornYear;

        std::cin.ignore(max_size, ' ');

        std::cin >> courses;

        if (postSecondaryYear >= 2010 || bornYear >= 1991) {
            std::cout << name << " eligible" << '\n';
        } else if (courses > 40) {
            std::cout << name << " ineligible" << '\n';
        } else {
            std::cout << name << " coach petitions" << '\n';
        }
    }

    

    return 0;
}