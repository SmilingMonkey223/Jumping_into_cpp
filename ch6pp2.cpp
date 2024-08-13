#include <iostream>

using namespace std;
char op;
double num1, num2, result;
void divide(double num1, double num2);
void multiply(double num1, double num2);
void sub(double num1, double num2);
void add(double num1, double num2);
int main () {
  cout << "\nGive me one of the 4 base arithmetic operations: ";
  cin >> op;
  cout << "Give me a Number: ";
  cin >> num1;
  cout << "Give me a Number: ";
  cin >> num2;
  if (op == '+') {
    add (num1,num2);
  }
  if (op == '/') {
    divide (num1,num2);
  }
  if (op == '-') {
    sub (num1,num2);
  }
  if (op == '*') {
    multiply (num1,num2);
  }
} 

void add (double num1, double num2) {
  result = num1 + num2;
  cout << "here is the arithmetic operation applied on your numbers: " << result << "\n";
}
void sub (double num1, double num2) {
  result = num1 - num2;
  cout << "here is the arithmetic operation applied on your numbers: " << result << "\n";
}
void multiply (double num1, double num2) {
  result = num1 * num2;
  cout << "here is the arithmetic operation applied on your numbers: " << result << "\n";
}
void divide (double num1, double num2) {
  result = num1 / num2;  
  cout << "here is the arithmetic operation applied on your numbers: " << result << "\n";
}
