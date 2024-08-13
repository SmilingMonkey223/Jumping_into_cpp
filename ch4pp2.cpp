#include <iostream>

using namespace std;

int main ()
{
  int pw1, pw2, check;
  cout << "Create a password, it can only be a number: ";
  cin >> pw1;
  cout << "Create another password, it can only be a number as well: ";
  cin >> pw2;
  cout << "Give me one of the passwords: ";
  cin >> check;
  if (check == pw1 || check == pw2)
  {
    cout << "Successful login\n";
  }
  else {
    cout << "Wrong password, try again\n";
  }
}

