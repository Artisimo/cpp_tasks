/*
AuPLa0503. Sastādīt C++ programmu, kas pieprasa ievadīt N veselus skaitļus un nosaka lielākā skaitļa vērtību.
Risinājumā jāizmanto funkcija lielakais(a, b), kas atgriež kā rezultātu lielāko no dotajiem veselajiem skaitļiem a un b.
Funkcijas lielākais(a, b) realizācijā jāizmanto nosacījuma funktors (conditional operator).
*/

// autors: Artis Birznieks, ab21296
// datums 05.10.2021.


#include <iostream>

using namespace std;


int lielakais(int a, int b){
    int lielakais = (a > b) ? a : b;
    return lielakais;
}

int main(){
    int ok;
    int skaitlis;
    int lielakaisSkaitlis;
    int counter = 0;
    do{
        cout << "ievadi veselu skaitli: " << endl;
        cin >> skaitlis;
        if(counter == 0){
            lielakaisSkaitlis = skaitlis;
        }
        else{
            lielakaisSkaitlis = lielakais(skaitlis, lielakaisSkaitlis);
        }


        counter++;
        cout << "lielākais skaitlis = " << lielakaisSkaitlis << endl;
        cout << "Turpināt (1) vai beigt (0) ?" << endl;
        cin >> ok;
    }while(ok == 1);
    //cout << lielakais(10, 20) << endl;


return 0;
}


