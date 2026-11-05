** Flight Management System Using BST**

 **Project Overview**

The Flight Management System is a C++ console application that manages flight records using a Binary Search Tree (BST). Each flight is stored as a node, and records are organized by Flight ID.

The system allows the user to add, search, delete, and display flights. It can also calculate estimated arrival times, find the cheapest flight, and save or load flight records using a text file.

## Flight Information

Each flight record contains:

- Flight ID
- Source
- Destination
- Airline
- Departure Time
- Arrival Time
- Flight Duration
- Ticket Price
- Flight Status

Each Flight ID must be unique. Duplicate Flight IDs are not inserted.

## Main Features

1. **Add Flight:** Add a new flight record to the BST.
2. **Search Flight:** Search for a flight using its Flight ID.
3. **Delete Flight:** Remove a flight using its Flight ID.
4. **Display Flights:** Display all flights in ascending order of Flight ID using inorder traversal.
5. **Calculate ETA:** Calculate the estimated arrival time using the departure time and flight duration, then compare it with the scheduled arrival time.
6. **Cheapest Flight:** Find and display the flight with the lowest ticket price.
7. **Save Flights:** Save flight records to `flights.txt`.
8. **Load Flights:** Load flight records from `flights.txt`. Saved records are also loaded automatically when the program starts.

## Project Files

- `main.cpp` – Contains the C++ source code and BST implementation.
- `flights.txt` – Stores sample flight records and saved flight data.
- `README.md` – Provides information about the project.

## Data Structure

The project uses a Binary Search Tree based on Flight ID:

- Smaller Flight IDs are stored in the left subtree.
- Larger Flight IDs are stored in the right subtree.
- Duplicate Flight IDs are not allowed.
- Inorder traversal displays flights in ascending order of Flight ID.

## Sample Flight File Format

Flight records in `flights.txt` are stored in comma-separated format:


FlightID,Source,Destination,Airline,DepartureTime,ArrivalTime,Duration,TicketPrice,Status


Example:

101,Lahore,Karachi,PIA,09:30,11:15,1.75,18000,Scheduled
102,Islamabad,Lahore,AirBlue,13:00,14:10,1.17,14500,Scheduled
103,Karachi,Islamabad,SereneAir,18:20,20:15,1.92,21000,Delayed


## How to Run

Open the project in Visual Studio and run the C++ program. Keep `flights.txt` in the program's working directory so the system can load and save flight records.

**Project:** C++ Flight Management System using a Binary Search Tree (BST)
