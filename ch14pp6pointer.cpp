#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>

using namespace std;

void initializeMaze(int &width, int &height, char **&mazeGrid);
void generateMazePaths(int startX, int startY, char **mazeGrid, int width,
                       int height);
void carveExit(char **mazeGrid, int width, int height);
void displayMaze(char **mazeGrid, int width, int height);
void freeMazeMemory(char **mazeGrid, int height);

int main() {
  srand(time(NULL));
  int width, height;
  cout << "Welcome to my Maze Generator\n";
  cout << "Enter maze dimensions (min width 20, min height 10): \n";
  cin >> width >> height;

  assert(width >= 20 && height >= 10 &&
         "Maze dimensions must be at least 20x10.");

  // Maze initialization
  char **mazeGrid;
  initializeMaze(width, height, mazeGrid);
  int entranceRow = (rand() % ((height - 1) / 2)) * 2 + 1;
  mazeGrid[entranceRow][0] = ' ';
  mazeGrid[entranceRow][1] = ' ';
  generateMazePaths(entranceRow, 1, mazeGrid, width, height);
  carveExit(mazeGrid, width, height);
  displayMaze(mazeGrid, width, height);
  freeMazeMemory(mazeGrid, height);
  cout << "\nGood luck finding your way out!\n";
  return 0;
}

// Function to initialize the maze with walls and ensure odd dimensions
void initializeMaze(int &width, int &height, char **&mazeGrid) {
  if (width % 2 == 0)
    width++;
  if (height % 2 == 0)
    height++;

  mazeGrid = new char *[height];
  assert(mazeGrid != nullptr && "Maze grid allocation failed.");

  for (int i = 0; i < height; i++) {
    mazeGrid[i] = new char[width];
    assert(mazeGrid[i] != nullptr && "Maze row allocation failed.");
    fill(mazeGrid[i], mazeGrid[i] + width, '#'); // Fill with walls
  }
}

// Recursive DFS function to generate paths
void generateMazePaths(int x, int y, char **mazeGrid, int width, int height) {
  int dx[4] = {0, 2, 0, -2};
  int dy[4] = {2, 0, -2, 0};
  int directions[4] = {0, 1, 2, 3};

  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(directions, directions + 4, g);

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[directions[i]];
    int ny = y + dy[directions[i]];

    // Ensure the new cell is within bounds and unvisited (still a wall)
    if (nx > 0 && nx < height - 1 && ny > 0 && ny < width - 1 &&
        mazeGrid[nx][ny] == '#') {
      assert(mazeGrid[x][y] == ' ' &&
             "DFS starting position should be a path.");
      mazeGrid[x + dx[directions[i]] / 2][y + dy[directions[i]] / 2] =
          ' ';                // Remove wall
      mazeGrid[nx][ny] = ' '; // Mark cell as part of the path
      generateMazePaths(nx, ny, mazeGrid, width, height);
    }
  }
}

// Carve an exit on the right side, ensuring it connects to the maze
void carveExit(char **mazeGrid, int width, int height) {
  int exitRow = (rand() % ((height - 1) / 2)) * 2 + 1;
  mazeGrid[exitRow][width - 1] = ' ';
  mazeGrid[exitRow][width - 2] = ' '; // Ensure path connects to exit

  // Assert that the exit cell and its left neighbor are open
  assert(mazeGrid[exitRow][width - 1] == ' ' && "Exit cell should be open.");
  assert(mazeGrid[exitRow][width - 2] == ' ' &&
         "Cell left of exit should be part of the path.");
}

// Function to display the maze
void displayMaze(char **mazeGrid, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << mazeGrid[i][j];
    }
    cout << endl;
  }
}

// Clean up dynamically allocated memory for the maze
void freeMazeMemory(char **mazeGrid, int height) {
  for (int i = 0; i < height; i++) {
    delete[] mazeGrid[i];
  }
  delete[] mazeGrid;
}
