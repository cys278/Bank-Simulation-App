/*
 * Queue.cpp
 * 
 * Description: Queue ADT Class
 *
 * Class Invariant:  FIFO or LILO order
 *
 * Author: Chowdhury Yasir(cya127) and Priyansh Sarvaiya (pgs3)
 * 
 * Last Modified: April. 2024
 */


#include <iostream>
#include "Queue.h"

using namespace std;

// Constructor to create a queue with specified initial capacity
template <typename ElementType>
Queue<ElementType>::Queue(unsigned int initialCapacity) : elementCount(0), elements(new ElementType[initialCapacity]), capacity(initialCapacity), frontIndex(0) {}

// Constructor to create a copy of an existing queue
template <typename ElementType>
Queue<ElementType>::Queue(const Queue<ElementType> &other) : elementCount(other.elementCount), elements(new ElementType[other.capacity]), capacity(other.capacity), frontIndex(other.frontIndex)
{
    // Copy elements from another queue
    for (unsigned int i = 0; i < other.elementCount; ++i)
    {
        elements[i] = other.elements[i];
    }
}

// Destructor to deallocate memory
template <typename ElementType>
Queue<ElementType>::~Queue()
{
    delete[] elements; // Deallocate memory
}

// Assignment operator overload to copy queue
template <typename ElementType>
Queue<ElementType> &Queue<ElementType>::operator=(const Queue<ElementType> &other)
{
    if (this != &other)
    {
        delete[] elements;
        elementCount = other.elementCount;
        capacity = other.capacity;
        frontIndex = other.frontIndex;
        elements = new ElementType[capacity];
        // Copy elements from another queue
        for (unsigned int i = 0; i < other.elementCount; ++i)
        {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

// Check if the queue is empty
template <typename ElementType>
bool Queue<ElementType>::isEmpty() const
{
    return elementCount == 0;
}

// Add a new element to the end of the queue
template <typename ElementType>
bool Queue<ElementType>::enqueue(ElementType &newElement)
{
    if (elementCount == capacity)
    {
        resize(capacity * 2); // Double the capacity if queue is full
    }
    elements[(frontIndex + elementCount) % capacity] = newElement;
    ++elementCount;
    return true;
}

// Remove the front element from the queue
template <typename ElementType>
void Queue<ElementType>::dequeue()
{
    if (isEmpty())
    {
        throw EmptyDataCollectionException("Queue is empty");
    }
    frontIndex = (frontIndex + 1) % capacity;
    --elementCount;
}

// Get the front element of the queue without removing it
template <typename ElementType>
ElementType &Queue<ElementType>::peek() const
{
    if (isEmpty())
    {
        throw EmptyDataCollectionException("Queue is empty");
    }
    return elements[frontIndex];
}

// Resize the capacity of the queue
template <typename ElementType>
void Queue<ElementType>::resize(unsigned int newCapacity)
{
    ElementType *newElements = new ElementType[newCapacity];
    // Copy elements to the new array
    for (unsigned int i = 0; i < elementCount; ++i)
    {
        newElements[i] = elements[(frontIndex + i) % capacity];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
    frontIndex = 0;
}