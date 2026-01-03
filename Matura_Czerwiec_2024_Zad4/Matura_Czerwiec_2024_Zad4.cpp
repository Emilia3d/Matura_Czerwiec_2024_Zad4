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
    //int n = 16;
    fstream plik("odbiorcy.txt");
    int n = 1024;
    
    cout << "Zad 4.2" << endl;
    vector <int> odbiorcy;
    string linia;
    int odbiorca;
    while (getline(plik, linia)) {
        odbiorcy.push_back(stoi(linia));
    }
    int licz = 0;
    for (int i = 1; i <= n; i++) {
        if (find(odbiorcy.begin(), odbiorcy.end(), i) == odbiorcy.end()) {
            licz++;
        }
    }
    cout << licz << endl;

    cout << "Zad 4.3" << endl;
}
