#include <iostream>
using namespace std;

// Function to calculate Fibonacci iteratively
long long fibIter(int n) {
    if (n == 0) return 0; // Handle the base case for n = 0
    if (n == 1) return 1; // Handle the base case for n = 1

    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci is not defined for negative numbers!" << endl;
        return 1; // Exit with an error code
    }

    cout << "Fibonacci(" << n << ") = " << fibIter(n) << endl;
    return 0; // Indicate successful execution
}
