#include <iostream>
#include <string>

using namespace std;

int SumAndProduct (int num_1, int num_2, int *product) {
  *product = num_2 * num_1;
  return num_1 + num_2;
}

int main() {
  int num_1, num_2;
  int product;
  cout << "Give me 2 numbers, give 1 and then press enter and enter for the next one again: \n";
  cin >> num_1;
  cin >> num_2;
  int sum = SumAndProduct(num_1, num_2, &product);
  cout << sum << " is the sum and " << product << " is the product of your number \n";
}

