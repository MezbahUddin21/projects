#include <bits/stdc++.h>
using namespace std;

struct TravelBooking {
    int uniqueID;
    string travelerName;
    string startPlace;
    string destination;
    double cost;
};

class TravelManagementSystem {
private:
    vector<TravelBooking> bookings;
    int nextUniqueID = 1;

public:
    void addBooking(const TravelBooking& booking) {
        TravelBooking newBooking = booking;
        newBooking.uniqueID = nextUniqueID++;
        bookings.push_back(newBooking);
        cout << "Booking added successfully. Unique ID: " << newBooking.uniqueID << endl;
    }

    void displayBookings() const {
        if (bookings.empty()) {
            cout << "No bookings available." << endl;
            return;
        }

        cout << setw(5) << "ID" << setw(20) << "Traveler Name" << setw(20) << "Destination" << setw(10) << "Cost" << endl;
        cout << "----- -------------------- -------------------- ----------" << endl;

        for (const auto& booking : bookings) {
            cout << setw(5) << booking.uniqueID << setw(20) << booking.travelerName << setw(20) << booking.destination << setw(10) << booking.cost << endl;
        }
    }

    void searchBookingByID(int uniqueID) const {
        auto it = find_if(bookings.begin(), bookings.end(), [uniqueID](const TravelBooking& booking) {
            return booking.uniqueID == uniqueID;
            });

        if (it != bookings.end()) {
            cout << "Booking found. Details:" << endl;
            cout << "Traveler Name: " << it->travelerName << endl;
            cout << "Destination: " << it->destination << endl;
            cout << "Cost: " << it->cost << endl;
        }
        else {
            cout << "No booking found with the given ID." << endl;
        }
    }

    void editBooking(int uniqueID, const TravelBooking& newBooking) {
        auto it = find_if(bookings.begin(), bookings.end(), [uniqueID](TravelBooking& booking) {
            return booking.uniqueID == uniqueID;
            });

        if (it != bookings.end()) {
            *it = newBooking;
            cout << "Booking edited successfully." << endl;
        }
        else {
            cout << "No booking found with the given ID. No booking edited." << endl;
        }
    }

    void deleteBooking(int uniqueID) {
        auto it = find_if(bookings.begin(), bookings.end(), [uniqueID](const TravelBooking& booking) {
            return booking.uniqueID == uniqueID;
            });

        if (it != bookings.end()) {
            bookings.erase(it);
            cout << "Booking deleted successfully." << endl;
        }
        else {
            cout << "No booking found with the given ID. No booking deleted." << endl;
        }
    }
};

int main() {
    TravelManagementSystem travelSystem;

    while (true) {
        cout << "\n1. Add Booking\n2. Display Bookings\n3. Search Booking by ID\n4. Edit Booking\n5. Delete Booking\n6. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            TravelBooking newBooking;
            cout << "Enter traveler name: ";
            cin >> newBooking.travelerName;
            cout << "Enter destination: ";
            cin >> newBooking.destination;
            cout << "Enter cost: ";
            cin >> newBooking.cost;
            travelSystem.addBooking(newBooking);
            break;
        }
        case 2:
            travelSystem.displayBookings();
            break;
        case 3: {
            int searchID;
            cout << "Enter the unique ID to search: ";
            cin >> searchID;
            travelSystem.searchBookingByID(searchID);
            break;
        }
        case 4: {
            int editID;
            cout << "Enter the unique ID of the booking to edit: ";
            cin >> editID;

            TravelBooking newBooking;
            cout << "Enter new traveler name: ";
            cin >> newBooking.travelerName;
            cout << "Enter new destination: ";
            cin >> newBooking.destination;
            cout << "Enter new cost: ";
            cin >> newBooking.cost;

            travelSystem.editBooking(editID, newBooking);
            break;
        }
        case 5: {
            int deleteID;
            cout << "Enter the unique ID of the booking to delete: ";
            cin >> deleteID;
            travelSystem.deleteBooking(deleteID);
            break;
        }
        case 6:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please choose a valid option.\n";
        }
    }

    return 0;
}
