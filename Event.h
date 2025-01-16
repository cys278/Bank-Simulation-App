/*
 * Event.h
 * 
 * Description: Header file defining the Event class, which represents an event in the simulation.
 *              Events can either be of type 'A' (Arrival) or 'D' (Departure).
 * 
 * Author: Chowdhury Yasir (cya127) and Priyansh Sarvaiya (pgs3)
 * 
 * Last Modified: April 2024
 */

#ifndef EVENT_H
#define EVENT_H

#include <stdexcept> // For exceptions
#include <string>    // For string representation of exceptions

class Event {
public:
    // Type definitions for event types
    static const char ARRIVAL = 'A';
    static const char DEPARTURE = 'D';

private:
    char type;      // Event type ('A' for Arrival, 'D' for Departure)
    int time;       // Time when the event occurs
    int length;     // Length of service time for Arrival events (0 for Departure events)

public:
    // Default Constructor
    // Description: Creates an Event with default values.
    Event();

    // Parameterized Constructor
    // Description: Creates an Event with specified type and time.
    Event(char eventType, int eventTime, int serviceLength = 0);

    // Getters
    // Description: Returns the type of the event ('A' or 'D').
    char getType() const;

    // Description: Returns the time associated with the event.
    int getTime() const;

    // Description: Returns the service length of the event.
    int getLength() const;

    // Setters
    // Description: Sets the type of the event.
    void setType(char eventType);

    // Description: Sets the time of the event.
    void setTime(int eventTime);

    // Description: Sets the service length of the event.
    void setLength(int serviceLength);

    // Overloaded Operators
    // Description: Compares two events based on their times.
    //              Returns true if the current event occurs earlier than the other.
    bool operator<(const Event& other) const;

    // Description: Compares two events based on their times.
    //              Returns true if the current event occurs later than the other.
    bool operator>(const Event& other) const;
};

#endif // EVENT_H
