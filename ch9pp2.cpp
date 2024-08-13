#include <iostream>
#include <cstdlib>

using namespace std;

int randRange(int low, int high){
  return rand() % (high - low) + low;
}

int main () {
  int input;
  srand(time(NULL));
  int x = randRange(1,101);
  cout << x << endl;
  cout << "I generated a random number between 1 and 100, try to guess it: \n";
  cin >> input;
  while (input != x) {
    cout << "that was not the correct number, try again: \n";
    cin >> input;
  }
  cout << "Nice! the number was " << x << endl;
} 
