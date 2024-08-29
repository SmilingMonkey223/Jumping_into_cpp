#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void generateMaze(vector<vector<char>> &maze, int height, int width);

int main() {
  vector<vector<char>> maze;

  int height, width;
  cout << "'-' welcome to mazegen '-'\n";
  cout << "You can only follow the lines, so if there is a / you will be going "
          "up \n";
  cout << "This programm is a maze generator, please first input a height and "
          "then a width: "
          "\n";
  cin >> height >> width;
  while (height < 10 || width < 10) {
    cout << "This Maze is too small, i dont want to create such a simple maze, "
            "minimum 10x10 \n";
    cin >> height >> width;
  }
  generateMaze(maze, height, width);
  cout << endl << "Have fun finding ur way out of the maze" << endl;
}

void generateMaze(vector<vector<char>> &maze, int height, int width) {
  maze.resize(height, vector<char>(width));
  for (int i = 0; i < height; i++) {
    cout << endl;
    for (int j = 0; j < width; j++) {
      if (i == 3 && j == 0 || i == 6 && j == width - 1) {
        maze[i][j] = '|';
        cout << maze[i][j];
      } else if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
        maze[i][j] = '#';
        cout << maze[i][j];
      } else if (j % 5 == 4) {
        maze[i][j] = '\\';
        cout << maze[i][j];
      } else if (j % 5 == 3) {
        maze[i][j] = '_';
        cout << maze[i][j];
      } else if (j % 5 == 2) {
        maze[i][j] = '[';
        cout << maze[i][j];
      } else if (j % 5 == 1) {
        maze[i][j] = '/';
        cout << maze[i][j];
      } else {
        maze[i][j] = '|';
        cout << maze[i][j];
      }
    }
  }
}
