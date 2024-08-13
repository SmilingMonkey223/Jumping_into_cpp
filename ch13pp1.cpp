#include <iostream>
#include <string>

using namespace std;



void ref_name(string  &name_1, string &name_2) {
  string temp = name_1;
  name_1 = name_2;
  name_2 = temp;

}

void p_name(string *p_name_1, string *p_name_2) {
  string temp = *p_name_1;
  *p_name_1 = *p_name_2;
  *p_name_2 = temp;
}

int main () {
  string name_1;
  string name_2;
  cout << "Write your first or last name: \n";
  cin >> name_1;
  cout << "Write your the other option of what you write before: \n";
  cin >> name_2;
  p_name(&name_1, &name_2);
  cout << name_1 << " " << name_2 << '\n'; 
  ref_name(name_1, name_2);
  cout << name_1 << " " << name_2 << '\n'; 
}
