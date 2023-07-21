#include "bst.h"
#include <iostream>
#include <cassert>

// Test function for the BST
void testBST() {
    BST<int> bst;

    // Test inserting elements
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(12);
    bst.Insert(17);

    // Test searching for elements
    assert(*bst.Search(10) == 10);
    assert(*bst.Search(5) == 5);
    assert(*bst.Search(15) == 15);
    assert(bst.Search(100) == nullptr); // Element not found

    // Test finding minimum and maximum
    assert(*bst.Min() == 3);
    assert(*bst.Max() == 17);

    // Test finding predecessor and successor
    assert(*bst.Predecessor(7) == 5);
    assert(*bst.Successor(7) == 10);
    assert(bst.Predecessor(3) == nullptr); // No predecessor
    assert(bst.Successor(17) == nullptr); // No successor

    // Test deleting elements
    bst.Delete(5);
    assert(bst.Search(5) == nullptr);

    bst.Delete(15);
    assert(bst.Search(15) == nullptr);

    bst.Delete(10);
    assert(bst.Search(10) == nullptr);

    // Test outputting the sorted elements
    bst.OutputSorted();
    std::cout << std::endl;

    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(10);

    bst.OutputSorted();
    std::cout << std::endl;

    // Test selecting elements by rank
    for (int i = 0; i < 7; i++) {
        std::cout << "Element with rank " << i << ": " << *bst.Select(i) << std::endl;
    }

    // Test selecting an element out of range (should throw exception)
    bst.Select(10);
}

int main() {
    testBST();
    return 0;
}
