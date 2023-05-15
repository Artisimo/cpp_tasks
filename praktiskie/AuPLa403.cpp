/*
AuPLa0403. Sastādīt C++ programmu, kas dotam naturālam skaitlim nosaka lielāko ciparu pierakstā.
Risinājuma iegūšanai sastādīt funkciju, kura naturālam skaitlim nosaka lielāko ciparu pierakstā.
*/

//autors: Artis Birznieks ab21296
// datums: 29.09.2021.

#include <iostream>

using namespace std;

int NoteiktLielakoCiparu(int skaitlis){
    int rez;
    int cipars;
    do{
        cipars = skaitlis % 10;
        if(cipars > rez){
            rez = cipars;
        }
        skaitlis = skaitlis / 10;
    }while(skaitlis >= 1);

    return rez;
}

int main(){

    int ok;
    int skaitlis;
    int cipars;
    int rez;
    do{
        cout << "Ievadi naturalu skaitli: " << endl;
        cin >> skaitlis;

        rez = NoteiktLielakoCiparu(skaitlis);

        cout << "Lielakais cipars skaitlii " << skaitlis << " ir " << rez << endl;


        cout << "Turpinat (1) vai beigt (0) ?" << endl;
        cin >> ok;
    }while(ok == 1);


}
