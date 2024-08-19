#include <iostream>
#include <vector>

using namespace std;

void createBoard(vector<vector<char>> &board, int height, int width);
bool checkValidMove(vector<vector<char>> &board, int height, int userInput);
void updateBoard(vector<vector<char>> &board, int height, int width,
                 int userInput);

int main() {
  vector<vector<char>> board;
  int height, width, userInput;
  cout << " ^-^ Welcome to my Version of the game Connect-4 ^-^ \n";
  cout << "P1 is + and P2 is x, Please input the height and width of the game "
          "you guys want to create, it has to be a minimum of 4x4 obviously \n";
  while (height <= 4 && width <= 4) {
    cin >> height >> width;
  }

  createBoard(vector<vector<char>> board, height, width);
  cout << "P1 please make ur move, write the number where you want to place ur "
          "symbol \n";
  cin >> userInput;
  while (checkValidMove(userInput) = false) {
    cout << "That was an invalid move, input a number that is between 1 and "
            "the width you used to determine the game size \n";
    cin >> userInput;
  }
  updateBoard();
}

void createBoard(vector<vector<char>> &board, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      board[i][j] = '_';
    }
  }
  cout << vector<vector<char>> & board;
}

bool checkValidMove(vector<vector<char>> &board, int userInput, int height) {
  for (int i = height; i <= 0; i--) {
    if (board[i][userInput] == '_') {
      return true;
    }
  }
  return false;
}

void updateBoard()
