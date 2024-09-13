#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

using namespace std;

void addFriend(map<string, int> *userbase);
void updateFriend(map<string, int> *userbase);
bool FriendExists(string name, map<string, int> *userbase);
void displaySorted(map<string, int> *userbase,
                   vector<pair<string, int>> *sortedUserbase);

int main() {
  string name;
  int input, lastTimeSpokenTo;
  vector<pair<string, int>> sortedUserbase;
  map<string, int> userbase;
  cout << "This is a Program to keep track of when youve last talked to a "
          "friend \n";
  cout << "here are your options : \n";
  while (true) {
    cout << "Enter 1 if you want to add a new Friend into your list \n";
    cout << "Enter 2 if you want to update how recently youve talked to a "
            "person "
            "\n";
    cout << "Enter 3 if you want to display when you last talked to whom, "
            "sorted "
            "by when you last talked to them \n";
    cout << "Enter 4 to quit the Program \n";
    cin >> input;
    if (input == 4)
      break;
    switch (input) {
    case 1:
      addFriend(&userbase);
      break;
    case 2:
      updateFriend(&userbase);
      break;
    case 3:
      displaySorted(&userbase, &sortedUserbase);
      break;
    default:
      cout << "Invalid input, please input a number between 1-4 \n";
      cin >> input;
    }
  }
}
void addFriend(map<string, int> *userbase, string name, int lastTimeSpokenTo) {
  cout << "What is the name of your friend? \n";
  cin >> name;
  while (true) {
    if (!FriendExists(name, &userbase)) {
      cout "And when have you last spoken to that person? (in days) \n";
      cin >> lastTimeSpokenTo;
      userbase->insert({name, lastTimeSpokenTo});
      cout << "Your friend has been added to the userbase \n";
      break;
    } else {
      cout
          << "This name already exists in the userbase, please use a different "
             "name for this person \n";
      cin >> name;
    }
  }
}

void updateFriend(map<string, int> *userbase, string name,
                  int lastTimeSpokenTo) {
  if (FriendExists(name, *userbase)) {
    cout << "And when have you last spoken to that person? (in days) \n";
    cin >> lastTimeSpokenTo;
    userbase->at({name, lastTimeSpokenTo});
    cout << "The last time you have talked to this person has been updated \n";
  }
}

bool FriendExists(string name, map<string, int> *userbase) {
  if (userbase->find(name) != userbase->end()) {
    return true;
  }
  return false;
}

void displaySorted(map<string, int> *userbase,
                   vector<pair<string, int>> *sortedUserbase) {
  for (int i = 0; i < size(userbase); i++) {
    sortedUserbase[i] = userbase[i];
  }
  sort(sortedUserbase.begin(), sortedUserbase.end(),
       [](auto &left, auto &right) { return left.second < right.second; });
  for (int i = 0; i < size(sortedUserbase); i++) {
    cout << sortedUserbase[i] << endl;
  }
}
