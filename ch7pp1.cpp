#include <iostream>
#include <string>

using namespace std;

// Arrays for numbers in words
string belowTwenty[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string thousands[] = {"", "Thousand", "Million", "Billion", "Trillion"};

string numberToWords(long long num);

string helper(int num) {
  if (num == 0) {
    return "";
  } else if (num < 20) {
    return belowTwenty[num] + " ";
  } else if (num < 100) {
    return tens[num / 10] + " " + helper(num % 10);
  } else {
    return belowTwenty[num / 100] + " Hundred " + helper(num % 100);
  }
}

string numberToWords(long long num) {
    if (num == 0) {
      return "Zero";
    }

    string result = "";
    int i = 0;

    while (num > 0) {
      if (num % 1000 != 0) {
        result = helper(num % 1000) + thousands[i] + " " + result;
        num /= 1000;
      i++;
    }

    // Trim the result string
    while (result.back() == ' ') {
      result.pop_back();
    }

    return result;
}

int main() {
  long long num;
  cout << "Enter a number (0 to 100 billion): ";
  cin >> num;

  if (num < 0 || num > 100000000000) {
    cout << "Number out of range!" << endl;
  } else {
    cout << numberToWords(num) << endl;
  }
}
  
