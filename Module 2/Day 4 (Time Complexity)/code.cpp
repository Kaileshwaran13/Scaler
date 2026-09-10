#include<iostream>
using namespace std;

// Count the number of factors in a number 

// Approach 1: Brute Force

void factorCountBruteForce(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    cout << count << '\n';
}

// Approach 2: Optimized by Sqrt Logic

void factorCountSqrt (int num) {
    int count = 0;
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            if (i * i == num) {
                count++;
            } else {
                count += 2;
            }
        }
    }
    cout << count << '\n';
}


// ----------------------

int main (void) {
    int num;
    cin >> num;
    cout << "Count the Factors of a number: ";
    factorCountBruteForce(num);
    factorCountSqrt(num);
}
