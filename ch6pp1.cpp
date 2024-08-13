#include <iostream>
#include <string>
using namespace std;

void Fish (string input);
void Beef (string input);
void Salad (string input);
void select();
void calculator ();
void song();

int main () {
  string input;
  select();
  cout << "Fish\n" "Salad\n" "Beef\n";
  cin >> input;
  while (input != "Fish" && input != "Beef" && input != "Salad") {
    select();
    cin >> input;
  }
  Salad(input);
  Fish(input);
  Beef(input);
  cout << "do you want to call the function 99 beers?: ";
  cin >> input;
  if (input == "yes") {
    song();
  }
  cout << "do you want to call the function Calculator?: ";
  cin >> input;
  if (input == "yes") {
    calculator();
  }
}
  void select () {
    cout << "Please select one of the options: " << endl;
  }
  void Fish (string input) {
    if (input == "Fish") {
      cout << "here is your " << input << endl; 
    }
  }
  void Salad (string input) {
    if (input == "Salad") {
      cout << "here is your " << input << endl; 
    }
  }
  void Beef (string input) {
    if (input == "Beef") {
      cout << "here is your " << input << endl; 
    }
  }
  void song () {
  for (int i = 99; i > 0; i--) {
    cout << i << " bottles of beer, on the wall. " << endl;
    cout << i << " bottles of beer. " << endl;
    cout << "Take one down, pass it around, " << i-1 << " bottles of beer on the wall.";
    }
  }
   void calculator () {
    char op;
    double num1, num2, result;
    cout << "\nGive me one of the 4 base arithmetic operations: ";
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


