#include <iostream>
#include <vector>

using namespace std;

void BoardInit(vector<vector<char>> &board, int height, int width);
bool checkValidMove();
void updateBoard();

int main() {
  vector<vector<char>> board;
  int height, width;
  cout << " ^-^ Welcome to my Version of the game Connect-4 ^-^ \n";
  cout << "P1 is + and P2 is x, Please input the height and width of the game "
          "you guys want to create, it has to be a minimum of 4x4 obviously \n";
  while (height < 4 && width < 4) {
    cin >> height >> width;
  }
  BoardInit(vector<vector<char>> board, height, width);
  cout << "P1 please make ur move, write the number where you want to place ur "
          "symbol \n";
  if (checkValidMove = true) {
    updateBoard();
  } else {
    cout << "That was an invalid move, cant play like this \n";
  }
}

void BoardInit(vector<vector<char>> &board, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      board[i][j] = '_';
    }
  }
  cout << vector<vector<char>> & board;
}
