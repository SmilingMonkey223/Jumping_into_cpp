#include <iostream>
#include <string>

using namespace std;

// Function to print common lines based on the day
void printCommonLines(int day) {
    switch(day) {
        case 12: cout << "Twelve drummers drumming\n";
        case 11: cout << "Eleven pipers piping\n";
        case 10: cout << "Ten lords a-leaping\n";
        case 9: cout << "Nine ladies dancing\n";
        case 8: cout << "Eight maids a-milking\n";
        case 7: cout << "Seven swans a-swimming\n";
        case 6: cout << "Six geese a-laying\n";
        case 5: cout << "Five gold rings\n";
        case 4: cout << "Four calling birds\n";
        case 3: cout << "Three French hens\n";
        case 2: cout << "Two turtle doves\n";
        case 1:
            if(day != 1) {
                cout << "And a partridge in a pear tree\n";
            } else {
                cout << "A partridge in a pear tree\n";
            }
            break;
    }
}

int main() {
    int input;
    cout << "The verse of which day would you like to play (1-12)?: ";
    cin >> input;

    if (input < 1 || input > 12) {
        cout << "Invalid input. Please enter a number between 1 and 12." << endl;
        return 1;
    }

    cout << "On the ";

    switch (input) {
        case 1: cout << "first "; break;
        case 2: cout << "second "; break;
        case 3: cout << "third "; break;
        case 4: cout << "fourth "; break;
        case 5: cout << "fifth "; break;
        case 6: cout << "sixth "; break;
        case 7: cout << "seventh "; break;
        case 8: cout << "eighth "; break;
        case 9: cout << "ninth "; break;
        case 10: cout << "tenth "; break;
        case 11: cout << "eleventh "; break;
        case 12: cout << "twelfth "; break;
    }

    cout << "day of Christmas my true love sent to me\n";

    printCommonLines(input);
}
