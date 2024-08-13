#include <iostream>
#include <string>

using namespace std;

struct user_data {
  string phone_number;
  string name;
  string address;
};


int main() {
  int input;
  string display;

  cout << "How many users will there be in ur address book?: \n";
  cin >> input;
  cin.ignore();
  user_data users[input];
  for (int i = 0; i < input; i++) {
    cout << "Please give me ur Username: \n";
    getline(cin,users[i].name);
    cout << "Now your Address: \n";
    getline(cin,users[i].address );
    cout << "Now your Phonenumber: \n";
    getline(cin,users[i].phone_number );
  }
  cout << "Would you like to display ur entire address book? or maybe partially? \n";
  cout << "Type 'all' to display the entire address book, and the corresponding number to look at a specific person: \n";
  cin >> display;
  if (display == "all") {
    for (int i = 0; i < input; i++) {
      cout << "Here is the user data for user " << i + 1 << ":\n";
      cout << "His Name: \n" << users[i].name << endl;
      cout << "His Address: \n" << users[i].address << endl;
      cout << "His Phonenumber: \n" << users[i].phone_number << endl;   
    }
  }
  else {
    int display_singular = stoi(display);
    cout << "His Name: \n" << users[display_singular - 1].name << endl;
    cout << "His Address: \n" << users[display_singular - 1].address << endl;
    cout << "His Phonenumber: \n" << users[display_singular - 1].phone_number << endl;
  }
}
