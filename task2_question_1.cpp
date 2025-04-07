#include <iostream>
using namespace std;

class BouncyNumber {
private:
    int num; // Store the input number

public:
    // Function to get and validate user input
    void inputNumber() {
        cout << "Enter a positive integer: ";
        cin >> num;

        // Check if input is valid
        if (num <= 0) {
            cout << "Invalid input! Please enter a positive integer." << endl;
            exit(1); // Exit if input is not positive
        }
    }

    // Function to check if number is bouncy
    void checkBouncy() {
        // Numbers less than 100 can't be bouncy
        if (num < 100) {
            cout << num << " is NOT bouncy (less than 3 digits)." << endl;
            return;
        }

        int temp = num;           // Temporary variable for digit processing
        bool increasing = false;  // Flag for increasing pattern
        bool decreasing = false;  // Flag for decreasing pattern

        // Process digits from right to left
        while (temp > 9) {
            int lastDigit = temp % 10;         // Get rightmost digit
            int secondLastDigit = (temp / 10) % 10; // Get second-to-last digit

            // Compare adjacent digits
            if (lastDigit > secondLastDigit) {
                increasing = true;  // Found an increase
            }
            else if (lastDigit < secondLastDigit) {
                decreasing = true;  // Found a decrease
            }

            temp /= 10;  // Remove rightmost digit
        }

        // Determine and display result
        if (increasing && decreasing) {
            cout << num << " is a bouncy number (neither consistently increasing nor decreasing)." << endl;
        }
        else {
            cout << num << " is NOT bouncy." << endl;
            // Optional: Add reason for clarity
            if (!increasing && !decreasing) {
                cout << "(digits are equal)" << endl;
            }
            else if (increasing) {
                cout << "(digits consistently decrease)" << endl;
            }
            else {
                cout << "(digits consistently increase)" << endl;
            }
        }
    }
};

int main() {
    BouncyNumber bouncy;    // Create object
    bouncy.inputNumber();   // Get input
    bouncy.checkBouncy();   // Check if bouncy
    return 0;
}
