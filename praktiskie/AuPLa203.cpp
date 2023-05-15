
/*
AuPLa0203.
Izveidot C++ programmu, kas aprēķina funkcijas f(x) vērtību y.
Funkcija f(x) uzdota ar sakarību:
 y ir 0, ja x mazāks par -2;
 y ir –x-2, ja x ir robežās no -2 līdz -1;
 y ir x, ja x ir robežās no -1 līdz 1(neieskaitot);
 y ir –x+2, ja x ir robežās no 1 līdz 2(neieskaitot);
 y ir 0, ja x ir lielāks vai vienāds ar 2.
Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.
*/

//autors: Artis Birznieks ab21296
// datums: 15.09.2021

#include <iostream>
using namespace std;

int main(){

    int ok;
    float x;
    float y;

    do{

        cout << "ievadiet argumenta x veertibu" << endl;
        cin >> x;
        if(x < -2)                              y = 0;
        else if(x >= -2 && x <= -1)             y = -x-2;
            else if(x >= -1 && x < 1)           y = x;
                else if(x >= 1 && x < 2)        y = -x + 2;
                    else                        y = 0;

        cout << "Funkcijas F(x) vertiba = " << y << endl;
        cout << "Turpinat (1) vai beigt (0)?" <<endl;
        cin >> ok;


    }while(ok == 1);

}



/*************** Testu plans *************************
        x                   paredzamais rezultats
        -3                      0
        -2                      0
        -1.5                    -0.5
        -1                      -1
        0                       0
        1                       1
        1.5                     05
 ***************************************************/
