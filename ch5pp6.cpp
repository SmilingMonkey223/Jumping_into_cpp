#include <iostream>

using namespace std;

int main () {
  cout << "here are the first 20 numbers squared\n";
  for (int i = 0;i <= 20;i++) {
    int squared = i * i;
    cout << i << " is " << squared << " squared\n";
  }
   
}
