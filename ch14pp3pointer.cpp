#include <iostream>
using namespace std;

int main() {
  int num1, num2;
  cout << "Give me 2 Numbers for a 2D Array: \n";
  cin >> num1 >> num2;

  int **array = new int *[num1];
  for (int i = 0; i < num1; i++) {
    array[i] = new int[num2];
  }

  for (int i = 0; i < num1; i++) {
    for (int j = 0; j < num2; j++) {
      cout << &array[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < num1; i++) {
    delete[] array[i];
  }
  delete[] array;

  return 0;
}
