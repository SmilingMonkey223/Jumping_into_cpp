#include <iostream>

using namespace std;

void Display_Board(char spaces[]);
bool Check_Winner(char spaces[], char player);
bool Check_Gameover(char spaces[]);
bool Check_Player_move_is_valid(int input, char spaces[]);
int Player_move();
void Game_State(char spaces[], bool& game_over, bool& tie);

char spaces[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int turn = 0;

int main() {
    bool game_over = false;
    bool tie = false;
    cout << "Let's play a game of Tic-Tac-Toe!\n";
    cout << "First Player is X, Second is O\n";
    cout << "The game will end when someone has won or no winner can be concluded from the game. Have fun!\n";

    while (!game_over) {
        Display_Board(spaces);
        int input = Player_move();
        if (Check_Player_move_is_valid(input, spaces)) {
            turn++;
            Game_State(spaces, game_over, tie);
        }
    }

    if (tie) {
        cout << "The game has concluded in a tie. Well played!\n";
    } else {
        if (turn % 2 == 0) {
            cout << "Congratulations! Player O wins!\n";
        } else {
            cout << "Congratulations! Player X wins!\n";
        }
    }

    return 0;
}

void Display_Board(char spaces[]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "|_" << spaces[i * 3 + j] << "_|";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool Check_Winner(char spaces[], char player) {
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };

    for (int i = 0; i < 8; i++) {
        if (spaces[wins[i][0]] == player && spaces[wins[i][1]] == player && spaces[wins[i][2]] == player) {
            return true;
        }
    }

    return false;
}

bool Check_Gameover(char spaces[]) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    return true;
}

bool Check_Player_move_is_valid(int input, char spaces[]) {
    if (input < 1 || input > 9) {
        cout << "Invalid input. Please enter a number between 1 and 9.\n";
        return false;
    }

    if (spaces[input - 1] == ' ') {
        spaces[input - 1] = (turn % 2 == 0) ? 'X' : 'O';
        return true;
    } else {
        cout << "This space is already occupied. Please choose another.\n";
        return false;
    }
}

int Player_move() {
    int input;
    cout << "Player " << ((turn % 2 == 0) ? "X" : "O") << ", enter the number of the position where you want to place your symbol: ";
    cin >> input;
    return input;
}

void Game_State(char spaces[], bool& game_over, bool& tie) {
    if (Check_Winner(spaces, 'X')) {
        game_over = true;
    } else if (Check_Winner(spaces, 'O')) {
        game_over = true;
    } else if (Check_Gameover(spaces)) {
        game_over = true;
        tie = true;
    }
}

