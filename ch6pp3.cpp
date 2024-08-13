#include <iostream>
#include <string>

using namespace std;

void pwcheck(double checkPw, string checkUser, string user1, string user2, string user3, double pw1, double pw2, double pw3);

int main() {
    double pw1, pw2, pw3, checkPw;
    string checkUser, user1, user2, user3;

    // Create usernames and passwords
    cout << "Create a Username for user1: ";
    cin >> user1;
    cout << "Now user2: ";
    cin >> user2;
    cout << "and lastly user3: ";
    cin >> user3;
    cout << "Create a password for user1: ";
    cin >> pw1;
    cout << "User2: ";
    cin >> pw2;
    cout << "User3: ";
    cin >> pw3;

    // Attempt to log in
    cout << "Log into one of your accounts, give me your username: ";
    cin >> checkUser;
    cout << "and now the password for that account: ";
    cin >> checkPw;

    pwcheck(checkPw, checkUser, user1, user2, user3, pw1, pw2, pw3);
}

void pwcheck(double checkPw, string checkUser, string user1, string user2, string user3, double pw1, double pw2, double pw3) {
    if ((checkUser == user1 && checkPw == pw1) || 
        (checkUser == user2 && checkPw == pw2) || 
        (checkUser == user3 && checkPw == pw3)) {
        cout << "Successful login\n";
    } else {
        cout << "Wrong username or password, try again\n";
        cout << "Log into one of your accounts, give me your username: ";
        cin >> checkUser;
        cout << "and now the password for that account: ";
        cin >> checkPw;

        if ((checkUser == user1 && checkPw == pw1) || 
            (checkUser == user2 && checkPw == pw2) || 
            (checkUser == user3 && checkPw == pw3)) {
            cout << "Successful login\n";
        } else {
            cout << "Wrong twice, unsuccessful login\n";
        }
    }
}

