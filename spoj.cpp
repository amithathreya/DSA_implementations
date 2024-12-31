#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false; // Numbers less than or equal to 1 are not prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false; // If divisible, not a prime
    }
    return true;
}

int main() {
    int n, next_prime;
    cin >> n >> next_prime;

    bool isImmediate = true; // Flag to check if next_prime is the immediate prime

    for (int i = n + 1; i < next_prime; i++) {
        if (isPrime(i)) {
            isImmediate = false; // A prime exists between n and next_prime
            break;
        }
    }

    if (isImmediate && isPrime(next_prime)) {
        cout << "YES" << endl; // next_prime is the immediate prime
    } else {
        cout << "NO" << endl; // Either next_prime is not prime or another prime exists between
    }

    return 0;
}
