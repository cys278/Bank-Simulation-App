/*
 * BankSimApp.cpp
 *
 * Description: Handles simulation of events
 * 
 * Author: Chowdhury Yasir(cya127) and Priyansh Sarvaiya (pgs3)
 * 
 *  Last Modified: April 2024
 */

#include "EmptyDataCollectionException.h"
#include <iostream>
#include "Queue.h"
#include "PriorityQueue.h"
#include "BinaryHeap.h"
#include "Event.h"

using namespace std;

#include <sstream>
#include <iomanip>

int totalWaitTime = 0; // Global variable to store total waiting time

// Function to process arrival event
void processArrival(Event &arrivalEvent, PriorityQueue<Event> &eventPriorityQueue, Queue<Event> &bankLine, int &currentTime, bool &tellerAvailable)
{
    cout << "Processing an arrival event at time:" << setw(5) << right << currentTime << endl;
    eventPriorityQueue.dequeue(); // Remove arrival event from priority queue
    int departureTime;
    if (bankLine.isEmpty() && tellerAvailable) // If bank line is empty and teller is available
    {
        departureTime = currentTime + arrivalEvent.getLength(); // Calculate departure time
        Event departureEvent = Event('D', departureTime); // Create departure event
        eventPriorityQueue.enqueue(departureEvent); // Enqueue departure event
        tellerAvailable = false; // Set teller as unavailable
    }
    else
    {
        bankLine.enqueue(arrivalEvent); // Enqueue arrival event to bank line
    }
}

// Function to process departure event
void processDeparture(Event &departureEvent, PriorityQueue<Event> &eventPriorityQueue, Queue<Event> &bankLine, int &currentTime, bool &tellerAvailable)
{
    cout << "Processing a departure event at time:" << setw(4) << right << currentTime << endl; // Print departure event information
    eventPriorityQueue.dequeue(); // Remove departure event from priority queue

    int departureTime;

    if (!bankLine.isEmpty()) // If bank line is not empty
    {

        try
        {
            Event customer = bankLine.peek(); // Peek next customer in bank line
            totalWaitTime = totalWaitTime + currentTime - customer.getTime(); // Update total waiting time
            bankLine.dequeue(); // Remove customer from bank line
            departureTime = currentTime + customer.getLength(); // Calculate departure time for next customer
            Event newDepartureEvent = Event('D', departureTime); // Create new departure event
            eventPriorityQueue.enqueue(newDepartureEvent); // Enqueue new departure event
        }
        catch (EmptyDataCollectionException &exception) // Catch exception if bank line is empty
        {
            cout << exception.what() << endl; // Print exception message
        }
    }
    else
    {
        tellerAvailable = true; // Set teller as available if bank line is empty
    }
}

int main(int argc, char *argv[])
{

    cout << "Simulation Begins" << endl;

    // Initialize variables
    int currentTime = 0;
    Queue<Event> bankLine = Queue<Event>();
    PriorityQueue<Event> eventPriorityQueue = PriorityQueue<Event>();

    bool tellerAvailable = true;

    int customerCount = 0.0;

    string aLine = "";
    int length = 0;
    int time = 0;
    Event streamEvent;

    // Read input data and enqueue events
    while (getline(cin >> ws, aLine))
    { // while (there is data)
        stringstream ss(aLine); // Create stringstream for parsing
        ss >> time >> length; // Extract time and length from input line
        streamEvent = Event(); // Create new Event object
        streamEvent.setLength(length); // Set length for Event
        streamEvent.setTime(time); // Set time for Event

        if (!eventPriorityQueue.enqueue(streamEvent)) // Enqueue Event to priority queue
        {
            return 1; // Return error code if enqueue fails
        }
    }
    customerCount = eventPriorityQueue.getElementCount(); // Get total number of customers

    // Event Loop
    while (!eventPriorityQueue.isEmpty())
    {
        try
        {
            Event newEvent = eventPriorityQueue.peek(); // Get next event from priority queue
            currentTime = newEvent.getTime(); // Update current time to event time

            if (newEvent.getType() == Event::ARRIVAL) // If arrival event
            {
                processArrival(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable); // Process arrival event
            }
            else // If departure event
            {
                processDeparture(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable); // Process departure event
            }
        }
        catch (EmptyDataCollectionException &exception) // Catch exception if priority queue is empty
        {
            cout << exception.what() << endl; // Print exception message
        }
    }

    // Print statistics
    cout << "Simulation Ends" << endl;
    cout << endl;
    cout << "Final Statistics: " << endl;
    cout << "    Total number of people processed:  " << customerCount << endl;
    cout << "    Average amount of time spent waiting: " << (float)totalWaitTime / (float)customerCount << endl;
    return 0;
}