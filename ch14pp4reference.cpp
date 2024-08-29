#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void displayFriends(map<string, int> &friends);
void displayFriendsSorted(map<string, int> &friends);
void addFriend(map<string, int> &friends, string name, int days);
void updateValue(map<string, int> &friends, string name, int days);

int main() {
  map<string, int> friends;
  string name;
  int days;
  int input;

  while (true) {
    cout << "This is a program that lets you see when you last talked to a "
            "friend \n";
    cout << "Type 1 if you want to add a new friend \n";
    cout << "Type 2 if you want to update a value for a friend \n";
    cout << "Type 3 if you want to have the list of all your friends displayed "
            "\n";
    cout << "Type 4 if you want to have the list of all your friends displayed "
            "but by recency \n";
    cout << "Type 5 if you want to exit this program \n";
    cin >> input;

    switch (input) {
    case 1:
      cout << "What is the Name of the friend you want to add? \n";
      cin >> name;
      cout << "and how many days has it been since youve last spoken to this "
              "person? please write a number only: \n";
      cin >> days;
      addFriend(friends, name, days);
      break;
    case 2:
      cout << "From what friend would you like to update your talking history? "
              "\n";
      cin >> name;
      cout << "and when did you last talk to that person? \n";
      cin >> days;
      updateValue(friends, name, days);
      break;
    case 3:
      cout << "Here is your friends list and when you last talked to them: \n";
      displayFriends(friends);
      break;
    case 4:
      cout << "Here is your friends list and when you last talked to them, "
              "sorted "
              "by how recent your last conversation was: \n";
      displayFriendsSorted(friends);
      break;
    case 5:
      cout << "Hope you had fun using the program, goodbye \n";
      return 0;
    default:
      cout << "You gave an input that is not recognized, please try another "
              "number \n"
           << endl;
      continue;
    }
  }
}

void addFriend(map<string, int> &friends, string name, int days) {
  if (friends.count(name) > 0) {
    cout << "A Friend with this name exists already, u need to name this "
            "person different "
            "if this is a new friend \n";
  } else {
    friends[name] = days;
  }
}

void updateValue(map<string, int> &friends, string name, int days) {
  if (friends.find(name) != friends.end()) {
    friends[name] = days;
  } else {
    cout << "Friend not found in the list. Please check the name and try again."
         << endl;
  }
}

void displayFriends(map<string, int> &friends) {
  for (const auto &entry : friends) {
    cout << entry.first << ": " << entry.second << endl;
  }
}

void displayFriendsSorted(map<string, int> &friends) {
  vector<pair<string, int>> sorted_friends(friends.begin(), friends.end());

  sort(sorted_friends.begin(), sorted_friends.end(),
       [](const pair<string, int> &a, const pair<string, int> &b) {
         return a.second < b.second;
       });

  for (const auto &entry : sorted_friends) {
    cout << entry.first << ": " << entry.second << endl;
  }
}
