#include <iostream>
using namespace std;

class ArraySorter {
private:
    int array[10]; // Array to store elements
    int size;      // Size of the array

public:
    // Function to input array size and elements
    void inputArray() {
        cout << "Enter size of the array (max 10): ";
        cin >> size;

        if (size > 10 || size <= 0) {
            cout << "Invalid size! Size must be between 1 and 10." << endl;
            return;
        }

        cout << "Enter array elements:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> array[i];
        }
    }

    // Function to sort the array using bubble sort
    void sortArray() {
        int temp;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (array[i] > array[j]) {
                    // Swap elements
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    // Function to display the sorted array
    void displayArray() {
        cout << "Sorted array in (Accending order):" << endl;
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArraySorter sorter;

    // Input array
    sorter.inputArray();

    // Sort array
    sorter.sortArray();

    // Display sorted array
    sorter.displayArray();

    return 0;
}
