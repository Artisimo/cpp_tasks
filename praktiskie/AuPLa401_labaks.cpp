
/*
AuPLa0401. Sastādīt C++ programmu, kas dotam naturālam skaitlim nosaka dota cipara skaitu pierakstā.
 Risinājuma iegūšanai sastādīt funkciju, kura naturālam skaitlim nosaka dota cipara skaitu pierakstā.
 */

 //autors: Artis Birznieks ab21296
 // datums: 29.09.2021.


 #include <iostream>

 using namespace std;

 int NoteiktCiparuSkaitu(int n, int m){

    int rez = 0;
    int cipars;
    do{
        cipars = n  % 10;
        n = n / 10;

        if(cipars == m){
            rez += 1;
        }
    }while(n >= 1);
    return rez;
 }


 int main(){

    int ok;
    int n;
    int m;
    int rez;
    do{
        cout << "Ievadi naturalu skaitli: " << endl;
        cin >> n;

        cout << "Ievadi ciparu:" << endl;
        cin >> m;

        rez = NoteiktCiparuSkaitu(n, m);

        cout << "Cipars " << m << " skaitlii " << n << " paradas " << rez << " reizes." << endl;


        cout << "Turpinat (1) vai beigt (0) ?" << endl;
        cin >> ok;
    }while(ok == 1);
 }

