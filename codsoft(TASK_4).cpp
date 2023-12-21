#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    bool bonusMoveAvailable;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X'), bonusMoveAvailable(true) {}

    char getCurrentPlayer() const {
        return currentPlayer;
    }

    void printBoard() const {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            return false;
        }

        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() const {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }

        return false;
    }

    bool checkTie() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;  // Empty space found, game is not a tie yet
                }
            }
        }
        return true;  // All spaces are filled, and no winner, so it's a tie
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void useBonusMove() {
        if (bonusMoveAvailable) {
            cout << "Bonus Move Activated for Player " << currentPlayer << "!" << endl;
            bonusMoveAvailable = false;
        } else {
            cout << "Bonus Move Already Used. No more bonus moves allowed." << endl;
        }
    }
};

int main() {
    TicTacToe game;

    int row, col;
    int bonusMoveChoice;

    cout << "Welcome to Unique Tic-Tac-Toe with Bonus Move Feature!" << endl;

    do {
        game.printBoard();

        cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row == -1 && col == -1) {
            game.useBonusMove();
        } else if (game.makeMove(row, col)) {
            if (game.checkWin()) {
                game.printBoard();
                cout << "Player " << game.getCurrentPlayer() << " wins! Congratulations!" << endl;
                break;
            } else if (game.checkTie()) {
                game.printBoard();
                cout << "It's a tie! Good game!" << endl;
                break;
            } else {
                game.switchPlayer();
            }
        }

    } while (true);

    return 0;
}
