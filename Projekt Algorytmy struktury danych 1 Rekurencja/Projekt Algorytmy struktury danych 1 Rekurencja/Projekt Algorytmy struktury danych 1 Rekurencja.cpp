#include <iostream>
#include <limits> // Dla std::numeric_limits
using namespace std;

// Funkcja rekurencyjna dla ciągu a)
double sumaA(int n) {
    if (n == 1) {
        return 1; // baza rekurencji
    }
    return 1.0 / n + sumaA(n - 1);
}

// Funkcja rekurencyjna dla ciągu b)
double sumaB(int n) {
    if (n == 1) {
        return 1; // baza rekurencji
    }
    if (n % 2 == 0) {
        return -1.0 / n + sumaB(n - 1); // dla liczb parzystych zmieniamy znak
    }
    else {
        return 1.0 / n + sumaB(n - 1); // dla liczb nieparzystych dodajemy
    }
}

// Funkcja do pobierania poprawnego wejścia
int getValidatedInput() {
    int n;
    while (true) {
        cout << "Podaj liczbe calkowita: ";
        cin >> n;

        if (cin.fail()) {
            cin.clear(); // Czyści flagę błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Usuwa błędne dane z bufora
            cout << "Nieprawidlowa wartosc. Wprowadz liczbe calkowita!" << endl;
        }
        else if (n <= 0) {
            cout << "Liczba musi byc dodatnia. Sprobuj ponownie." << endl;
        }
        else {
            return n; // Poprawne wejście
        }
    }
}

int main() {
    int n;

    // Test dla ciągu a)
    cout << "Test dla ciagu a:" << endl;
    n = getValidatedInput();
    cout << "Suma dla ciagu a dla n=" << n << " wynosi: " << sumaA(n) << endl;

    // Test dla ciągu b)
    cout << "Test dla ciagu b:" << endl;
    n = getValidatedInput();
    cout << "Suma dla ciagu b dla n=" << n << " wynosi: " << sumaB(n) << endl;

    return 0;
}
