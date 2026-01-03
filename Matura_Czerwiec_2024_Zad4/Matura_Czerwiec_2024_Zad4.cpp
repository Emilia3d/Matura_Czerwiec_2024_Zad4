// Matura_Czerwiec_2024_Zad4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    //fstream plik("odbiorcy_przyklad.txt");
    //int const N = 16;
    fstream plik("odbiorcy.txt");
    int const N = 1024;
    
    cout << "Zad 4.2" << endl;
    vector <int> odbiorcy;
    string linia;
    int odbiorca;
    while (getline(plik, linia)) {
        odbiorcy.push_back(stoi(linia));
    }
    int licz = 0;
    for (int i = 1; i <= N; i++) {
        if (find(odbiorcy.begin(), odbiorcy.end(), i) == odbiorcy.end()) {
            licz++;
        }
    }
    cout << licz << endl;
    plik.clear();
    plik.seekg(0);

    cout << "Zad 4.3" << endl;
    
    int pakiet = N;

    int przesylanie[101][N+1];

    for (int pakiet = 1; pakiet <= N; pakiet++) {
        przesylanie[1][pakiet] = odbiorcy[pakiet - 1];

    }

     for (int runda = 2; runda <= 100; runda++) {
        for (int pakiet = 1; pakiet <= N; pakiet++) {
            przesylanie[runda][pakiet] = odbiorcy[przesylanie[runda - 1][pakiet]-1];
            if (przesylanie[runda][pakiet] == pakiet){
                cout << runda << " " << pakiet << endl;
                return 0;
            }

        }
    }
    
    cout << "Zad 4.4" << endl;
}
