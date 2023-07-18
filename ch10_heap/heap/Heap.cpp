#ifndef HEAP_CPP
#define HEAP_CPP

#include "Heap.h"
#include <algorithm>
using std::copy;
using std::swap;
#include <exception>
using std::runtime_error;
#include <iostream>
using std::cout;

/*

*/
template <typename T>
void Heap<T>::bubbleDown(int i) {
    while (leftChild(i) < nextI) {
        int l = leftChild(i);
        int r = rightChild(i);
        int lastI = i;

        T* smaller;

        if (r >= nextI || elements[l] < elements[r]) {
            smaller = &elements[l];
            i = l;
        } else {
            smaller = &elements[r];
            i = r;
        }
        
        if (*smaller < elements[lastI]) {
            elementsToI[*smaller] = lastI;
            swap(*smaller, elements[lastI]);
        } else {
            break;
        }
    }

    // Update element bubbled down
    elementsToI[elements[i]] = i;
}

/*
    O(logn) because the array is a full binary tree
    Insert element at leaf level
        bubble the element up the tree as needed to maintain the heap invariant
*/
template <typename T>
void Heap<T>::Insert(T element) {
    // Only allow unique elements
    if (elementsToI.count(element) == 1) {
        throw std::runtime_error("Cannot insert element: element already exists");
    }

    // Allocate new space if needed
    if (nextI == n) {
        T *newElements = new T[n * 2];
        
        copy(elements, elements + n, newElements);

        elements = newElements;
    }

    // Insert at leaf level
    elements[nextI] = element;

    // Bubble up as needed to maintain heap invariant
    int i = nextI;
    int lastI = i;
    while (i != 0) {
        int p = parent(i);

        if (elements[i] < elements[p]) {
            elementsToI[elements[p]] = i;
            swap(elements[i], elements[p]);
        } else {
            break;
        }

        i = p;
        lastI = i;
    }
    elementsToI[element] = lastI;

    nextI += 1;
}

/*
    O(logn) because the array is a full binary tree
    Remove minimum element from the heap
        Reorganize heap to maintain heap invariant
*/
template <typename T>
T Heap<T>::ExtractMin() {
    if (nextI == 0) {
        throw runtime_error("Cannot extract from heap of size 0");
    }
    
    T minElement = elements[0];

    Delete(minElement);

    return minElement;
}

/*
    O(logn) because the array is a full binary tree
    Remove element from heap
        Reorganize heap to maintain heap invariant
*/
template <typename T>
void Heap<T>::Delete(T element) {
    if (elementsToI.count(element) == 0) {
        throw runtime_error("Cannot delete element: element does not exist in heap");
    }
    nextI -= 1;

    int i = elementsToI[element];
    
    // Swap root element (min element) and last element to maintain full binary tree structure
    swap(elements[i], elements[nextI]);

    // Bubble the root element down as needed to maintain heap invariant
    bubbleDown(i);

    // Remove min element from index tracking
    elementsToI.erase(elements[nextI]);
}

template <typename T>
void Heap<T>::Output() {
    cout << "Heap: ";
    for (int i = 0; i < nextI; i++) {
        cout << elements[i] << ' ';
    }
    
    cout << "\nElements: ";
    for (auto &p : elementsToI) {
        cout << p.first << ' ' << p.second << ' ';
    }

    cout << '\n';
}

#endif