# Bank Simulation Project

## Overview
This project simulates a banking system using **event-driven programming** principles. The simulation processes customers arriving at and being served by a bank teller. It utilizes advanced data structures such as queues and binary heaps to manage and prioritize events in a time-efficient manner.

---

## Features
- Simulates **arrival** and **departure** events for bank customers.
- Maintains a **FIFO queue** for managing customers waiting in line.
- Implements a **priority queue** using a binary heap to prioritize events by timestamp.
- Dynamically resizes memory for queues and heaps as needed.
- Calculates statistics:
  - Total customers processed.
  - Average waiting time.

---

## Data Structures
1. **Queue:**
   - Implements a FIFO structure to manage the bank line.
   - Resizable for dynamic memory allocation.

2. **Binary Heap:**
   - Manages events in a priority queue.
   - Ensures that events are processed based on their time in ascending order.

3. **Priority Queue:**
   - Built on the binary heap.
   - Adds functionality for enqueueing and dequeueing events with priority.

---

## How It Works
1. **Input Format:**
   - Each line in the input contains two integers:
     - **Time:** Arrival time of the customer.
     - **Length:** Duration for which the teller will serve the customer.

2. **Event Handling:**
   - **Arrival Event:**
     - If the teller is free, the customer is served immediately.
     - Otherwise, the customer is added to the bank queue.
   - **Departure Event:**
     - Removes the customer being served and serves the next customer from the bank queue if any are waiting.

3. **Simulation Process:**
   - Reads input data to create arrival events.
   - Uses a **priority queue** to process events in chronological order.
   - Calculates the total number of customers and average wait time.

---

## Files and Implementation
### **1. Queue.h/Queue.cpp**
- Implements the Queue class.
- Resizable array-based FIFO structure for storing events.

### **2. BinaryHeap.h/BinaryHeap.cpp**
- Implements the Binary Heap.
- Used as the underlying structure for the priority queue.

### **3. PriorityQueue.h/PriorityQueue.cpp**
- Implements a priority queue using a binary heap.
- Handles enqueue, dequeue, and peek operations.

### **4. Event.h**
- Defines the `Event` class.
- Tracks event type (`Arrival` or `Departure`), time, and duration.

### **5. BankSimApp.cpp**
- The main application file.
- Handles input, simulation logic, and output of statistics.

---

## Usage
### **Compilation**
```bash
g++ -std=c++17 -o BankSimApp BankSimApp.cpp Queue.cpp BinaryHeap.cpp PriorityQueue.cpp Event.cpp
