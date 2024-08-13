#include <iostream>
#include <string>

using namespace std;

struct user_data {
  string phone_number;
  string name;
  string address;
};

int main() {
  user_data user1;

  cout << "Please give me ur Username: \n";
  getline(cin, user1.name);
  cout << "Now your Address: \n";
  getline(cin, user1.address);
  cout << "Now your Phonenumber: \n";
  getline(cin, user1.phone_number);

  cout << "Here are the stats for user 1: \n";
  cout << "His Name: \n" << user1.name << endl;
  cout << "His Address: \n" << user1.address << endl;
  cout << "His Phonenumber: \n" << user1.phone_number << endl;
}
