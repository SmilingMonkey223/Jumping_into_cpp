#include <iostream>
#include <vector>

using namespace std;

void createBoard(vector<vector<int>> &board, int height, int width);
int checkValidMove(vector<vector<int>> &board, int playerMove, int height);
void updateBoard(vector<vector<int>> &board, int playerMove, int height,
                 int width);
void checkWin(vector<vector<int>> &board);

int main() {
  int height, width, playerMove;
  vector<vector<int>> board;
  cout << "Welcome to my version of a Connect-4 *-*\n";
  cout << "Player 1 will be the symbol '+' and Player 2 'x' \n";
  cout << "You will first choose what size the board is, please first input a "
          "height and after that a width \n";
  cout << "The board can be a minimum of 4x4 \n";
  cin >> height >> width;
  while (height < 5 || width < 5) {
    cout << "invalid board size, got to be atleast 4x4.... \n";
    cout << "Please input another height and width \n";
    cin >> height >> width;
  }
  createBoard(board, height, width);
  while (true) {
    int turn = 0;
    if (turn % 2 == 0) {
      cout << "Alright, P1 please write the number for which spot you would "
              "like "
              "to occupy";
    } else {
      cout << "Alright, P2 please write the number for which spot you would "
              "like "
              "to occupy";
    }
    turn++;
    cin >> playerMove;
    checkValidMove(board, playerMove, height);
    updateBoard(board, playerMove, height, width);
    checkWin(board);
  }
}

void createBoard(vector<vector<int>> *board, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      *board[i][j] = "_" << "|" << endl;
    }
    cout << endl;
  }
}

int checkValidMove(vector<vector<int>> &board, int playerMove, int height) {
  for (int i = height; i >= 0; i--) {
    if (board[playerMove] == "_") {
      return board[i][playerMove];
    }
  }
}
void updateBoard(vector<vector<int>> &board, int playerMove, int height,
                 int width) {}

void checkWin(vector<vector<int>> &board) {}
