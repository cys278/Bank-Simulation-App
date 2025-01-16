/*
 * BinaryHeap.h
 * 
 * Description: Header file defining the BinaryHeap class, which implements a Complete Binary Heap data structure.
 * 
 * Class Invariant:  Always a Complete Binary Heap.
 *
 * Author: Chowdhury Yasir
 * 
 * Last Modified: April. 2024
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include "Event.h"
#include "Queue.h"

template <typename ElementType>

class BinaryHeap
{

private:
    unsigned int elementCount;
    ElementType *elements;
    unsigned int capacity;

    void reHeapDown(unsigned int indexOfRoot);

public:
    BinaryHeap(unsigned int initialCapacity = 10); // Constructor

    ~BinaryHeap(); // Destructor

    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition: The Binary Heap is unchanged by this operation.
    // Time Efficiency: O(1)

    unsigned int getElementCount() const;

    // Description: Inserts newElement into the Binary Heap.
    //              It returns true if successful, otherwise false.
    // Time Efficiency: O(log2 n)

    bool insert(ElementType &newElement);

    // Description: Removes (but does not return) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(log2 n)

    void remove();

    // Description: Retrieves (but does not remove) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Postcondition: This Binary Heap is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(1)

    ElementType &retrieve() const;
};
#include "BinaryHeap.cpp" // Including the implementation file
#endif
