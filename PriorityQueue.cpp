/*
 * PriorityQueue.cpp
 *
 * Description: PriorityQueue ADT class 
 *
 * Author: Chowdhury Yasir(cya127) and Priyansh Sarvaiya (pgs3)
 * 
 * Last Modification: April. 2024
 *
 */


#include "PriorityQueue.h"

// Returns true if the priority queue is empty, otherwise false.
template<typename ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return binaryHeap.getElementCount() == 0;
}

// Enqueues a new element into the priority queue.
// Returns true if the insertion is successful, otherwise false.
template<typename ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType& newElement) {
    return binaryHeap.insert(newElement);
}

// Dequeues the element with the highest priority from the priority queue.
// Throws an EmptyDataCollectionException if the priority queue is empty.
template<typename ElementType>
void PriorityQueue<ElementType>::dequeue() {
    if (isEmpty()) {
        throw EmptyDataCollectionException("dequeue() called with an empty PriorityQueue.");
    }
    binaryHeap.remove();
}

// Retrieves the element with the highest priority from the priority queue without removing it.
// Throws an EmptyDataCollectionException if the priority queue is empty.
template<typename ElementType>
ElementType& PriorityQueue<ElementType>::peek() const {
    if (isEmpty()) {
        throw EmptyDataCollectionException("peek() called with an empty PriorityQueue.");
    }
    return binaryHeap.retrieve();
}

// Returns the number of elements in the priority queue.
template<typename ElementType>
int PriorityQueue<ElementType>::getElementCount() {
    return binaryHeap.getElementCount();
}