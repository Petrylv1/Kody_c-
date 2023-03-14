#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include "header.h"
#include "funkcje.cpp"

using namespace std;

int main() {

    int ruchy, sp, wyb, rozmiar;

    m:cout << "Podaj rozmiary planszy" << endl;
    cin >> rozmiar;

    tablica(rozmiar);

    rozmiar *= rozmiar;

    cout << "Kolko i Krzyzyk" << endl;
    cout << "1. Rozgrywka z druga osoba" << endl;
    cout << "2. Rozgrywka z AI" << endl;
    cin >> wyb;

    if (wyb == 1) {
        ruchy = 0;
        system("cls");
        budowanie(); //budowanie planszy/resetowanie
        rysowanie(); //rysowanie planszy

        do {

            wpisywanie();
            sp = sprawdzanie();
            ruchy++;
            if (sp == 1 || ruchy == rozmiar) break;

        } while (ruchy < rozmiar);
    }

    else if (wyb == 2) {
        ruchy = 0;
        system("cls");
        budowanie();
        rysowanie();

        do {
            wpisywanieZAI();
            sp = sprawdzanie();
            ruchy++;

            if (sp == 1 || ruchy == rozmiar) break;

            //AI
            system("cls");
            AI();
            sp = sprawdzanie();
            ruchy++;

            if (sp == 1 || ruchy == rozmiar) break;
        } while (ruchy < rozmiar);
    }

    else {
        system("cls");
        cout << "Bledna wartosc!" << endl;
        Sleep(2000);
        system("cls");
        goto m;
    }

    if (sp == 1 && ruchy % 2 == 1) cout << endl << "Koniec gry!" << endl << "Gracz 1 (x) wygral" << endl << endl;
    else if (sp == 1 && ruchy % 2 == 0) cout << endl << "Koniec gry!" << endl << "Gracz 2 (o) wygral" << endl << endl;
    else cout << endl << "Koniec gry!" << endl << "Remis!" << endl << endl;

    cout << "Zagrac jeszcze raz?" << endl;
    cout << "1.Tak" << endl;
    cout << "2.Nie" << endl;
    cin >> wyb;
    cout << endl;

    if (wyb == 1) {
        system("cls");
        cout << "Wczytywanie..." << endl;
        Sleep(1000);
        system("cls");
        goto m;
    }
    else return 0;

    return 0;
}
