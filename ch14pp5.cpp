#include <iostream>
#include <vector>

using namespace std;

void createBoard(vector<vector<char>> &board, int height, int width);
bool checkValidMove(vector<vector<char>> &board, int height, int userInput);
void updateBoard(vector<vector<char>> &board, int height, int userInput,
                 int width, int turn);
bool checkWin(vector<vector<char>> &board, int height, int width);

int main() {
  vector<vector<char>> board;
  int height, width, userInput, gameover, turn = 0;
  cout << " ^-^ Welcome to my Version of the game Connect-4 ^-^ \n";
  cout
      << "P1 is + and P2 is x, Please input the height and width of the game "
         "you guys want to create, it has to be a minimum of 4x4 obviously: \n";
  cin >> height >> width;
  while (height < 4 || width < 4) {
    cout << "That is an invalid height or width, please create a board that "
            "is "
            "atleast 4x4 \n";
    cin >> height >> width;
  }

  createBoard(board, height, width);

  while (!checkWin(board, height, width)) {
    cout << "Player " << (turn % 2 == 0 ? "1" : "2") << " its your turn: ";
    cin >> userInput;
    while (!checkValidMove(board, height, userInput)) {
      cout << "That was an invalid move, your input has to be a number "
              "between "
              "1 "
              "and the width of the game \n";
      cin >> userInput;
    }
    updateBoard(board, height, userInput, width, turn);
    turn++;
    gameover = width * height;
    if (turn >= gameover) {
      cout << "it seems no one more space is left and no one has won the game "
              "\n";
      return 0;
    }
  }
}

void createBoard(vector<vector<char>> &board, int height, int width) {
  board.resize(height, vector<char>(width, '_'));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      board[i][j] = '_';
      cout << board[i][j] << '|';
    }
    cout << endl;
  }
}

bool checkValidMove(vector<vector<char>> &board, int height, int userInput) {
  for (int i = height - 1; i >= 0; i--) {
    if (board[i][userInput - 1] == '_') {
      return true;
    }
  }
  return false;
}

void updateBoard(vector<vector<char>> &board, int height, int userInput,
                 int width, int turn) {
  for (int i = height - 1; i >= 0; i--) {
    if (board[i][userInput - 1] == '_') {
      if (turn % 2 == 0) {
        board[i][userInput - 1] = '+';
        break;
      }
      if (turn % 2 == 1) {
        board[i][userInput - 1] = 'x';
        break;
      }
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << board[i][j] << '|';
    }
    cout << endl;
  }
}
bool checkWin(vector<vector<char>> &board, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 3; j < width; j++) {
      if (board[i][j] == 'x' && board[i][j - 1] == 'x' &&
          board[i][j - 2] == 'x' && board[i][j - 3] == 'x') {
        cout << "Congratulations P2 you won the game!\n";
        return true;
      }
    }
  }

  for (int i = 3; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (board[i][j] == 'x' && board[i - 1][j] == 'x' &&
          board[i - 2][j] == 'x' && board[i - 3][j] == 'x') {
        cout << "Congratulations P2 you won the game!\n";
        return true;
      }
    }
  }

  for (int i = 3; i < height; i++) {
    for (int j = 3; j < width; j++) {
      if (board[i][j] == 'x' && board[i - 1][j - 1] == 'x' &&
          board[i - 2][j - 2] == 'x' && board[i - 3][j - 3] == 'x') {
        cout << "Congratulations P2 you won the game!\n";
        return true;
      }
    }
  }

  for (int i = 0; i <= height - 4; i++) {
    for (int j = 3; j < width; j++) {
      if (board[i][j] == 'x' && board[i + 1][j - 1] == 'x' &&
          board[i + 2][j - 2] == 'x' && board[i + 3][j - 3] == 'x') {
        cout << "Congratulations P2 you won the game!\n";
        return true;
      }
    }
  }

  return false;
}
