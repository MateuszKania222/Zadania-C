#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Book {
    string tytul;
    string autor;
    int rokWydania;
    bool status;

    void displayBook() const {
        cout << "  Tytuł: " << tytul << "\n"
            << "  Autor: " << autor << "\n"
            << "  Rok wydania: " << rokWydania << "\n"
            << "  Status: " << (status ? "Wypożyczona" : "Dostępna") << "\n";
        cout << "------------------------------------" << endl;
    }
};

struct Person {
    string imie;
    string nazwisko;
    int ID;
    vector<Book> wypozyczoneKsiazki;

    void displayPerson() const {
        cout << "Imię: " << imie << ", Nazwisko: " << nazwisko << "\n";
        cout << "ID: " << ID << "\n";
        cout << "Wypożyczone książki:" << endl;
        if (wypozyczoneKsiazki.empty()) {
            cout << "  Brak wypożyczonych książek.\n";
        }
        else {
            for (const auto& ksiazka : wypozyczoneKsiazki) {
                ksiazka.displayBook();
            }
        }
        cout << "====================================" << endl;
    }
};

// Reszta kodu (bez zmian)

int generujLosowyID(set<int>& istniejąceID) {
    int noweID;
    do {
        noweID = rand() % 9000 + 1000;
    } while (istniejąceID.count(noweID) > 0);
    istniejąceID.insert(noweID);
    return noweID;
}

bool czyZawieraTylkoLitery(const string& tekst) {
    for (char c : tekst) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

void wyszukajPoID(vector<Person>& osoby, int szukaneID) {
    cout << "\n--- Wyszukiwanie po ID ---\n";
    for (auto& osoba : osoby) {
        if (osoba.ID == szukaneID) {
            osoba.displayPerson();
            return;
        }
    }
    cout << "Nie znaleziono osoby z ID: " << szukaneID << endl;
    cout << "--------------------------\n";
}

void wyszukajPoImieniuNazwisku(vector<Person>& osoby, const string& imie, const string& nazwisko) {
    cout << "\n--- Wyszukiwanie po imieniu i nazwisku ---\n";
    for (auto& osoba : osoby) {
        if (osoba.imie == imie && osoba.nazwisko == nazwisko) {
            osoba.displayPerson();
            return;
        }
    }
    cout << "Nie znaleziono osoby o imieniu i nazwisku: " << imie << " " << nazwisko << endl;
    cout << "------------------------------------------\n";
}

void dodajKsiazke(vector<Person>& osoby, int ID, const Book& nowaKsiazka) {
    cout << "\n--- Dodawanie książki ---\n";
    for (auto& osoba : osoby) {
        if (osoba.ID == ID) {
            osoba.wypozyczoneKsiazki.push_back(nowaKsiazka);
            cout << "Dodano książkę do listy wypożyczonych książek!\n";
            cout << "------------------------------------------\n";
            return;
        }
    }
    cout << "Nie znaleziono osoby z ID: " << ID << endl;
    cout << "------------------------------------------\n";
}

void usunKsiazke(vector<Person>& osoby, int ID, const string& tytulKsiazki) {
    cout << "\n--- Usuwanie książki ---\n";
    for (auto& osoba : osoby) {
        if (osoba.ID == ID) {
            auto& ksiazki = osoba.wypozyczoneKsiazki;
            for (auto it = ksiazki.begin(); it != ksiazki.end(); ++it) {
                if (it->tytul == tytulKsiazki) {
                    ksiazki.erase(it);
                    cout << "Usunięto książkę z listy wypożyczonych książek!\n";
                    cout << "------------------------------------------\n";
                    return;
                }
            }
            cout << "Nie znaleziono książki o tytule: " << tytulKsiazki << endl;
            cout << "------------------------------------------\n";
            return;
        }
    }
    cout << "Nie znaleziono osoby z ID: " << ID << endl;
    cout << "------------------------------------------\n";
}

void wyswietlWszystkich(const vector<Person>& osoby) {
    cout << "\n--- Lista wszystkich osób w bibliotece ---\n";
    if (osoby.empty()) {
        cout << "Brak osób w bibliotece.\n";
        cout << "------------------------------------------\n";
        return;
    }

    for (const auto& osoba : osoby) {
        osoba.displayPerson();
        cout << "-----------------------\n";
    }
}

int main() {
    setlocale(LC_ALL, "polish");
    srand(time(0));

    vector<Person> osoby;
    set<int> istniejąceID;
    vector<Book> ksiazki = {
        {"W pustyni i w puszczy", "Henryk Sienkiewicz", 1911, false},
        {"Lalka", "Bolesław Prus", 1890, false},
        {"Pan Tadeusz", "Adam Mickiewicz", 1834, false}
    };

    int wybor;

    while (true) {
        cout << "\n======== MENU GŁÓWNE ========\n";
        cout << "1. Dodaj nową osobę do biblioteki\n";
        cout << "2. Wyszukaj osobę po ID\n";
        cout << "3. Wyszukaj osobę po imieniu i nazwisku\n";
        cout << "4. Dodaj książkę do listy wypożyczonych książek\n";
        cout << "5. Usuń książkę z listy wypożyczonych książek\n";
        cout << "6. Wyświetl wszystkie osoby i ich wypożyczone książki\n";
        cout << "7. Wyjście\n";
        cout << "=============================\n";
        cout << "Wybierz opcję: ";
        cin >> wybor;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (wybor) {
        case 1: {
            Person newPerson;
            do {
                cout << "\nPodaj imię: ";
                getline(cin, newPerson.imie);
                if (!czyZawieraTylkoLitery(newPerson.imie)) {
                    cout << "Błąd: Imię nie może zawierać cyfr!\n";
                }
            } while (!czyZawieraTylkoLitery(newPerson.imie));

            do {
                cout << "Podaj nazwisko: ";
                getline(cin, newPerson.nazwisko);
                if (!czyZawieraTylkoLitery(newPerson.nazwisko)) {
                    cout << "Błąd: Nazwisko nie może zawierać cyfr!\n";
                }
            } while (!czyZawieraTylkoLitery(newPerson.nazwisko));

            newPerson.ID = generujLosowyID(istniejąceID);
            osoby.push_back(newPerson);
            cout << "\nDodano nową osobę do biblioteki! Przypisany ID: " << newPerson.ID << endl;
            break;
        }
        case 2: {
            int szukaneID;
            cout << "\nPodaj ID osoby do wyszukania: ";
            cin >> szukaneID;
            wyszukajPoID(osoby, szukaneID);
            break;
        }
        case 3: {
            string imie, nazwisko;
            cout << "\nPodaj imię: ";
            getline(cin, imie);
            cout << "Podaj nazwisko: ";
            getline(cin, nazwisko);
            wyszukajPoImieniuNazwisku(osoby, imie, nazwisko);
            break;
        }
        case 4: {
            int ID;
            cout << "\nPodaj ID osoby: ";
            cin >> ID;
            cin.ignore();
            cout << "\nDostępne książki do wypożyczenia:\n";
            for (size_t i = 0; i < ksiazki.size(); ++i) {
                cout << i + 1 << ". ";
                ksiazki[i].displayBook();
            }
            int wyborKsiazki;
            cout << "Wybierz numer książki: ";
            cin >> wyborKsiazki;
            if (wyborKsiazki >= 1 && wyborKsiazki <= ksiazki.size()) {
                Book nowaKsiazka = ksiazki[wyborKsiazki - 1];
                nowaKsiazka.status = true;
                dodajKsiazke(osoby, ID, nowaKsiazka);
            }
            else {
                cout << "Niepoprawny wybór.\n";
            }
            break;
        }
        case 5: {
            int ID;
            cout << "\nPodaj ID osoby: ";
            cin >> ID;
            cin.ignore();
            string tytulKsiazki;
            cout << "Podaj tytuł książki do usunięcia: ";
            getline(cin, tytulKsiazki);
            usunKsiazke(osoby, ID, tytulKsiazki);
            break;
        }
        case 6:
            wyswietlWszystkich(osoby);
            break;
        case 7:
            cout << "\nDo widzenia!\n";
            return 0;
        default:
            cout << "\nNiepoprawny wybór. Spróbuj ponownie.\n";
            break;
        }
    }
    return 0;
}


