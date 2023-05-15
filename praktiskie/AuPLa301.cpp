/*
AuPLa0301. Sastādīt C++ programmu, kas dotam naturālam skaitlim N aprēķina faktoriāla funkcijas vērtību.
Naturāla skaitļa N>=1 faktoriālu definē šādi:
N! = 1 * 2 * 3 * (N-1) * N
Ir pieņemts, ka tukšais reizinājums jeb reizinājums, kurā neietilpst neviens skaitlis, ir vienāds ar 1, tāpēc
0! = 1.
Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.
*/

// Autors: Artis Birznieks ab21296
// Datums: 22.09.2021

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){

int ok;
unsigned long long int fakt;
int n;
cout << "maksimaalaa vesela skaitla vertiba sajaa datoraa: " << ULLONG_MAX << endl;
do{
    fakt = 1;
    while(true){
        cout << "Ievadi naturalu skaitli" << endl;
        if(cin >> n && n >= 0 && n < 21){
            break;
        }
        else{
            cout << "Parliecinies, vai ievaditie dati ir pareizi! (Naturali skaitli, 0 <= N <= 20)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    if(n == 0){
        fakt = 1;
    }
    else{
        for(int i = 1; i <= n; i++){
        fakt *= i;
        }
    }

    cout << n << "! = " << fakt << endl;

    cout <<  "Turpinat (1) vai beigt (0) ?" << endl;
    cin >> ok;
    fakt = 1;
}while(ok == 1);
}

