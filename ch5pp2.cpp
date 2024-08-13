#include <iostream>
#include <string>
using namespace std;

int main () {

  string input;
  cout << "Please select one of the options: " << endl;
  cout << "Fish\n" "Salad\n" "Beef\n";
  cin >> input;
  while (input != "Fish" && input != "Beef" && input != "Salad") {
    cout << "Please select one of the options\n";
    cin >> input;
  }
  cout << "here is your " << input << endl; 
}
