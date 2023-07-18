#ifndef HEAP_H
#define HEAP_H

#include <unordered_map>

/*
    For the sake of simplicity, this heap only works with unique elements
*/
template <typename T>
class Heap {
private:
    T *elements;
    std::unordered_map<T, int> elementsToI;

    int n;
    int nextI;

    int parent(int i) { return i / 2; }
    int leftChild(int i) { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }

    void bubbleDown(int i);
public:
    Heap() {
        elements = new T[10];
        n = 10;
        nextI = 0;
    }

    int size() { return nextI; }

    void Insert(T element);

    T ExtractMin();

    void Delete(T element);

    void Output();

    T FindMin() { return elements[0]; }
};

#include "Heap.cpp"

#endif