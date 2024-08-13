#include <iostream>
#include <string>

using namespace std;

void multiplication_table(int num_1, int num_2, int **user_table) {
  for (size_t i = 0; i < num_1; i++) {
    for (size_t j = 0; j < num_2; j++) {
      user_table[i][j] = (i + 1) * (j + 1);
      cout << user_table[i][j] << "\t"; // Print each number followed by a tab
    }
    cout << endl; // New line after each row
  }
}

int main() {
  string input;
  cout << "This is a multiplication table creator \n";
  cout << "Please give me two numbers with an x between (example 3x5): \n";
  cin >> input;
  size_t multiplicator = input.find('x');
  int num_1 = stoi(input.substr(0, multiplicator));
  int num_2 = stoi(input.substr(multiplicator + 1));

  // Dynamically allocate memory for the 2D array
  int **user_table = new int *[num_1];
  for (int i = 0; i < num_1; i++) {
    user_table[i] = new int[num_2];
  }

  multiplication_table(num_1, num_2, user_table);

  // Deallocate memory
  for (int i = 0; i < num_1; i++) {
    delete[] user_table[i];
  }
  delete[] user_table;

  return 0;
}
