// Write a program that adds elements to a linked list in sorted order, rather
// than at the beginning.

#include <cassert>
#include <iostream>
using namespace std;

struct number {
  int element;
  number *p_next_number;
};

number *p_numbers = nullptr;
number *getNewNumber(int element) {
  number *p_number = new number;
  p_number->element = element;
  p_number->p_next_number = nullptr;
  return p_number;
}

number *addElement(number *p_numbers, int element) {
  number *p_number = getNewNumber(element);

  if (p_numbers == nullptr || p_numbers->element > element) {
    p_number->p_next_number = p_numbers;
    return p_number;
  }

  number *current_number = p_numbers;
  while (current_number->p_next_number != nullptr &&
         current_number->p_next_number->element < element) {
    current_number = current_number->p_next_number;
  }

  p_number->p_next_number = current_number->p_next_number;
  current_number->p_next_number = p_number;

  return p_numbers;
}

int main() {
  int element;
  cout << "This program adds elements to a list in sorted order.\n";

  while (true) {
    cout << "Enter an integer to add to the list (or 'x' to stop): ";
    if (!(cin >> element)) {
      cin.clear();
      cin.ignore(1000, '\n');
      break;
    }

    p_numbers = addElement(p_numbers, element);

    cout << "Current list: ";
    number *current = p_numbers;
    while (current != nullptr) {
      cout << current->element << " ";
      current = current->p_next_number;
    }
    cout << endl;
  }

  return 0;
}
