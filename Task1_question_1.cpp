#include <iostream>
using namespace std;

class Temperature {
private:
    float ip; // Input temperature
    float op; // Output temperature
    int ch;   // User choice

public:
    // Function to display the menu and get user choice
    void getMenu() {
        cout << "1. Celsius to Fahrenheit" << endl
             << "2. Fahrenheit to Celsius" << endl
             << "Enter your choice: ";
        cin >> ch;
    }

    // Function to get the temperature input
    void getData() {
        cout << "Enter temperature to be converted: ";
        cin >> ip;
    }

    // Function to convert Celsius to Fahrenheit
    void convert2F() {
        op = 1.8 * ip + 32; // Formula: F = (9/5) * C + 32
    }

    // Function to convert Fahrenheit to Celsius
    void convert2C() {
        op = (ip - 32) * 5 / 9; // Formula: C = (F - 32) * (5/9)
    }

    // Function to decide which conversion to perform
    void decide() {
        if (ch == 1) {
            convert2F(); // Convert Celsius to Fahrenheit
        } else if (ch == 2) {
            convert2C(); // Convert Fahrenheit to Celsius
        } else {
            cout << "Invalid choice! Please enter 1 or 2." << endl;
            getMenu(); // Re-prompt for choice
            getData(); // Re-prompt for temperature input
            decide();  // Re-decide based on new input
        }
    }

    // Function to display the converted temperature
    void display() {
        cout << "The converted temperature is: " << op << endl;
    }
};

int main() {
    Temperature T1;

    // Get user choice
    T1.getMenu();

    // Get temperature input
    T1.getData();

    // Perform conversion
    T1.decide();

    // Display the result
    T1.display();

    return 0;
}
