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
    fstream plik("odbiorcy_przyklad1.txt");
    int const N = 6;
    //fstream plik("odbiorcy_przyklad.txt");
    //int const N = 16;
    //fstream plik("odbiorcy.txt");
    //int const N = 1024;
    
    cout << "Zad 4.2" << endl;
    vector <int> odbiorcy;
    string linia;
    
    while (getline(plik, linia)) {
        odbiorcy.push_back(stoi(linia));
    }
    
    int licz = 0;
    for (int i = 0; i <N; i++) {
        if (find(odbiorcy.begin(), odbiorcy.end(), i) == odbiorcy.end()) {
            licz++;
        }
    }
    cout << "ilosc komp bez pakietów"<<licz << endl;

    for (int i = 0; i <N ; i++) {
        cout << odbiorcy[i]<<endl;
    }
    
    cout << "Zad 4.3" << "r-runda, p-pakiet "<<endl;
    
    int pakiet = N;

    int przesylanie[101][N + 1];

    for (int pakiet = 1; pakiet <= N; pakiet++) {
        przesylanie[1][pakiet] = odbiorcy[pakiet - 1];//pakiet-1, bo naprawdę są liczone od 0

    }

    for (int runda = 2; runda <= 6; runda++) {
        for (int pakiet = 1; pakiet <= N; pakiet++) {
            przesylanie[runda][pakiet] = odbiorcy[przesylanie[runda - 1][pakiet] - 1];
            cout << "r"<<runda << "p" << pakiet << "-" << przesylanie[runda][pakiet]<<"  ";
            //if (przesylanie[runda][pakiet] == pakiet) {
                //cout << runda << " " << pakiet << endl;
            //return 0;
            //}
        }
        cout << endl;
    }

    
    cout << "Zad 4.4" << endl;
    vector <int> zad4_4_runda1;
    vector <int> zad4_4_runda2;
    vector <int> zad4_4_runda4;
    vector <int> zad4_4_runda8;

    //wypisujemy i sortujemy wartości dla każdej rundy 2
    for (int pakiet = 1; pakiet <= N; pakiet++) {
        zad4_4_runda1.push_back(przesylanie[2][pakiet-1]);
    }

    sort(zad4_4_runda1.begin(), zad4_4_runda1.end());
    //Wyszukujemy najczęstszą wartość
    for (int i = 1; i < zad4_4_runda1.size(); i++)
        cout << zad4_4_runda1[i]<<endl;
    
}