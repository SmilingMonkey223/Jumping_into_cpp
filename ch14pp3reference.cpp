
#include <iostream>
#include <vector>
using namespace std;

void createArray(vector<vector<int>> &array, int val_1, int val_2);

int main() {
  vector<vector<int>> array;
  int val_1, val_2;
  cout << "Give me 2 value for a 2D Array \n";
  cin >> val_1 >> val_2;
  createArray(array, val_1, val_2);
  return 0;
}

void createArray(vector<vector<int>> &array, int val_1, int val_2) {
  int x;
  array.resize(val_1, vector<int>(val_2));
  for (int i = 0; i < val_1; i++) {
    for (int j = 0; j < val_2; j++) {
      cout << &array[i][j] << endl;
    }
    cout << endl;
  }
}
