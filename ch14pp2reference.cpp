#include <iostream>
#include <vector>

using namespace std;

void generateArray(vector<vector<vector<int>>> &Multiplication_array,
                   int length, int width, int height);

int main() {
  vector<vector<vector<int>>> Multiplication_array;
  int length, width, height;
  cout << "Give me a length, a width and then a height: ";
  cin >> length >> width >> height;

  Multiplication_array.resize(
      length, vector<vector<int>>((width), vector<int>(height)));

  cout << "Here is the resulting 3D-Array Multiplication table from your "
          "inputs:\n";
  generateArray(Multiplication_array, length, width, height);

  return 0;
}

void generateArray(vector<vector<vector<int>>> &Multiplication_array,
                   int length, int width, int height) {
  for (int i = 0; i < length; i++) {
    cout << "Layer " << i + 1 << endl;
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < height; k++) {
        Multiplication_array[i][j][k] = (i + 1) * (j + 1) * (k + 1);
        cout << (Multiplication_array[i][j][k]) << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
