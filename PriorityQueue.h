/*
 * PriorityQueue.h
 *
 * Description: Header file defining the PriorityQueue class, which implements a priority queue data structure using a binary heap.
 *
 * Author: Chowdhury Yasir(cya127) and Priyansh Sarvaiya (pgs3)
 * 
 * Last Modification: April. 2024
 *
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Queue.h"
#include "Event.h"
#include "BinaryHeap.h" // Assuming ElementType is Event, change it accordingly if not

template <typename ElementType>
class PriorityQueue
{

private:
    BinaryHeap<ElementType> binaryHeap; // Binary Heap as the underlying data structure

public:
    /******* Start of Priority Queue Public Interface *******/

    // Description: Returns true if this Priority Queue is empty, otherwise false.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in this Priority Queue and
    //              returns true if successful, otherwise false.
    // Time Efficiency: O(log2 n)
    bool enqueue(ElementType &newElement);

    // Description: Removes (but does not return) the element with the next
    //              "highest" priority value from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
    // Time Efficiency: O(log2 n)
    void dequeue();

    // Description: Returns (but does not remove) the element with the next
    //              "highest" priority value from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType &peek() const;

    // Gives the total number of elements in PriorityQueue
    int getElementCount();

};

#include "PriorityQueue.cpp" //Including the implementation file
#endif