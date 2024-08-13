#include <iostream>
#include <string>

using namespace std;


int main () {
  int x = 3;
  int y = 20;

  if (&y < &x) {
  cout << x << " " << y << endl;
  }
  else {
    cout << y << " " << x << endl;
  }


}
