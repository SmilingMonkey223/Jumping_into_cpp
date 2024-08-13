#include <iostream>
#include <vector>

using namespace std;

void createBoard(int height, int width);
void currentBoard(int height, int width);
void updateBoard(int height, int width, int userInput);
void checkValidInput();

int main() {
  int height, width, userInput, turn, max_moves;
  vector<int[]> board;
  cout << "welcome to my version of connect-4 \n";
  cout << "You will first have to create a board, please put in a number for "
          "the height of the game, and after that a number for the width \n";
  cin >> height >> width;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      board[i][j] = '_';
    }
  }

  max_moves = height * width;
  turn = 0;
  while (max_moves >= 0) {
    if (turn % 2 == 0) {
      cout << "P1 it is your turn, please put in a number from 1 up to the "
              "specified width of your game \n";
      cin >> userInput;
      if (checkValidInput) {
        updateBoard(height, width, userInput);
        turn++;
        max_moves--;
      } else {
        cout << "This move was not valid, try another \n";
      }
      currentBoard(height, width);
    } else {
      cout << "P2 it is your turn, please put in a number from 1 up to the "
              "specified width of your game \n";
      cin >> userInput;
      if (checkValidInput) {
        updateBoard(height, width, userInput);
        turn++;
        max_moves--;
      } else {
        cout << "This move was not valid, try another \n";
      }
      currentBoard(height, width);
    }
  }
}

void updateBoard(char board[][width], int row, int col, char token, int turn) {
  board[row][col] = token;
}

void currentBoard(char board[][width], int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool checkValidInput(char board[][width], int height, int width,
                     int userInput) {
  if (userInput > 0 && userInput <= width) {
    if (board[0][userInput] == '_') {
      return true;
    } else {
      return false;
    }
  }
}
