#include <iostream>

using namespace std;
int main () {
  double input;
  int sum;
  sum = 0;
  cout << "i will sum up all the numbers you put in until you give me the value 0: \n";
  while (input != 0) {
    cin >> input;
    sum += input;
  }
  cout << sum << endl;
}
