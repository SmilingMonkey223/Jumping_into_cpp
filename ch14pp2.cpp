#include <iostream>
#include <string>

using namespace std;

void multiplication_table_2D(int num_1, int num_2, int **user_table) {
  for (size_t i = 0; i < num_1; i++) {
    for (size_t j = 0; j < num_2; j++) {
      user_table[i][j] = (i + 1) * (j + 1);
      cout << user_table[i][j] << "\t"; // Print each number followed by a tab
    }
    cout << endl; // New line after each row
  }
}
void multiplication_table_3D(int length, int width, int height,
                             int ***user_table) {
  for (size_t i = 0; i < length; i++) {
    for (size_t j = 0; j < width; j++) {
      for (size_t k = 0; k < height; k++) {
        user_table[i][j][k] = (i + 1) * (j + 1) * (k + 1);
        cout << user_table[i][j][k] << "\t";
      }
    }
    cout << endl; // New line after each row
  }
}
int main() {
  string input;
  string choice;
  cout << "This is a multiplication table creator \n";
  cout << "Would you like a 3D or 2D multiplication table? \n";
  cin >> choice;
  if (choice == "2D") {
    cout << "Please give me two numbers with an x between (example 3x5): \n";
    cin >> input;
    size_t multiplicator = input.find('x');
    int num_1 = stoi(input.substr(0, multiplicator));
    int num_2 = stoi(input.substr(multiplicator + 1));

    int **user_table = new int *[num_1];
    for (int i = 0; i < num_1; i++) {
      user_table[i] = new int[num_2];
    }

    multiplication_table_2D(num_1, num_2, user_table);

    for (int i = 0; i < num_1; i++) {
      delete[] user_table[i];
    }
    delete[] user_table;

    return 0;
  }

  else if (choice == "3D") {
    int length, width, height;
    cout << "Please give me a length, width and height for a 3D "
            "multiplication "
            "table: \n";
    cin >> length >> width >> height;
    int ***p_p_user_table;
    p_p_user_table = new int **[length];
    for (int i = 0; i < length; i++) {
      p_p_user_table[i] = new int *[width];
      for (int j = 0; j < width; j++) {
        p_p_user_table[i][j] = new int[height];
      }
    }

    multiplication_table_3D(length, width, height, p_p_user_table);

    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
        delete[] p_p_user_table[i][j];
      }
    }
    for (int i = 0; i < length; i++) {
      delete[] p_p_user_table[i];
    }
    delete[] p_p_user_table;
  }
}
