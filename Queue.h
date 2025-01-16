/*
 * Queue.h
 * 
 * Description: Header file defining the Queue class, which implements a FIFO (First In, First Out) data structure.
 *
 * Class Invariant:  FIFO or LILO order
 *
 * Author: Chowdhury Yasir(cya127) and Priyansh Sarvaiya (pgs3)
 * 
 * Last Modified: April. 2024
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "Event.h"
template <typename ElementType>

class Queue
{
private:
   unsigned int elementCount = 0; // Number of element in the Queue
   ElementType *elements;         // pointer  to a queue to store elemnts
   unsigned int capacity;
   unsigned int frontIndex; // Index of front element (next dequeued/peeked element)
   void resize(unsigned int newCapacity);

public:
   Queue(unsigned int initialCapacity = 10);                       // Constructor
   Queue(const Queue<ElementType> &other);                         // Copy Constructor
   ~Queue();                                                       // Destructor for dellocating memories dynamically
   Queue<ElementType> &operator=(const Queue<ElementType> &other); // Overloaded assignment operator

   // Description: Returns true if this Queue is empty, otherwise false.
   // Postcondition: This Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;
   // Description: Inserts newElement at the "back" of this Queue
   //              (not necessarily the "back" of this Queue's data structure)
   //              and returns true if successful, otherwise false.
   // Time Efficiency: O(1)
   bool enqueue(ElementType &newElement);

   // Description: Removes (but does not return) the element at the "front" of this Queue
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   void dequeue();

   // Description: Returns (but does not remove) the element at the "front" of this Queue
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType &peek() const;
};
#include "Queue.cpp"
#endif
