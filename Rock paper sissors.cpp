#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Generate computer move
char getComputerMove() {
    int move = rand() % 3;

    if (move == 0) return 'r';
    if (move == 1) return 'p';
    return 's';
}

// Determine result
int getResults(char player, char computer) {

    if (player == computer)
        return 0; // Draw

    if ((player == 'r' && computer == 's') ||
        (player == 'p' && computer == 'r') ||
        (player == 's' && computer == 'p'))
        return 1; // Player wins

    return -1; // Computer wins
}

// Convert move to readable format
string getMoveName(char move) {
    if (move == 'r') return "Rock";
    if (move == 'p') return "Paper";
    return "Scissors";
}

// Validate user input
char getPlayerMove() {

    char move;

    while (true) {
        cout << "Enter your move (R/P/S): ";
        cin >> move;

        move = tolower(move);

        if (move == 'r' || move == 'p' || move == 's')
            return move;

        cout << "Invalid input! Please try again.\n";
    }
}

int main() {

    srand(time(0)); // Seed random generator

    char choice;

    cout << "\n===== ROCK PAPER SCISSORS GAME =====\n";

    do {

        char playerMove = getPlayerMove();
        char computerMove = getComputerMove();

        int result = getResults(playerMove, computerMove);

        cout << "\nYour Move     : " << getMoveName(playerMove);
        cout << "\nComputer Move : " << getMoveName(computerMove);

        if (result == 0)
            cout << "\nResult        : Draw!";
        else if (result == 1)
            cout << "\nResult        : You Win!";
        else
            cout << "\nResult        : Computer Wins!";

        cout << "\n\nPlay again? (Y/N): ";
        cin >> choice;

    } while (tolower(choice) == 'y');

    cout << "\nThank you for playing!\n";

    return 0;
}

