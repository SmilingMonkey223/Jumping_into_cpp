#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

// Assuming symbols and values arrays are defined globally or passed to the function
const char* symbols[] = {"Cherry", "Lemon", "Orange", "Plum"};
const int values[] = {100, 200, 300, 400};  // Example values

int randRange(int min, int max) {
    return rand() % (max - min) + min;
}

void display_symbols() {
    int display[3];  // Correctly initializing the array
    for (int i = 0; i < 3; i++) {
        int x = randRange(0, 4);
        display[i] = x;
    }

    // Display the symbols
    cout << "Symbols: ";
    for (int i = 0; i < 3; i++) {
        cout << symbols[display[i]] << " ";
    }
    cout << "\n";

    // Check for winning combinations
    if (display[0] == display[1] && display[1] == display[2]) {
        cout << "You won " << values[display[0]] << " dollars!\n";
    } else {
        cout << "You didn't win anything.\n";
    }
}

int main() {
    srand(time(0));  // Seed the random number generator
    display_symbols();
    return 0;
}
