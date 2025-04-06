#include <iostream>
using namespace std;

class DayOfWeek {
private:
    int day;

public:
    // Function to input the day number
    void inputNumDay() {
        cout << "Enter any number between 1 to 7: ";
        cin >> day;
    }

    // Function to display the corresponding day of the week
    void displayDay() {
        if (day == 1) {
            cout << "Sunday" << endl;
        } else if (day == 2) {
            cout << "Monday" << endl;
        } else if (day == 3) {
            cout << "Tuesday" << endl;
        } else if (day == 4) {
            cout << "Wednesday" << endl;
        } else if (day == 5) {
            cout << "Thursday" << endl;
        } else if (day == 6) {
            cout << "Friday" << endl;
        } else if (day == 7) {
            cout << "Saturday" << endl;
        } else {
            cout << "Enter valid number!!" << endl;
        }
    }
};

int main() {
    DayOfWeek day;

    // Input the day number
    day.inputNumDay();

    // Display the corresponding day of the week
    day.displayDay();

    return 0;
}
