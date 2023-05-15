// Autors: Artis Birznieks ab21296
// Datums: 14.02.2022

//Pārveidot programmu txt6get.cpp, lai tiktu aprēķināti dotajā failā esošo simbolu biežumi. Izdrukāt biežumus.
//Dati no faila jānolasa pa vienai rindiņai. Nedrīkst dublēt visa faila saturu operatīvajā atmiņā.

#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
    fstream fin;
    char c;
    string rindina;
    int biezums[256] = {0};
    int filesize = 0;
    fin.open ("txt_in6.txt", ios::in);
    getline(fin, rindina);
    while (fin)
    {
        for(int i = 0; i < rindina.length(); i++){
            biezums[rindina[i]]++;
        }
        getline(fin, rindina);
    };
    fin.close ();
    for(int i= 0; i < 256; i++){
        if (biezums[i] != 0){
            cout << char(i) << " " << biezums[i] << endl;
        }
    }
    cout << filesize << endl;
    return 0;
}


