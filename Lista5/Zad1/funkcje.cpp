#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

using namespace std;

int tab[3][3], mod;

//budowanie resetuje plansze do wartosci domyslnych z kazdym restartem gry
void budowanie() {

    int iteracja = 0;
    mod = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tab[i][j] = iteracja;
            iteracja++;
        }
    }
}

void rysowanie() {

    int l = 0;

    cout << "    0   1   2 -> X" << endl;

    for(int i = 0; i < 3; i++) {
        cout << l << " ";
        l += 3;
        for(int j = 0; j < 3; j++) {
            cout << "|";
            if(tab[i][j] == 'X') printf(" x ");
            else if(tab[i][j] == 'O') printf(" o ");
            else if(j < 3) cout << "___";
            if(j == 2) cout << "|";
        }
        cout << endl;
    }
    cout << "Y |" << endl;
}

void wpisywanie() {

    int pole;
    mod %= 2;

    if (mod == 1) cout << "Gracz 1 (x)" << endl;
    if (mod == 0) cout << "Gracz 2 (o)" << endl;

    cout << "Wybierz pole (X + Y)" << endl;
    cin >> pole;
    system("cls");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (pole == tab[i][j]) {
                if (mod == 1) tab[i][j] = 'X';
                if (mod == 0) tab[i][j] = 'O';
            }
        }
    }

    mod++;

    rysowanie();
}

void wpisywanieZAI() {
    int pole;

    cout << "Gracz 1 (x)" << endl;
    cout << "Wybierz pole (X + Y)" << endl;
    cin >> pole;
    system("cls");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (pole == tab[i][j]) {
                tab[i][j] = 'X';
            }
        }
    }
    rysowanie();
}

int sprawdzanie() {

        int sprawdzanie = 0;

    for(int i = 0; i < 3; i++) {
        //sprawdzanie bokow
        if(tab[i][0] == tab[i][1] && tab[i][0] == tab[i][2] || tab[0][i] == tab[1][i] && tab[0][i] == tab[2][i]) {
            sprawdzanie = 1;
            return sprawdzanie;
        }

        //sprawdzanie przekatnych
        if(tab[0][0] == tab[1][1] && tab[0][0] == tab[2][2] || tab[0][2] == tab[1][1] && tab[0][2] == tab[2][0]) {
            sprawdzanie = 1;
            return sprawdzanie;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tab[i][j] != 'X' && tab[i][j] != 'O') sprawdzanie = 0;
        }
    }

    return sprawdzanie;
}

void AI() {

    srand(time(NULL));

    int a, pos = 0;

    m:for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(pos != 1 && tab[i][j] != 'X' && tab[i][j] != 'O') {
                a = rand() % 2;
                if(a == 1) {
                    tab[i][j] = 'O';
                    pos++;
                }
            }
        }
    }

    if (a == 0) goto m;

    rysowanie();
}
