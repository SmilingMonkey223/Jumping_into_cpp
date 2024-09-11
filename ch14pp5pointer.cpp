#include <iostream>
#include <vector>

using namespace std;
void createBoard(vector<vector<board>>);
int main() {
  int height, width, playerMove;
  vector<vector<int>> board;
  cout << "Welcome to my version of a Connect-4 \n";
  cout << "Player 1 will be the symbol '+' and Player 2 'x' \n";
  cout << "You will first choose what size the board is, please first input a "
          "height and after that a width \n";
  cout << "The board can be a minimum of 4x4 \n";
  cin >> height >> width;
  createBoard(*board);
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
    checkValidMove(vector<vector<int>> * board, playerMove);
    updateBoard(vector<vector<int>> * board, playerMove);
  }
}
