
/*
AuPLa0303. Sastādīt C++ programmu, kas pieprasa ievadīt N veselus skaitļus un nosaka lielākā skaitļa vērtību.
Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.
*/

// autors: Artis Birznieks ab21296
// datums: 22.09.2021

#include <iostream>
using namespace std;

int main(){

int ok;
int n;
int lielakaisSkaitlis;
int ievaditaisSkaitlis;

do{
    do{
        cout << "Ievadi skaitlu skaitu:" << endl;
        cin >> n;
        if(n < 1){
            cout << "nekonkreta vertiba, ievadiet n >=1" << endl;

        }
    }while(n < 1);


    for(int i = 0; i < n; i++){

        do{
            cout << "Ievadiet veselu skaitli: " << endl;
            cin >> ievaditaisSkaitlis;
        }while(ievaditaisSkaitlis < 1);


        if(ievaditaisSkaitlis > lielakaisSkaitlis){
            lielakaisSkaitlis = ievaditaisSkaitlis;
        }
    }


    cout << "Lielakais skaitlis: " << lielakaisSkaitlis << endl;
    cout << "Turpinat (1) vai beigt (0) ?" << endl;
}while(ok == 1);

}
