#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct user_scores {
  vector<int> scores;
  string name;
};

unordered_map<string, user_scores> users;

void new_score(string name, int score) {
  auto user = users.find(name);
  if (user != users.end()) {
    user->second.scores.push_back(score);
  } else {
    user_scores NewUser;
    NewUser.scores.push_back(score);
    NewUser.name = name; 
    users.insert({name, NewUser});
  }
}

void print_user_scores(string input, const unordered_map<string, user_scores>& users) {
  cout << endl;
  auto user = users.find(input);
  if (user != users.end()) {
    for (int score : user->second.scores) {
      cout << score << endl;
    }   
  } else {
    cout << "User has not been found \n";
  } 
}

void high_scores(const unordered_map<string, user_scores>& users) {
  cout << endl;
  for (const auto& user : users) {
    int high_score = 0;
    for (int score : user.second.scores) {
      if (score > high_score) {
        high_score = score;
      }
    }
    cout << "The highscore of " << user.first << " is " << high_score << endl;
  }
}

void all_scores(const unordered_map<string, user_scores>& users) {
  cout << endl;
  for (const auto& user : users) {
    cout << "These are all the scores for " << user.first << ":\n";
    for (int score : user.second.scores) {
      cout << score << endl; 
    }
  }
}

void all_users(const unordered_map<string, user_scores>& users) {
  cout << "These are all the current users \n";
  for (const auto& user : users) {
    cout << user.first << endl;
  }
}

int main() {
  bool finished = false;
  while (!finished) {
    cout << "Hello, these are the things this program can do: \n";
    cout << "1. by typing '1' you can create a score for a user\n";
    cout << "2. by typing '2' you can list all the highscores each user has gotten so far \n";
    cout << "3. by typing '3' you can list all the current users \n";
    cout << "4. by typing '4' you can list every user and each of their scores \n";
    cout << "5. by typing '5' you can search for a user and list all their scores\n";
    cout << "6. by typing 'exit' you will exit this program. \n";
    
    string input;
    cin >> input;
    
    if (input == "1") {
      string username;
      int points;
      cout << "For what user would you like to create a score?\n";
      cin >> username;
      cout << "And what score did you get: \n";
      cin >> points;
      new_score(username, points);
    } else if (input == "2") {
      high_scores(users);
    } else if (input == "3") {
      all_users(users);
    } else if (input == "4") {
      all_scores(users);
    } else if (input == "5") {
      string username;
      cout << "Enter the username to search for: \n";
      cin >> username;
      print_user_scores(username, users);
    } else if (input == "exit") {
      finished = true;
      cout << "Thank you very much for using my program \n";
    } else {
      cout << "Invalid option, please try again.\n";
    }
  }
  return 0;
}

