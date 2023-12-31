#include <iostream>
#include "Heap.h"

int main() {
    Heap<int> heap;

    // Test Insert function
    heap.Insert(8);
    heap.Insert(5);
    heap.Insert(12);
    heap.Insert(3);
    heap.Insert(10);

    // Expected output: Heap: 3 5 10 8 12

    // Test ExtractMin function
    while (heap.Size() > 0) {
        int minElement = heap.ExtractMin();
        std::cout << minElement << " ";
    }
    std::cout << std::endl;  // Expected output: 3 5 8 10 12

    // Test Delete function
    heap.Insert(8);
    heap.Insert(5);
    heap.Insert(12);
    heap.Insert(3);
    heap.Insert(10);

    heap.Delete(5);

    // Expected output: Heap: 3 8 10 12
    
    return 0;
}
