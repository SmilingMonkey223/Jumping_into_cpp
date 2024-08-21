#include <iostream>
#include <vector>

using namespace std;

void createBoard(vector<vector<char>> &board, int height, int width);
bool checkValidMove(vector<vector<char>> &board, int height, int userInput);
void updateBoard(vector<vector<char>> &board, int height, int userInput,
                 int width);

int main() {
  vector<vector<char>> board;
  int height, width, userInput, turn;
  cout << " ^-^ Welcome to my Version of the game Connect-4 ^-^ \n";
  cout << "P1 is + and P2 is x, Please input the height and width of the game "
          "you guys want to create, it has to be a minimum of 4x4 obviously \n";
  while (height <= 4 && width <= 4) {
    cin >> height >> width;
  }
  turn = 0;
  createBoard(vector<vector<char>> board, height, width);
  cout << "P1 please make ur move, write the number where you want to place ur "
          "symbol \n";
  cin >> userInput;
  while (checkValidMove(userInput, height, vector<vector<char>> board))
    = false {
      cout << "That was an invalid move, your input has to be a number between "
              "1 "
              "and the width of the game \n";
      cin >> userInput;
    }
  updateBoard(userInput, height, width, vector<vector<char>> board);
  cout << "P2 please make ur move, write the number where you want to place ur "
          "symbol \n";
  while (checkValidMove(userInput, height, vector<vector<char>> board))
    = false {
      cout << "That was an invalid move, your input has to be a number between "
              "1 "
              "and the width of the game \n";
      cin >> userInput;
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
    } else {
      board[height][userInput] = 'x';
    }
  }
}
