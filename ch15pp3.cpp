// Write a program to find an element in a linked list by name.

#include <iostream>
#include <string>
using namespace std;

struct person {
  string name;
  int age;
  float height;
  string profession;
  person *p_next_person = nullptr;
};

// the linked list

person *Chingu() {
  person *p_Chingu = new person;
  p_Chingu->name = "Chingu";
  p_Chingu->age = 19;
  p_Chingu->height = 1.65;
  p_Chingu->profession = "Slavic doll and queen of vancouver";
  p_Chingu->p_next_person = nullptr;
  return p_Chingu;
};

person *Emily() {
  person *p_Emily = new person;
  p_Emily->name = "Emily";
  p_Emily->age = 44;
  p_Emily->height = 1.71;
  p_Emily->profession = "Professor";
  p_Emily->p_next_person = Chingu();
  return p_Emily;
};
person *Charlie() {
  person *p_Charlie = new person;
  p_Charlie->name = "Charlie";
  p_Charlie->age = 29;
  p_Charlie->height = 1.80;
  p_Charlie->profession = "Electrician";
  p_Charlie->p_next_person = Emily();
  return p_Charlie;
};
person *Bob() {
  person *p_Bob = new person;
  p_Bob->name = "Bob";
  p_Bob->age = 15;
  p_Bob->height = 1.70;
  p_Bob->profession = "Student";
  p_Bob->p_next_person = Charlie();
  return p_Bob;
};

person *p_people = Bob();

int main() {
  string element;
  person *current = p_people;
  bool found = false;
  cout << "This is a program to find an element in a linked list by name, we "
          "got the following elements in a linked list : \n Bob \n Charlie \n "
          "Emily \n Chingu \n Please type in the element you wan to search "
          "for : \n";
  cin >> element;
  while (current != nullptr) {
    if (current->name == element) {
      cout << "The data of the person you were looking for : \n Name: "
           << current->name << "\n Age: " << current->age
           << "\n Height: " << current->height << " m "
           << "\n Profession: " << current->profession << endl;
      found = true;
      break;
    }
    current = current->p_next_person;
  }
  if (!found) {
    cout << "This name is not in the database, make sure you wrote the name "
            "Casesensitive and wrote it correctly. \n";
  }
}
