#include <iostream>

using namespace std;

void createBoard(char **board, int height, int width);
void updateBoard(char **board, int height, int width);
bool PlayerMoveValid(char **board, int playerMove, int height, int width);
void checkWin(char **board);

int main() {
  int height, width, draw, playerMove, turn = 0;
  cout << "Welcome to my version of a Connect-4 *-*\n";
  cout << "Player 1 will be the symbol '+' and Player 2 'x' \n";
  cout << "You will first choose what size the board is, please first input a "
          "height and after that a width \n";
  cout << "The board can be a minimum of 4x4 \n";
  cin >> height >> width;
  draw = width * height;
  while (height < 5 || width < 5) {
    cout << "invalid board size, got to be atleast 4x4.... \n";
    cout << "Please input another height and width \n";
    cin >> height >> width;
  }
  char **board = new char *[height];
  createBoard(int height, int width);
  cout << "Alright, write down the width (as a number) where you want to "
          "make ur move \n";
  while (turn <= draw) {
    cout << "P1 turn \n";
    cin >> playerMove;
    while (!PlayerMoveValid) {
      cout << "That was an invalid move, ur supposed to write a number between "
              "1 "
              "and the width you specified for the board, try again \n";
      cin >> playerMove;
    }
    updateBoard(int height, int width);
    checkWin();
    turn++;
    cout << "P2 turn \n";
    cin >> playerMove;
    while (!PlayerMoveValid) {
      cout << "That was an invalid move, ur supposed to write a number between "
              "1 "
              "and the width you specified for the board, try again \n";
      cin >> playerMove;
    }
    updateBoard(int height, int width);
    checkWin();
    turn++;
  }
  cout << "the game has concluded without a winner, hope you enjoyed playing";
  return 0;
}

void createBoard(char **board, int height, int width) {
  for (int i = 0; i < height; i++) {
    board[i] = new char[width];
    for (int j = 0; j < width; j++) {
      board[i][j] = '_';
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

void updateBoard(char **board, int height, int width) {}

bool PlayerMoveValid(char **board, int playerMove, int height, int width) {
  for (int i = height; i > 0; i--) {
    if (board[i] = "_") {
      return true;
    }
  }
  return false;
}
