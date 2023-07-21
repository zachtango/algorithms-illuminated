#include <iostream>
#include <string>
#include "HashTable.h"

int main() {
    HashTable<std::string> hashMap;

    // Insert some elements
    hashMap.Insert(10, "Alice");
    hashMap.Insert(25, "Bob");
    hashMap.Insert(53, "Charlie");
    hashMap.Insert(92, "David");
    hashMap.Insert(102, "Eve");

    // Search for elements
    std::cout << "Searching for elements:" << std::endl;
    try {
        std::cout << "Search 10: " << hashMap.Search(10) << std::endl;
        std::cout << "Search 53: " << hashMap.Search(53) << std::endl;
        std::cout << "Search 102: " << hashMap.Search(102) << std::endl;
        std::cout << "Search 5: " << hashMap.Search(5) << std::endl; // Key not present
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    // Delete an element
    std::cout << "\nDeleting elements:" << std::endl;
    hashMap.Delete(25);
    hashMap.Delete(102);

    // Search after deletion
    std::cout << "Search 25: ";
    try {
        std::cout << hashMap.Search(25) << std::endl; // Key not present
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Search 102: ";
    try {
        std::cout << hashMap.Search(102) << std::endl; // Key not present
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    // Insert more elements to test reallocation
    for (int i = 0; i < 100; i++) {
        std::string name = "User" + std::to_string(i);
        hashMap.Insert(i, name);
    }

    // Search after reallocation
    std::cout << "\nSearching for elements after reallocation:" << std::endl;
    try {
        std::cout << "Search 92: " << hashMap.Search(92) << std::endl;
        std::cout << "Search 53: " << hashMap.Search(53) << std::endl;
        std::cout << "Search 101: " << hashMap.Search(101) << std::endl; // Key not present
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
