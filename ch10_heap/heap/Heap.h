#include <unordered_map>
#include <algorithm>
#include <exception>
#include <iostream>

/*
    Heap operations
    - Insert
    - ExtractMin
    - Delete
    - FindMin
*/

const int DEFAULT_HEAP_SIZE = 10;

template <typename T>
class Heap {
private:
    T *elements;
    int n;
    int nextI;
    
    std::unordered_map<T, int> elementToI;

    int parent(int i) { return i / 2; }
    int leftChild(int i) { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }

    void bubbleUp(int i);
    void bubbleDown(int i);

public:
    Heap() {
        n = DEFAULT_HEAP_SIZE;
        elements = new T[n];
        nextI = 0;
    }

    int Size() { return nextI; }

    void Insert(T element);

    T ExtractMin();

    void Delete(T element);

    T FindMin();

    ~Heap() {
        delete[] elements;
    }
};

template <typename T>
void Heap<T>::bubbleUp(int i) {

    int p = parent(i);

    while (elements[i] < elements[p]) {
        std::swap(elements[i], elements[p]);
        elementToI[elements[i]] = i;
        i = p;
        p = parent(i);
    }

    elementToI[elements[i]] = i;
}

template <typename T>
void Heap<T>::bubbleDown(int i) {

    int l = leftChild(i);
    int r = rightChild(i);

    while (l < nextI) {
        T *smaller;
        int c;
        if (r >= nextI || elements[l] < elements[r]) {
            smaller = &elements[l];
            c = l;
        } else {
            smaller = &elements[r];
            c = r;
        }

        if (*smaller < elements[i]) {
            std::swap(*smaller, elements[i]);
            elementToI[elements[i]] = i;
        } else {
            break;
        }

        i = c;
        l = leftChild(i);
        r = leftChild(i);
    }

    elementToI[elements[i]] = i;
}

template <typename T>
void Heap<T>::Insert(T element) {

    if (elementToI.count(element) == 1) {
        throw std::runtime_error("Cannot insert element: element already exists");
    }

    if (nextI == n) {
        T *newElements = new T[2 * n];
        std::copy(elements, elements + nextI, newElements);

        delete[] elements;

        elements = newElements;
    }

    elements[nextI] = element;

    // Bubble up as needed to maintain heap invariant
    bubbleUp(nextI);

    nextI += 1;
}

template <typename T>
T Heap<T>::ExtractMin() {
    T minElement = FindMin();

    Delete(minElement);

    return minElement;
}

template <typename T>
void Heap<T>::Delete(T element) {
    if (elementToI.count(element) == 0) {
        throw std::runtime_error("Cannot delete element: element does not exist");
    }

    nextI -= 1;
    
    int i = elementToI[element];

    std::swap(elements[i], elements[nextI]);

    bubbleDown(i);

    elementToI.erase(element);
}

template <typename T>
T Heap<T>::FindMin() {
    if (nextI == 0) {
        throw std::runtime_error("Cannot find min element: heap is empty");
    }
    return elements[0];
}
