// Matura_Czerwiec_2024_Zad4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

//fstream plik("odbiorcy_przyklad1.txt");
//int const N = 6;
//fstream plik("odbiorcy_przyklad.txt");
//int const N = 16;
fstream plik("odbiorcy.txt");
int const N = 1024;

int przesylanie[N + 1][N + 1];//musi być przed main, bo było przepełnienie stosu

int Dominanta(vector<int> v) {
    sort(v.begin(), v.end());
    int najw = 1, akt = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1]) ++akt;
        else {
            najw = max(akt, najw);
            akt = 1;
        }
        najw = max(najw, akt); 
    }
    return najw;
}

int main()
{
    cout << "Zad 4.2" << endl;
    vector <int> odbiorcy;
    string linia;

    while (getline(plik, linia)) {
        odbiorcy.push_back(stoi(linia));
    }

    int licz = 0;
    for (int i = 1; i <= N; i++) {
        if (find(odbiorcy.begin(), odbiorcy.end(), i) == odbiorcy.end()) {
            licz++;
        }
    }
    cout << "ilosc komp bez pakietow: " << licz << endl;

    cout << "Zad 4.3" << endl;
    cout<< "runda, pakiet:" << endl;

    int pakiet = N;

    //int przesylanie[N+1][N + 1];

    for (int pakiet = 1; pakiet <= N; pakiet++) {
        przesylanie[1][pakiet] = odbiorcy[pakiet - 1];//pakiet-1, bo naprawdę są liczone od 0
    }

    bool flaga = false;

    for (int runda = 2; runda <= N; runda++) {
        for (int pakiet = 1; pakiet <= N; pakiet++) {
            przesylanie[runda][pakiet] = odbiorcy[przesylanie[runda - 1][pakiet] - 1];
           if (przesylanie[runda][pakiet] == pakiet) {
                cout << runda << " " << pakiet << endl;
                flaga = true;
                break;
            }
        }
        if (flaga == true) break;
    }

    cout << "Zad 4.4" << endl;
    //UWAGA w 4.3 przerwaliśmy wypełnianie tablicy, trzeba nadpisać
    for (int runda = 2; runda <= N; runda++) {
        for (int pakiet = 1; pakiet <= N; pakiet++) {
            przesylanie[runda][pakiet] = odbiorcy[przesylanie[runda - 1][pakiet] - 1];
            }
        }

    vector<int> runda1, runda2, runda4, runda8;

    for (int pakiet = 1; pakiet <= N; ++pakiet) 
        runda1.push_back(przesylanie[1][pakiet]);

    for (int pakiet = 1; pakiet <= N; ++pakiet) 
        runda2.push_back(przesylanie[2][pakiet]);

    for (int pakiet = 1; pakiet <= N; ++pakiet) 
        runda4.push_back(przesylanie[4][pakiet]);

    for (int pakiet = 1; pakiet <= N; ++pakiet) 
        runda8.push_back(przesylanie[8][pakiet]);

    int m1 = Dominanta(runda1);
    int m2 = Dominanta(runda2);
    int m4 = Dominanta(runda4);
    int m8 = Dominanta(runda8);

    cout << m1 << " " << m2 << " " << m4 << " " << m8 << "\n";


    cout << "Zad.6 - podp." << endl;
    cout<<stoi("203", nullptr, 5) + stoi("4401", nullptr, 5) << endl;
    cout << stoi("4541", nullptr, 6) - stoi("2455", nullptr, 6) << endl;
}
