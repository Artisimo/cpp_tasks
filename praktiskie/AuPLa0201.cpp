/********************************************************************************************************************
AuPLa0201. Izveidot C++ programmu, kura pārvērš Fārenheita grādos uzdotu temperatūru par temperatūru Celsija grādos.
 Formula pārvēršanai:
C = 5/9(F-32)
Jābūt iespējai programmu izpildīt atkārtoti, neizejot no programmas.
*********************************************************************************************************************/
// autors: Artis Birznieks 21296
// datums: 15.09.2021

#include <iostream>
using namespace std;

int main(){

    float F;
    float C;
    int ok;

    do{

        cout << "Ievadiet Farenheita grados uzdotu temperaturu:" << endl;
        cin >> F;
        C = 5/9.0 * (F - 32);
        cout << "Temperatura Celsija grados:" << C << endl;

        cout << "Vai turpinat (1) vai beigt (0)" << endl;
        cin >> ok;

    }while(ok == 1);
}


    /*************Testu plans*********
            97.88           36.6
            32              0
            0               -17.77
    **********************************/
