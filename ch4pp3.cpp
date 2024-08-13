#include <iostream>

using namespace std;

int main ()
{
  char op;
  double num1, num2, result;
cout << "Give me one of the 4 base arithmetic operations: ";
cin >> op;
  cout << "Give me a Number: ";
  cin >> num1;
  cout << "Give me a Number: ";
  cin >> num2;
  if (op == '+' ) {
    result = num1 + num2;
    cout << "here is the arithmetic operation applied on your numbers: " << result << "\n";
  }
  else if ( op == '-' ) {
    result = num1 - num2;
    cout << "here is the arithmetic operation applied on your numbers: " << result << "\n";
  }
  else if ( op == '*' ) {
    result = num1 * num2;
    cout << "here is the arithmetic operation applied on your numbers: " << result << "\n";
  }
  else {
    result = num1 / num2;  
    cout << "here is the arithmetic operation applied on your numbers: " << result << "\n";
  }
}
