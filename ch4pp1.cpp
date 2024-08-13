#include <iostream>

using namespace std;

int main ()
{
  int age1, age2;
  cout << "Give me an age: ";
  cin >> age1;
  cout << "Give me another age: ";
  cin >> age2;
  if (age1 && age2 > 100)
  {
    cout << "Wow both ages are over 100?\n";
  }
  else 
  {
    cout << "those are some ordiniary ages, do better buddy\n";
  }
}

