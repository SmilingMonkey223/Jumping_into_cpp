#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int FindSmallestRemainingElement(int array[], int length, int index);
void swap( int array[], int first_index, int second_index);


void sort (int array[], int length) {
  for (int i = 0; i < length; i++) {
    int index = FindSmallestRemainingElement( array, length, i );
    swap( array, i, index );
  }
}

int FindSmallestRemainingElement(int array[],int length, int index) {
  int index_of_smallest_value = index;
  for (int i = index + 1; i < length; i++) {
    if (array[i] < array[index_of_smallest_value]) {
      index_of_smallest_value = i;  
    }
  }
  return index_of_smallest_value;
}

void swap (int array[], int first_index, int second_index) {
  int temp = array[first_index];
  array[first_index] = array[second_index];
  array[second_index] = temp;
}

int main () {
  srand( time( NULL ) );
  int size = 20;
  int array[size];
  int sorted = 0;
  int sorted_array[size];


  for ( int i = 0; i < size; i++ ) {
   array[i] = rand() % 100;
  }
  for ( int i = 0; i < size; i++ ) {
   sorted_array[i] = array[i];
  }
  cout << "Here is the list you just created \n";
  for ( int i = 0; i < size; i++ ) {
  cout << array[i] << endl;
  }
  sort(sorted_array,size);

  for (int i = 0; i < size; i++) {
    if (array[i] == sorted_array[i]) {
      sorted ++;
    }
  }
  if (sorted == size) {
    cout << "This list has already been sorted\n";
  }
  else {
    cout << "Here is the list sorted: \n";
    for (int i = 0; i < size; i++) {
      cout << sorted_array[i] << endl;
    }
  }
}
