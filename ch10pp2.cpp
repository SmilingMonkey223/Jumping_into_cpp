/* Write a program that takes in 50 values and prints out the highest, the lowest, the average and
then all 50 input values, one per line. */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void lowest(int array[]) {
  int min = array[0];
  for (int i = 0;i < 50;i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  cout << "the lowest number in of all 50 is : " << min << endl;
}

void highest(int array[]) {
  int max = array[0];
  for (int i = 0;i < 50;i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  cout << "the highest number in of all 50 is : " << max << endl;
}

void average(int array[]) {
  double sum = 0;
  for (int i = 0;i < 50;i++) {
    sum += array[i];
  }
  double avg = sum / 50;
  cout << "the average of all 50 numbers is : " << avg << endl;
}


void displayArray (int array[]) {
  for ( int i = 0; i < 50; i++ ) {
    if ( i != 0 ) {
      cout << "\n";
    }
    cout << array[i];
    if (i == 49){
      cout << "\n"; 
    }
  }
}
int main ()  {
  int array[50];
  srand( time( NULL ) );
  for ( int i = 0; i < 50; i++ ) {
    array[i] = rand() % 100;
  }
  highest(array); 
  lowest(array); 
  average(array); 
  displayArray(array);
}
