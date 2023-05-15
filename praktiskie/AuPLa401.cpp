/*

AuPLa0401. Sastādīt C++ programmu, kas dotam naturālam skaitlim nosaka dota cipara skaitu pierakstā.
Risinājuma iegūšanai sastādīt funkciju, kura naturālam skaitlim nosaka dota cipara skaitu pierakstā.
*/

// autors: Artis Birznieks ab21296
// datums: 29.09.2021.

#include <iostream>

using namespace std;

static void NoteiktCiparuSkaitu(int n, int m){ //n - skaitlis, m - cipars

    int skaitlis = n;
    int cipars;
    int arr[10];
    int ciparaSkaits;

    for(int i = 0; i < 10; i++){
        arr[i] = 0;
    }

    do{
          cipars = n % 10;
          n = n / 10;
          arr[cipars] = arr[cipars] + 1;


    }while(n >= 1);

    cout << "cipars " << m << " skaitlii " << skaitlis << " paraadaas " << arr[m] << " reizes" << endl;
}


int main(){
    int ok;
    int n;
    int m;
    bool a;
    bool b;

    do{

        cout << "ievadi naturalu skaitli: " << endl;
        cin >> n;
        cout << "Naturals skaitlis: " << n << endl;


        cout << "Ievadi ciparu: " << endl;
        cin >> m;
        cout << "Cipars: " << m << endl;

        NoteiktCiparuSkaitu(n, m);

        cout << "Turpinat (1) vai beigt (0) ?" << endl;
        cin >> ok;
    }while(ok == 1);

return 0;

}

