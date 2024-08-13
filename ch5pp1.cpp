#include <iostream>



using namespace std;

int main () {
  for (int i = 99; i > 0; i--) {
    cout << i << " bottles of beer, on the wall. " << endl;
    cout << i << " bottles of beer. " << endl;
    cout << "Take one down, pass it around, " << i-1 << " bottles of beer on the wall.";
  }
}
