/*
 * BinaryHeap.cpp
 *
 * Description: Binary Heap ADT class.
 *
 * Class Invariant:  Always a Complete Binary Heap.
 *
 * Author: Chowdhury Yasir
 * 
 * Last Modification: April. 2024
 *
 */

#include <iostream>
#include "BinaryHeap.h" // Header file
#include "Queue.h"
#include "Event.h"

using std::cout;
using std::endl;

// Constructor to create a Binary Heap with the specified initial capacity
template <typename ElementType>
BinaryHeap<ElementType>::BinaryHeap(unsigned int initialCapacity)
    : elementCount(0), elements(new ElementType[initialCapacity]), capacity(initialCapacity) {}

// Destructor to deallocate memory
template <typename ElementType>
BinaryHeap<ElementType>::~BinaryHeap()
{
    delete[] elements;
}

// Get the current number of elements in the Binary Heap
template <typename ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const
{
    return elementCount;
}

// Insert a new element into the Binary Heap
template <typename ElementType>
bool BinaryHeap<ElementType>::insert(ElementType &newElement)
{
    if (elementCount == capacity)
    {
        // Resize the array if it's full
        ElementType *newElements = new ElementType[capacity * 2];
        for (unsigned int i = 0; i < elementCount; ++i)
        {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity *= 2;
    }

    // Place the new element at the end
    elements[elementCount++] = newElement;

    // ReheapUp to maintain the heap property
    unsigned int currentIndex = elementCount - 1;
    while (currentIndex > 0)
    {
        unsigned int parentIndex = (currentIndex - 1) / 2;
        if (elements[currentIndex] <= elements[parentIndex])
        {
            // Swap with parent
            ElementType temp = elements[currentIndex];
            elements[currentIndex] = elements[parentIndex];
            elements[parentIndex] = temp;
            currentIndex = parentIndex;
        }
        else
        {
            break; // Heap property satisfied
        }
    }

    return true;
}

// Remove the root element from the Binary Heap
template <class ElementType>
void BinaryHeap<ElementType>::remove()
{

    if (elementCount == 0)
        throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

    elements[0] = elements[elementCount - 1];
    elementCount--;

    // No need to call reheapDown() is we have just removed the only element
    if (elementCount > 0)
        reHeapDown(0);

    return;
}

// Retrieve the root element of the Binary Heap
template <typename ElementType>
ElementType &BinaryHeap<ElementType>::retrieve() const
{
    if (elementCount == 0)
    {
        throw EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.");
    }
    return elements[0];
}

// Utility method
// Description: Recursively put the array back into a Complete Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot)
{

    unsigned int indexOfMinChild = indexOfRoot;

    // Find indices of children.
    unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
    unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

    // Base case: elements[indexOfRoot] is a leaf as it has no children
    if (indexOfLeftChild > elementCount - 1)
        return;

    // If we need to swap, select the smallest child
    // If (elements[indexOfRoot] > elements[indexOfLeftChild])
    if (!(elements[indexOfRoot] <= elements[indexOfLeftChild]))
        indexOfMinChild = indexOfLeftChild;

    // Check if there is a right child, is it the smallest?
    if (indexOfRightChild < elementCount)
    {
        // if (elements[indexOfMinChild] > elements[indexOfRightChild])
        if (!(elements[indexOfMinChild] <= elements[indexOfRightChild]))
            indexOfMinChild = indexOfRightChild;
    }

    // Swap parent with smallest of children.
    if (indexOfMinChild != indexOfRoot)
    {

        ElementType temp = elements[indexOfRoot];
        elements[indexOfRoot] = elements[indexOfMinChild];
        elements[indexOfMinChild] = temp;

        // Recursively put the array back into a heap
        reHeapDown(indexOfMinChild);
    }
    return;
}
