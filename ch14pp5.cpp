#include <iostream>
#include <vector>

using namespace std;

void createBoard(vector<vector<char>> board, int height, int width);
bool checkValidMove(vector<vector<char>> &board, int height, int userInput);
void updateBoard(vector<vector<char>> &board, int height, int userInput,
                 int width);
bool checkWin(vector<vector<char>> &board);

int main() {
  vector<vector<char>> board;
  int height, width, userInput, turn;
  cout << " ^-^ Welcome to my Version of the game Connect-4 ^-^ \n";
  cout << "P1 is + and P2 is x, Please input the height and width of the game "
          "you guys want to create, it has to be a minimum of 4x4 obviously \n";
  cin >> height >> width;
  while (height <= 4 || width <= 4) {
    cout << "That is an invalid height or width, please create a board that is "
            "atleast 4x4 \n";
    cin >> height >> width;
  }
  turn = 0;
  while (checkWin(vector<vector<char>> & board) = false) {
    createBoard(board, height, width);
    cout << "P1 please make ur move, write the number where you want to place "
            "ur "
            "symbol \n";
    cin >> userInput;
    while (checkValidMove(userInput, height, vector<vector<char>> board))
      = false {
        cout << "That was an invalid move, your input has to be a number "
                "between "
                "1 "
                "and the width of the game \n";
        cin >> userInput;
      }
    updateBoard(userInput, height, width, vector<vector<char>> board);
    checkWin_X();
    cout << "P2 please make ur move, write the number where you want to place "
            "ur "
            "symbol \n";
    while (checkValidMove(userInput, height, vector<vector<char>> board))
      = false {
        cout << "That was an invalid move, your input has to be a number "
                "between "
                "1 "
                "and the width of the game \n";
        cin >> userInput;
      }
    updateBoard(userInput, height, width, vector<vector<char>> board);
    checkWin_Y();
  }
}

void createBoard(vector<vector<char>> &board, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      board[i][j] = '_';
    }
  }
  cout << vector<vector<char>> & board;
}

bool checkValidMove(vector<vector<char>> &board, int height, int userInput) {
  for (int i = height; i >= 0; i--) {
    if (board[height][userInput] == '_') {
      return true;
    }
  }
  return false;
}

void updateBoard(vector<vector<char>> &board, int height, int userInput,
                 int width) {
  for (int i = height; i >= 0; i--) {
    if (board[height][userInput] == '_' && turn % 2 == 0) {
      board[height][userInput] = '+';
    }
    if (board[height][userInput] == '_' && turn % 2 == 1) {
      board[height][userInput] = 'x';
    }
  }
}

bool checkWin_X(vector<vector<char>> &board, int width, int height) {
  for (int i = 0; i < height; i++) {
    bool win = false;
    for (int j = 3; j < width; j++) {
      if (board[i][j] == 'x' && board[i][j - 1] == 'x' &&
          board[i][j - 2] == 'x' && board[i][j - 3] == 'x') {
        win = true;
      }
    }
    if (win == true) {
      cout << "Congratulations P2 you won the game!\n";
      return 0;
    }
  }
  for (int i = 3; i < height; i++) {
    bool win = false;
    for (int j = 0; j < width; j++) {
      if (board[i][j] == 'x' && board[i - 1][j] == 'x' &&
          board[i - 2][j] == 'x' && board[i - 3][j] == 'x') {
        win = true;
      }
    }
    if (win == true) {
      cout << "Congratulations P2 you won the game!\n";
      return 0;
    }
  }
}
bool checkWin_Y(vector<vector<char>> &board, int width, int height) {
  for (int i = 0; i < height; i++) {
    bool win = false;
    for (int j = 3; j < width; j++) {
      if (board[i][j] == '+' && board[i][j - 1] == '+' &&
          board[i][j - 2] == '+' && board[i][j - 3] == '+') {
        win = true;
      }
    }
    if (win == true) {
      cout << "Congratulations P1 you won the game!\n";
      return 0;
    }
  }
  for (int i = 3; i < height; i++) {
    bool win = false;
    for (int j = 0; j < width; j++) {
      if (board[i][j] == '+' && board[i - 1][j] == '+' &&
          board[i - 2][j] == '+' && board[i - 3][j] == '+') {
        win = true;
      }
    }
    if (win == true) {
      cout << "Congratulations P1 you won the game!\n";
      return 0;
    }
  }
}
