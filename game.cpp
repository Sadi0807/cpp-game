#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    char playAgain;

    do {
        int difficulty, maxNum, maxAttempts;
        
        cout << "Choose difficulty:\n1. Easy (1-50)\n2. Medium (1-100)\n3. Hard (1-500)\n";
        cin >> difficulty;

        if (difficulty == 1) maxNum = 50;
        else if (difficulty == 2) maxNum = 100;
        else maxNum = 500;

        maxAttempts = 7;
        int secret = rand() % maxNum + 1;
        int guess, attempts = 0;

        cout << "Guess a number between 1 and " << maxNum << endl;

        while (attempts < maxAttempts) {
            cout << "Attempt " << attempts + 1 << "/" << maxAttempts << ": ";
            cin >> guess;
            attempts++;

            if (guess == secret) {
                int score = (maxAttempts - attempts + 1) * 10;
                cout << "Correct! Score: " << score << endl;
                break;
            } else if (guess > secret) {
                cout << "Too high!\n";
            } else {
                cout << "Too low!\n";
            }

            // Hint system
            if (secret % 2 == 0) cout << "Hint: Even number\n";
            else cout << "Hint: Odd number\n";
        }

        if (guess != secret) {
            cout << "You lost! The number was " << secret << endl;
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
