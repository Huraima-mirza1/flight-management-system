# Flight Management System Using Binary Search Tree (BST)

## Project Description

The **Flight Management System** is a C++ console-based application that manages airline flight records using a **Binary Search Tree (BST)**. Each flight is stored as a node, and the BST is organized by Flight ID.

The program helps an administrator add, search, delete, display, and manage flight information. It also provides simple flight-related features such as calculating estimated arrival times and finding the cheapest flight.

## Flight Record Information

Each flight record contains:

- Flight ID
- Source
- Destination
- Airline
- Departure time
- Arrival time
- Flight duration (in hours)
- Ticket price
- Flight status

Flight IDs must be unique. The program does not insert a flight if its ID already exists.

## Features

1. **Add Flight** – Enter a new flight record and add it to the BST.
2. **Search Flight** – Find a flight using its Flight ID.
3. **Delete Flight** – Delete a flight from the BST using its Flight ID.
4. **Display Flights** – Display all flights in ascending order of Flight ID using inorder traversal.
5. **Calculate ETA** – Calculate the estimated arrival time from the departure time and flight duration, then compare it with the scheduled arrival time. The result is shown as On-Time, Early, or Delayed.
6. **Cheapest Flight** – Find and display the flight with the lowest ticket price.
7. **Save Flights** – Save the current flight records to `flights.txt`.
8. **Load Flights** – Load flight records from `flights.txt`. The program also attempts to load saved records automatically when it starts.
9. **Exit** – Save the current records and close the program.

## Files in This Project

- `main.cpp` – The C++ source code.
- `flights.txt` – Sample flight records used for testing and file storage.
- `README.md` – Project description and instructions.

## Requirements

- A C++ compiler that supports **C++11 or later**, such as:
  - GCC / MinGW
  - Microsoft Visual Studio

## How to Run

### Using Visual Studio

1. Open Visual Studio.
2. Create or open a C++ Console App project.
3. Add `main.cpp` to the project.
4. Place `flights.txt` in the program's working directory so the program can read and update it.
5. Build and run the project.

### Using a terminal with g++

1. Open a terminal in the project folder.
2. Compile the program:

   ```bash
   g++ main.cpp -o FlightManagementSystem
   ```

3. Run it:

   **Windows:**
   ```bash
   FlightManagementSystem.exe
   ```

   **Linux / macOS:**
   ```bash
   ./FlightManagementSystem
   ```

Keep `flights.txt` in the program's working directory. The program reads from and writes to a file with this name.

## `flights.txt` Format

Each line represents one flight. The fields are separated by commas and must appear in this order:

```text
FlightID,Source,Destination,Airline,DepartureTime,ArrivalTime,Duration,TicketPrice,Status
```

Example:

```text
101,Lahore,Karachi,PIA,09:30,11:15,1.75,18000,Scheduled
102,Islamabad,Lahore,AirBlue,13:00,14:10,1.17,14500,Scheduled
103,Karachi,Islamabad,SereneAir,18:20,20:15,1.92,21000,Delayed
```

Use the `HH:MM` format for departure and arrival times. Do not add extra commas inside a field because the program uses commas to separate the fields.

## Data Structure

The project uses a **Binary Search Tree**:

- A flight with a smaller Flight ID is placed in the left subtree.
- A flight with a larger Flight ID is placed in the right subtree.
- Duplicate Flight IDs are not allowed.
- Inorder traversal displays the records in ascending Flight ID order.

## Notes

- The program saves records in `flights.txt` when a flight is added, deleted, when the Save option is selected, and when the program exits.
- Keep a backup of `flights.txt` if you want to preserve a copy of your sample data.
- Only use sample or non-private data in the repository.

## Author

Student project – C++ Flight Management System using a Binary Search Tree (BST).
