#include <iostream>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to find the sum of prime factors of a number
int sumOfPrimeFactors(int num) {
    int sum = 0;

    // Check for number of 2s
    while (num % 2 == 0) {
        sum += 2;
        num /= 2;
    }

    // Check for other primes
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            sum += i;
            num /= i;
        }
    }

    // This condition is to check if num is a prime number greater than 2
    if (num > 2) {
        sum += num;
    }

    return sum;
}

int main() {
    cout << "Numbers from 1 to 1000 whose prime factors sum up to a prime number:" << endl;

    for (int num = 1; num <= 1000; num++) {
        int sum = sumOfPrimeFactors(num);
        if (isPrime(sum)) {
            cout << num << " ";
        }
    }

    cout << endl;
    return 0;
}
