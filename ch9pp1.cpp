#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int randRange (int low, int high) {
  return rand() % (high - low + 1) + low;
}

int main () {
  cout << "Flip a coin!: \n";
  srand(time(NULL));
  for (size_t i = 0; i < 10; i++) {
    int x = randRange(0,1);
    if (x == 1) {
      cout << "Heads\n";
    }
    else {
      cout << "Tails\n";
    }
  }
}

