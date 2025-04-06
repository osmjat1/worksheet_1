#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

class NumberGuessingGame {
private:
    int difficultyLevel;
    int secretNumber;
    int maxRange;

public:
    // Constructor to initialize the game
    NumberGuessingGame() {
        difficultyLevel = 0;
        secretNumber = 0;
        maxRange = 0;
    }

    // Function to set the difficulty level
    void setDifficulty() {
        cout << "Choose difficulty level:" << endl;
        cout << "1. Easy (1-8)" << endl;
        cout << "2. Medium (1-30)" << endl;
        cout << "3. Hard (1-50)" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> difficultyLevel;

        // Set the maximum range based on difficulty
        switch (difficultyLevel) {
            case 1:
                maxRange = 8;
                break;
            case 2:
                maxRange = 30;
                break;
            case 3:
                maxRange = 50;
                break;
            default:
                cout << "Invalid choice! Defaulting to Easy difficulty." << endl;
                maxRange = 8;
                difficultyLevel = 1;
                break;
        }

        // Generate a random number within the selected range
        srand(time(0)); // Seed the random number generator
        secretNumber = rand() % maxRange + 1;
    }

    // Function to play the game
    void playGame() {
        int guess;
        int attempts = 0;
        bool guessedCorrectly = false;

        cout << "Guess the number between 1 and " << maxRange << "!" << endl;

        while (!guessedCorrectly) {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess == secretNumber) {
                cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
                guessedCorrectly = true;
            } else if (guess < secretNumber) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Too high! Try again." << endl;
            }
        }
    }
};

int main() {
    NumberGuessingGame game;

    // Set the difficulty level
    game.setDifficulty();

    // Play the game
    game.playGame();

    return 0;
}
