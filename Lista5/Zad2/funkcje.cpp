#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "header.h"

using namespace std;

int mod;

vector<vector<int>> vec;
int a;

void tablica(int rozmiar) {
    vec.resize(rozmiar);
    a = rozmiar;
}

//budowanie resetuje plansze do wartosci domyslnych z kazdym restartem gry
void budowanie() {

    int iteracja = 0;
    mod = 1;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            vec[i].push_back(iteracja);
            iteracja++;
        }
    }
}

void rysowanie() {

    int l = 0, p = 0;

    cout << "  ";
    for (int k = 0; k < vec.size(); k++) {
        printf("%4d", k);
    }
    cout << endl;

    for(int i = 0; i < vec.size(); i++) {
        printf("%3d", l);
        l += a;
        for(int j = 0; j < vec.size(); j++) {
            cout << "|";
            if(vec[i][j] == 'X') printf(" x ");
            else if(vec[i][j] == 'O') printf(" o ");
            else if(j < vec.size()) cout << "___";
            if(j == vec.size() - 1) cout << "|";
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

    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec.size(); j++) {
            if (pole == vec[i][j]) {
                if (mod == 1) vec[i][j] = 'X';
                if (mod == 0) vec[i][j] = 'O';
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

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (pole == vec[i][j]) {
                vec[i][j] = 'X';
            }
        }
    }
    rysowanie();
}

int sprawdzanie() {

    //Sprawdzanie gracza 1

        int sprawdzanie = 0;

        int r = 0, h = 0, p = 0, p2 = 0, k = 0;

        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec.size(); j++) {
                if (i == i && vec[i][j] == 'X') r++;
                if (j == j && vec[j][i] == 'X') h++;
                if (i == j && vec[i][j] == 'X') p++;
                if (i + j == vec.size() - 1 && vec[i][j] == 'X') p2++;
            }

            if (r == vec.size() || h == vec.size() || p == vec.size() || p2 == vec.size()) {
                sprawdzanie = 1;
                return sprawdzanie;
            }

            h = 0;
            r = 0;
        }

        //Sprawdzanie gracza 2

        r = 0, h = 0, p = 0, p2 = 0, k = 0;

        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec.size(); j++) {
                if (i == i && vec[i][j] == 'O') r++;
                if (j == j && vec[j][i] == 'O') h++;
                if (i == j && vec[i][j] == 'O') p++;
                if (i + j == vec.size() - 1 && vec[i][j] == 'O') p2++;
            }

            if (r == vec.size() || h == vec.size() || p == vec.size() || p2 == vec.size()) {
                sprawdzanie = 1;
                return sprawdzanie;
            }

            h = 0;
            r = 0;
        }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (vec[i][j] != 'X' && vec[i][j] != 'O') sprawdzanie = 0;
        }
    }

    return sprawdzanie;
}

void AI() {

    srand(time(NULL));

    int a, pos = 0;

    m:for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec.size(); j++) {
            if(pos != 1 && vec[i][j] != 'X' && vec[i][j] != 'O') {
                a = rand() % 2;
                if(a == 1) {
                    vec[i][j] = 'O';
                    pos++;
                }
            }
        }
    }

    if (a == 0) goto m;

    rysowanie();
}
