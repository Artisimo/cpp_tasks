// PiPLa0101.cpp
// Autors: Artis Birznieks ab21296
// datums: 14.02.2022

/*PiPLa0101. Sastādīt C++ programmu, kas aprēķina, cik reizes dotajā teksta failā in0101.txt sastopams lietotāja dots simbols.
Dati no faila jānolasa pa vienai rindiņai. Nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Izdrukāt rezultātu.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream fin;
    string fvards;
    char simbols;
    string rindina;
    int simboluSkaits;
    int ok;

    do{
        simboluSkaits = 0;
        cout << "Ievadiet faila nosaukumu: " << endl;
        cin.clear();
        getline(cin, fvards);

        fin.open(fvards.c_str(), ios::in);
        if(!fin){
            cout << "Nav faila" << endl;
            return 13;
        }

        cout << "Ievadiet meklējamo simbolu: " << endl;
        cin.get(simbols);

        getline(fin, rindina);

        while(fin){
            for(int i = 0; i < rindina.length(); i++){
                if(rindina[i] == simbols){
                    simboluSkaits++;
                }
            }
            getline(fin, rindina);
        }

        cout << "Simbols " << simbols << " sastopams " << simboluSkaits << " reizes" << endl;
        fin.close();
        cout << "Turpināt (1) vai beigt (0) ?" << endl;
        cin >> ok;
        cin.clear();
        cin.ignore();
    }while(ok == 1);
    return 0;
}

/******************************Testa Plāns********************************
simbols                 in0101.txt                  paredzamais rezultāts

'a'                     "a b 1 a  "                    4
                        "? aa"
                        "fghjj"
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
'c'                                                    0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
' '                                                    6
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                        in0101a.txt
'a'                     "aaaaa aaa"                     8
***************************************************************************/

