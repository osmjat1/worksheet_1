#include <iostream>
using namespace std;

class CinemaBookingSystem {
private:
    char seats[5][5]; // 5x5 seating arrangement

public:
    // Constructor to initialize all seats as available ('O')
    CinemaBookingSystem() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                seats[i][j] = 'O';
            }
        }
    }

    // Function to display the current seating arrangement
    void displaySeats() {
        cout << "Current Seating Arrangement:" << endl;
        cout << "  1 2 3 4 5" << endl; // Column numbers
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << " "; // Row number
            for (int j = 0; j < 5; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to book a seat
    void bookSeat(int row, int col) {
        // Check if row and column are valid
        if (row < 1 || row > 5 || col < 1 || col > 5) {
            cout << "Invalid row or column number! Please enter numbers between 1 and 5." << endl;
            return;
        }

        // Check if the seat is already booked
        if (seats[row - 1][col - 1] == 'X') {
            cout << "Seat is already booked! Please choose another seat." << endl;
            return;
        }

        // Book the seat
        seats[row - 1][col - 1] = 'X';
        cout << "Seat booked successfully!" << endl;
    }

    // Function to get seat number and handle multiple bookings
    void getSeatNumber() {
        char choice;
        do {
            int row, col;
            cout << "Enter row number (1-5): ";
            cin >> row;
            cout << "Enter column number (1-5): ";
            cin >> col;

            // Book the seat
            bookSeat(row, col);

            // Display the updated seating arrangement
            displaySeats();

            // Ask if the user wants to book another seat
            cout << "Do you want to book another seat? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        cout << "Thank you for using the Cinema Booking System!" << endl;
    }
};

int main() {
    CinemaBookingSystem cinema;

    // Display the initial seating arrangement
    cinema.displaySeats();

    // Get seat numbers and handle bookings
    cinema.getSeatNumber();

    return 0;
}

