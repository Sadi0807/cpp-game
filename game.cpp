#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getMaxAttempts(int difficulty) {
    if (difficulty == 1) return 10;
    if (difficulty == 2) return 7;
    return 5;
}

int getMaxNumber(int difficulty) {
    if (difficulty == 1) return 50;
    if (difficulty == 2) return 100;
    return 200;
}

void showMenu() {
    cout << "===========================\n";
    cout << "   GUESS THE NUMBER GAME   \n";
    cout << "===========================\n";
    cout << "1. Play Game\n";
    cout << "2. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    srand(time(0));

    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 2) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice != 1) {
            cout << "Invalid option.\n";
            continue;
        }

        int difficulty;
        cout << "\nSelect difficulty:\n";
        cout << "1. Easy (1-50, 10 attempts)\n";
        cout << "2. Medium (1-100, 7 attempts)\n";
        cout << "3. Hard (1-200, 5 attempts)\n";
        cout << "Choice: ";
        cin >> difficulty;

        int maxNumber = getMaxNumber(difficulty);
        int attempts = getMaxAttempts(difficulty);
        int secret = rand() % maxNumber + 1;

        int guess;
        int score = 0;
        bool won = false;

        int low = 1, high = maxNumber;

        cout << "\nI picked a number between " << low << " and " << high << ".\n";

        while (attempts > 0) {
            cout << "\nAttempts left: " << attempts << "\n";
            cout << "Enter guess: ";
            cin >> guess;

            attempts--;

            if (guess == secret) {
                cout << "Correct! You win!\n";
                score = attempts * 20 + 50;
                won = true;
                break;
            }

            // Range hint system
            if (guess < secret) {
                cout << "Too low!\n";
                if (guess > low) low = guess;
            } else {
                cout << "Too high!\n";
                if (guess < high) high = guess;
            }

            // Hot/Cold hint
            int diff = abs(secret - guess);
            if (diff <= 5) {
                cout << "🔥 Very hot!\n";
            } else if (diff <= 15) {
                cout << "🌡️ Warm\n";
            } else {
                cout << "🧊 Cold\n";
            }

            cout << "Hint range: " << low << " to " << high << "\n";
        }

        if (!won) {
            cout << "\nOut of attempts! The number was " << secret << ".\n";
            score = 0;
        }

        cout << "Final score: " << score << "\n\n";

    } while (true);

    return 0;
}
