#include <iostream>
#include <ctime> // Do pomiaru czasu
using namespace std;

// Funkcja rekurencyjna
long long int fibRec(int n) {
    if (n < 2)
        return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

// Funkcja iteracyjna
long long int fibIter(int n) {
    if (n < 2)
        return n;

    long long int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    // Test 1: Pięć wybranych wartości n < 20
    cout << "Test dla n < 20:\n";
    int testValues[] = { 5, 10, 15, 18, 19 };
    for (int n : testValues) {
        cout << "n = " << n << ":\n";
        cout << "Rekurencyjnie: " << fibRec(n) << "\n";
        cout << "Iteracyjnie: " << fibIter(n) << "\n";
    }

    // Test 2: Obliczenia dla Fib46 - Fib50
    cout << "\nObliczenia dla Fib46 - Fib50:\n";
    for (int n = 46; n <= 50; n++) {
        cout << "n = " << n << ":\n";
        cout << "Iteracyjnie: " << fibIter(n) << "\n";
    }

    // Test 3: Porównanie szybkości działania dla Fib46 - Fib50
    cout << "\nPorównanie czasu działania (w mikrosekundach):\n";
    for (int n = 46; n <= 50; n++) {
        clock_t start, end;

        // Czas dla metody rekurencyjnej
        start = clock();
        fibRec(n);
        end = clock();
        cout << "Rekurencyjnie (n = " << n << "): " << (end - start) * 1000000 / CLOCKS_PER_SEC << " us\n";

        // Czas dla metody iteracyjnej
        start = clock();
        fibIter(n);
        end = clock();
        cout << "Iteracyjnie (n = " << n << "): " << (end - start) * 1000000 / CLOCKS_PER_SEC << " us\n";
    }

    return 0;
}
