#include <iostream>

using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin() {
    const int winPositions[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
        {1, 5, 9}, {3, 5, 7}  // Diagonals
    };

    for (auto &pos : winPositions) {
        if (square[pos[0]] == square[pos[1]] && square[pos[1]] == square[pos[2]]) {
            return 1;
        }
    }

    for (int i = 1; i <= 9; ++i) {
        if (square[i] != 'X' && square[i] != 'O') {
            return -1;
        }
    }

    return 0;
}

void drawBoard() {
    cout << "\n\n\tTic Tac Toe Game\n\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";
    for (int i = 1; i <= 9; i += 3) {
        cout << "  " << square[i] << "  |  " << square[i + 1] << "  |  " << square[i + 2] << "  \n";
        if (i < 7) cout << "_____|_____|_____\n";
        else cout << "     |     |     \n";
    }
}

int main() {
    int player = 1, i, choice;
    char mark;

    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
            square[choice] = mark;
        } else {
            cout << "Invalid move\n";
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();
        player++;
    } while (i == -1);

    drawBoard();
    if (i == 1) {
        cout << "\aCongratulations! Player " << --player << " wins!\n";
    } else {
        cout << "\aGame draw!\n";
    }

    cin.ignore();
    cin.get();
    return 0;
}
