#include <iostream>
#include <map>
#include <string>
using namespace std;

void addFriend(string name, int lastTimeSpokenTo);
void updateFriend(string name, int lastTimeSpokenTo);
void ExistingFriend(map<string, int> userbase);
void displaySorted();

int main() {
  string name;
  int input, lastTimeSpokenTo;
  map<string name, int lastTimeSpokenTo> userbase;

  cout << "This is a Program to keep track of when youve last talked to a "
          "friend \n";
  cout << "Enter 1 if you want to add a new Friend into your list \n";
  cout << "Enter 2 if you want to update how recently youve talked to a person "
          "\n";
  cout << "Enter 3 if you want to display when you last talked to whom, sorted "
          "by when you last talked to them \n";
  cout << "Enter 4 to quit the Program \n";
  while (input < 1 || input > 4) {
    cout << "You did not input a valid number, please input a number between "
            "1-4 \n";
    cin >> input;
  }
  switch (input) {
  case 1:
    addFriend(name, lastTimeSpokenTo);
    break;
  case 2:
    updateFriend(name, lastTimeSpokenTo);
    break;
  case 3:
    displaySorted();
    break;
  case 4:
    return 0;
  default:
  }
}
void addFriend(string name, int lastTimeSpokenTo) {
  cout << "What is the name of your friend? \n";
  cin >> name;
  if (!ExistingFriend) {
    cout "And when have you last spoken to that person? (in days) \n";
    cin >> lastTimeSpokenTo;
    cout << "Your friend has been added to the userbase \n";
  } else {
    cout << "This name is already in the userbase, please use a different "
            "name for this person \n";
  }
}
