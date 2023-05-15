/*********************************************************************************************
AuPLa0205.
Izveidot C++ programmu, kura ļauj ievadīt veselus skaitļus un aprēķina negatīvo skaitļu summu.
Ievade jābeidz tad, kad ievadīts skaitlis 0.
Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas
**********************************************************************************************/
//autors: Artis Birznieks ab21296
//datums: 15.09.2021

#include <iostream>
using namespace std;

int main(){

int ok;
int input=1;
bool validInput;
int galaRezultats;

do{
    input = 1;
    galaRezultats = 0;

    while(input != 0){

        cout << "Ieraksti veselu skaitli" << endl;
        cin >> input;

        if(input < 0){
            galaRezultats += input;

        }
        cout << "Gala rezultats sobrid ir: " << galaRezultats << endl;
    }
    cout << "gala rezultats ir: " << galaRezultats << endl;

    cout << "Turpinat (1) vai beigt (0) ?" << endl;
    cin >> ok;
}while(ok == 1);

}

/***************Testu plans*************************




****************************************************/
