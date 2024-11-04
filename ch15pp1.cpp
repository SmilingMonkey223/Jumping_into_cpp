// Write a program to remove an element from a linked list; the remove function
// should take just the element to be removed.

#include <cassert>
#include <iostream>

using namespace std;

struct number {
  int data;
  number *p_next_number;
};

number *p_numbers = NULL;

number *getNewNumber(int data) {
  number *p_number = new number;
  p_number->data = data;
  p_number->p_next_number = NULL;
  return p_number;
}

void deleteNumber(number *&head, int element) {
  while (head != NULL && head->data == element) {
    number *temp = head;
    head = head->p_next_number;
    delete temp;
  }

  if (head == NULL)
    return;

  number *current = head;
  while (current->p_next_number != NULL) {
    if (current->p_next_number->data == element) {
      number *temp = current->p_next_number;
      current->p_next_number = current->p_next_number->p_next_number;
      delete temp;
    } else {
      current = current->p_next_number;
    }
  }
}

int main() {
  int a, b, c, d, element;
  cout
      << "Hello, this program removes the element you want from a list, give "
         "me 4 numbers and after that tell me which one you would like to "
         "remove. After each number input press enter to signify that this is "
         "the number you want to input, the number cant be larger than 2'147 "
         "million / smaller than -2.147 million. Please enter the numbers : \n";

  cin >> a >> b >> c >> d;

  assert(cin && "All inputs must be integers.");

  p_numbers = getNewNumber(a);
  number *current = p_numbers;

  int array[3] = {b, c, d};

  for (int i = 0; i < 3; i++) {
    current->p_next_number = getNewNumber(array[i]);
    current = current->p_next_number;
  }
  cout << "Now please tell me what element (number) you would like to remove "
          "from the data structure : \n";
  cin >> element;
  deleteNumber(p_numbers, element);
  cout << "here is the finalized list : \n";
  current = p_numbers;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->p_next_number;
  }
  cout << endl;

  return 0;
}
