#include <bits/stdc++.h>
using namespace std;

// Constants
const int TOTAL_SEATS = 10;
long long nextPnr = 1500;

// Train Data
map<pair<string, string>, vector<int> > trainRoutes;  // (src, des) → trainNumbers
map<int, int> availableSeats;  // trainNumber → availableSeats
map<int, string> trainNames;   // trainNumber → trainName

// Classes
class Passenger {
public:
    string name;
    int age;
    char gender;
    long long contactNo;

    Passenger(string nm, int a, char gen, long long con) 
        : name(nm), age(a), gender(gen), contactNo(con) {}
};

class Train {
public:
    int trainNo;
    string trainName;
    string src, des;
    int availableSeats;

    Train(int num, string name, string source, string destination) 
        : trainNo(num), trainName(name), src(source), des(destination), availableSeats(TOTAL_SEATS) {}
};

class Ticket {
public:
    long long pnr;
    string passengerName;
    int trainNo;
    int seatNo;

    Ticket(long long p, string name, int train, int seat) 
        : pnr(p), passengerName(name), trainNo(train), seatNo(seat) {}
};

// Data Storage
vector<Passenger> passengers;
vector<Ticket> tickets;

// Function to check train availability
void checkAvailability() {
    cout << "Enter source: ";
    string src;
    cin >> src;
    cout << "Enter destination: ";
    string des;
    cin >> des;

    bool found = false;
    for (auto& route : trainRoutes) {
        if (route.first.first == src && route.first.second == des) {
            found = true;
            for (int trainNum : route.second) {
                if (availableSeats[trainNum] > 0) {
                    cout << "Train No: " << trainNum << "\n";
                    cout << "Train Name: " << trainNames[trainNum] << "\n";
                    cout << "Available Seats: " << availableSeats[trainNum] << "\n";
                }
            }
        }
    }

    if (!found) {
        cout << "No trains available between " << src << " and " << des << ".\n";
    } else {
        cout << "Availability check completed.\n";
    }
}

// Function to book a ticket
void bookTicket() {
    cout << "Enter Train Number: ";
    int trainNo;
    cin >> trainNo;

    if (availableSeats.find(trainNo) == availableSeats.end() || availableSeats[trainNo] <= 0) {
        cout << "Invalid train number or no seats available.\n";
        return;
    }

    // Get passenger details
    cout << "Enter Passenger Name: ";
    string name;
    cin >> name;
    cout << "Enter Age: ";
    int age;
    cin >> age;
    cout << "Enter Gender (M/F): ";
    char gender;
    cin >> gender;
    cout << "Enter Contact Number: ";
    long long contactNo;
    cin >> contactNo;

    // Create passenger and ticket
    passengers.emplace_back(name, age, gender, contactNo);
    int seatNo = TOTAL_SEATS - availableSeats[trainNo] + 1;
    tickets.emplace_back(nextPnr, name, trainNo, seatNo);

    cout << "Booking successful! PNR: " << nextPnr << "\n";
    availableSeats[trainNo]--;
    nextPnr++;
}

// Function to cancel a ticket
void cancelTicket() {
    cout << "Enter PNR Number: ";
    long long pnr;
    cin >> pnr;

    for (auto it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->pnr == pnr) {
            availableSeats[it->trainNo]++;
            tickets.erase(it);
            cout << "Ticket cancelled. Refund processed.\n";
            return;
        }
    }

    cout << "Invalid PNR number.\n";
}

// Function to check ticket status
void checkStatus() {
    cout << "Enter PNR Number: ";
    long long pnr;
    cin >> pnr;

    for (const auto& ticket : tickets) {
        if (ticket.pnr == pnr) {
            cout << "PNR No: " << ticket.pnr << "\n";
            cout << "Passenger Name: " << ticket.passengerName << "\n";
            cout << "Train No: " << ticket.trainNo << "\n";
            cout << "Seat No: " << ticket.seatNo << "\n";
            return;
        }
    }

    cout << "Invalid PNR number.\n";
}

// Main function
int main() {
    cout << "Welcome to the Train Ticket Booking System!\n";

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Check Train Availability\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. Check PNR Status\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                checkAvailability();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                checkStatus();
                break;
            case 5:
                cout << "Thank you for using the system!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
