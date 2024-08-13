#include <iostream>
#include <string>
using namespace std;

int main ()  {
  string input;
  int i = 0;
  cout << "Good day to you, you have 3 tries to enter the password.\n ";
  cin >> input;
  while (i < 2) {
    if (input != "ShinNoodle123") {
      cout << "wrong password try again \n";
      cin >> input;
      i++;
    }
    else  {
      cout << "successfully logged in \n";
      break;
   }
  }  
}
