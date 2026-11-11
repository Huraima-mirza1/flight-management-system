#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Convert time into minutes
int timeToMinutes(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));

    return hours * 60 + minutes;
}

// Node structure
struct Node {

    Node* left;
    Node* right;
    Node* p;

    int flightID;
    string source;
    string destination;
    string airline;
    string departure_time;
    string arrival_time;
    double flight_duration;
    int ticketPrice;
    string status;

    Node(int id, string s, string d, string a,
         string dep, string arr, double duration,
         int price, string stat) {

        flightID = id;
        source = s;
        destination = d;
        airline = a;
        departure_time = dep;
        arrival_time = arr;
        flight_duration = duration;
        ticketPrice = price;
        status = stat;

        left = nullptr;
        right = nullptr;
        p = nullptr;
    }
};

// BST class
class BST {

public:

    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a flight
    void insert(int id, string s, string d, string a,
                string dep, string arr, double duration,
                int price, string stat, bool showMessage = true) {

        if (search(id) != nullptr) {

            if (showMessage) {
                cout << "Flight with ID " << id
                     << " already exists. Insertion failed.\n";
            }

            return;
        }

        Node* newNode = new Node(id, s, d, a, dep,
                                 arr, duration, price, stat);

        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {

            y = x;

            if (newNode->flightID < x->flightID) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        newNode->p = y;

        if (y == nullptr) {
            root = newNode;
        }
        else if (newNode->flightID < y->flightID) {
            y->left = newNode;
        }
        else {
            y->right = newNode;
        }

        if (showMessage) {
            cout << "Flight inserted successfully.\n";
        }
    }

    // Search a flight
    Node* search(int id) {

        Node* current = root;

        while (current != nullptr && current->flightID != id) {

            if (id < current->flightID) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        return current;
    }

    // Find minimum node
    Node* minimum(Node* x) {

        while (x->left != nullptr) {
            x = x->left;
        }

        return x;
    }

    // Display one flight
    void displayFlight(Node* x) {

        cout << "\nFlight ID: " << x->flightID;
        cout << "\nSource: " << x->source;
        cout << "\nDestination: " << x->destination;
        cout << "\nAirline: " << x->airline;
        cout << "\nDeparture Time: " << x->departure_time;
        cout << "\nArrival Time: " << x->arrival_time;
        cout << "\nFlight Duration: " << x->flight_duration << " hours";
        cout << "\nTicket Price: " << x->ticketPrice;
        cout << "\nStatus: " << x->status << "\n";
    }

    // Replace one node with another
    void transplant(Node* u, Node* v) {

        if (u->p == nullptr) {
            root = v;
        }
        else if (u == u->p->left) {
            u->p->left = v;
        }
        else {
            u->p->right = v;
        }

        if (v != nullptr) {
            v->p = u->p;
        }
    }

    // Delete a flight
    void deleteNode(int id) {

        Node* z = search(id);

        if (z == nullptr) {
            cout << "Flight not found. Cannot delete.\n";
            return;
        }

        // Case 1: No left child
        if (z->left == nullptr) {
            transplant(z, z->right);
        }

        // Case 2: No right child
        else if (z->right == nullptr) {
            transplant(z, z->left);
        }

        // Case 3: Two children
        else {

            Node* y = minimum(z->right);

            if (y->p != z) {

                transplant(y, y->right);

                y->right = z->right;
                y->right->p = y;
            }

            transplant(z, y);

            y->left = z->left;
            y->left->p = y;
        }

        delete z;

        cout << "Flight deleted successfully.\n";
    }

    // Inorder traversal
    void inorder(Node* x) {

        if (x != nullptr) {

            inorder(x->left);
            displayFlight(x);
            inorder(x->right);
        }
    }

    // Display all flights in ascending order
    void display() {

        if (root == nullptr) {
            cout << "No flights available.\n";
            return;
        }

        cout << "\nFlights in ascending order of Flight ID:\n";

        inorder(root);
    }

    // Calculate ETA
    int CalculateETA(string dep, double dur) {

        int depMinutes = timeToMinutes(dep);
        int durMinutes = dur * 60;
        int totalminutes = depMinutes + durMinutes;
        int totalhours = totalminutes / 60;
        int remainingminutes = totalminutes % 60;

        cout << "Expected Time of Arrival: "
             << totalhours << ":" << remainingminutes << "\n";

        return totalminutes;
    }

    // Calculate ETA for all flights
    void calculateETA(Node* x) {

        if (x != nullptr) {

            calculateETA(x->left);

            cout << "\nFlight ID: " << x->flightID << "\n";

            int departure = timeToMinutes(x->departure_time);
            int eta = CalculateETA(x->departure_time, x->flight_duration);
            int scheduledArrival = timeToMinutes(x->arrival_time);

            if (scheduledArrival < departure) {
                scheduledArrival += 1440;
            }

            if (eta == scheduledArrival) {
                cout << "Result: On-Time\n";
            }
            else if (eta < scheduledArrival) {
                cout << "Result: Early\n";
            }
            else {
                cout << "Result: Delayed\n";
            }

            calculateETA(x->right);
        }
    }

    void calculateETA() {

        if (root == nullptr) {
            cout << "No flights available.\n";
            return;
        }

        calculateETA(root);
    }

    // Find cheapest flight
    Node* findCheapest(Node* x) {

        if (x == nullptr) {
            return nullptr;
        }

        Node* cheapest = x;

        Node* leftCheapest = findCheapest(x->left);
        Node* rightCheapest = findCheapest(x->right);

        if (leftCheapest != nullptr &&
            leftCheapest->ticketPrice < cheapest->ticketPrice) {

            cheapest = leftCheapest;
        }

        if (rightCheapest != nullptr &&
            rightCheapest->ticketPrice < cheapest->ticketPrice) {

            cheapest = rightCheapest;
        }

        return cheapest;
    }

    void cheapestFlight() {

        if (root == nullptr) {
            cout << "No flights available.\n";
            return;
        }

        Node* cheapest = findCheapest(root);

        cout << "\nCheapest Flight:\n";

        displayFlight(cheapest);
    }

    // Save flights using inorder traversal
    void saveInorder(Node* x, ofstream& file) {

        if (x != nullptr) {

            saveInorder(x->left, file);

            file << x->flightID << ","
                 << x->source << ","
                 << x->destination << ","
                 << x->airline << ","
                 << x->departure_time << ","
                 << x->arrival_time << ","
                 << x->flight_duration << ","
                 << x->ticketPrice << ","
                 << x->status << "\n";

            saveInorder(x->right, file);
        }
    }

    // Save flights to file
    void saveFlights() {

        ofstream file("flights.txt");

        if (!file) {
            cout << "Error opening file for saving.\n";
            return;
        }

        saveInorder(root, file);

        file.close();

        cout << "Flights saved successfully.\n";
    }

    // Load flights from file
    void loadFlights() {

        ifstream file("flights.txt");

        if (!file) {
            cout << "Error opening flights.txt.\n";
            return;
        }

        string line;
        int count = 0;

        while (getline(file, line)) {

            stringstream ss(line);

            string id, source, destination, airline;
            string departure, arrival, duration, price, status;

            getline(ss, id, ',');
            getline(ss, source, ',');
            getline(ss, destination, ',');
            getline(ss, airline, ',');
            getline(ss, departure, ',');
            getline(ss, arrival, ',');
            getline(ss, duration, ',');
            getline(ss, price, ',');
            getline(ss, status);

            // Skip incomplete records
            if (id.empty() || source.empty() || destination.empty() ||
                airline.empty() || departure.empty() || arrival.empty() ||
                duration.empty() || price.empty() || status.empty()) {

                cout << "Invalid record skipped.\n";
                continue;
            }

            try {

                int flightID = stoi(id);
                double flightDuration = stod(duration);
                int ticketPrice = stoi(price);

                // Prevent duplicate IDs
                if (search(flightID) == nullptr) {

                    insert(flightID, source, destination, airline,
                           departure, arrival, flightDuration,
                           ticketPrice, status, false);

                    count++;
                }
                else {

                    cout << "Duplicate Flight ID skipped: "
                         << flightID << "\n";
                }
            }
            catch (...) {

                cout << "Invalid record skipped.\n";
            }
        }

        file.close();

        cout << count << " new flights loaded successfully.\n";
    }
};

// Main function
int main() {

    BST tree;

    int choice;
    int id;

    string source, destination, airline;
    string departure, arrival, status;

    double duration;
    int price;

    // Automatically load saved flights when program starts
    tree.loadFlights();

    do {

        cout << "\n========== FLIGHT MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add new Flight\n";
        cout << "2. Search Flight by ID\n";
        cout << "3. Delete Flight by ID\n";
        cout << "4. Display All Flights (Ascending Flight ID)\n";
        cout << "5. Calculate flight duration and ETA\n";
        cout << "6. Cheapest Flight\n";
        cout << "7. Save Flights to File\n";
        cout << "8. Load Flights from File\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter Flight ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Source: ";
            getline(cin, source);

            cout << "Enter Destination: ";
            getline(cin, destination);

            cout << "Enter Airline: ";
            getline(cin, airline);

            cout << "Enter Departure Time (HH:MM): ";
            getline(cin, departure);

            cout << "Enter Arrival Time (HH:MM): ";
            getline(cin, arrival);

            cout << "Enter Flight Duration in hours (e.g. 1.75): ";
            cin >> duration;

            cout << "Enter Ticket Price: ";
            cin >> price;

            cin.ignore();

            cout << "Enter Status: ";
            getline(cin, status);

            tree.insert(id, source, destination, airline,
                        departure, arrival, duration,
                        price, status);

            tree.saveFlights();

            break;

        case 2:

            cout << "Enter Flight ID to search: ";
            cin >> id;

            {
                Node* result = tree.search(id);

                if (result != nullptr) {

                    cout << "\nFlight found:\n";

                    tree.displayFlight(result);
                }
                else {
                    cout << "Flight not found.\n";
                }
            }

            break;

        case 3:

            cout << "Enter Flight ID to delete: ";
            cin >> id;

            tree.deleteNode(id);

            tree.saveFlights();

            break;

        case 4:

            tree.display();

            break;

        case 5:

            tree.calculateETA();

            break;

        case 6:

            tree.cheapestFlight();

            break;

        case 7:

            tree.saveFlights();

            break;

        case 8:

            tree.loadFlights();

            break;

        case 0:

            tree.saveFlights();

            cout << "Exiting Flight Management System...\n";

            break;

        default:

            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
