/*
AuPLa0501.
Sastādīt C++ programmu, kas noskaidro, vai doto naudas daudzumu var izveidot,
lietojot pa vienai reizei tikai divas no dotajām trīs monētām – 1, 2 un 5 centu monētas.
Realizācijā jālieto priekšraksts „switch”.*/

//autors: Artis Birznieks
// datums: 05.10.2021.

#include <iostream>

using namespace std;

int main(){

int naudasDaudzums;

cout << "Ievadi naudas daudzumu" << endl;
cin >> naudasDaudzums;

switch(naudasDaudzums){
case 3:
    cout << naudasDaudzums << " var izveidot lietojot 1 centu un 2 centu monētas." << endl;
    break;
case 6:
    cout << naudasDaudzums << " var izveidot lietojot 1 centu un 5 centu monētas." << endl;
    break;
case 7:
    cout << naudasDaudzums << " var izveidot lietojot 2 centu un 5 centu monētas." << endl;
    break;
}




return 0;
}


