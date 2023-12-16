#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
    cout << endl << "\t\t\t\t⭐ Welcome to the Number Guessing Game ⭐" << endl;
    cout << endl << "\t\t\t\t🔍 You will have to guess a number between 1 to 100. 🔍" << endl;
    cout << endl << "\t\t\t\t🌟 Let's start playing and Best of Luck. 🌟" << endl;

    srand(time(0));
    int secretNumber = (rand() % 100) + 1;

    cout << endl << "^^** You will have a total of 5 chances to guess the correct number. **^^" << endl;
    int chancesLeft = 5;
    int playerGuess;

    for (int i = 1; i <= 5; i++) {
        cout << endl << "👉 Enter your guess: ";
        cin >> playerGuess;

        if (playerGuess == secretNumber) {
            cout << endl << "🎉 Congratulations! You have successfully guessed the right number. 🎉" << endl;
            cout << endl << "👏 Thanks for playing. Have a nice day! 👏" << endl;
            break;
        } else {
            if (playerGuess > secretNumber) {
                cout << endl << "⬇️ Insert a smaller number. Try again. ⬇️" << endl;
            } else {
                cout << endl << "⬆️ Insert a larger number. Try again. ⬆️" << endl;
            }
        }

        chancesLeft--;
        cout << endl << "🔢 Chances left to guess the random number: " << chancesLeft << endl;

        if (chancesLeft == 0) {
            cout << endl << " Sorry, your chances have run out to guess the random number. " << endl;
            cout << "💡 The random number was: " << secretNumber << " 💡" << endl;
            cout << "👋 Thanks for playing. Have a nice day. 👋" << endl;
        }
    }

    cout << endl;
    return 0;
}
