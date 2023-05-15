
/*
A17. Doti 4 naturāli skaitļi a, b, c, d. Salikt skaitļus pa pāriem tā, lai pāru kopsummas atšķirtos pēc iespējas mazāk.
*/

//autors: Artis Birznieks ab21296
//datums: 16.09.2021

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int a;
    int b;
    int c;
    int d;
    int ok;

    do{
        while (true) {
            cout << "Ievadi 4 naturālus skaitļus! (Atdali ar atstarpi, nelieto komatus.)" << endl;
            if ((cin >> a && a >= 0) &&
                (cin >> b && b >= 0) &&                                 // Pārliecinamies, vai ievadītie dati ir pareizi
                (cin >> c && c >= 0) &&
                (cin >> d && d >= 0)) {
                break;
            } else {

                cout << "Pārliecinies vai ievadītie dati ir pareizi! (Naturāli skaitļi, atdalīti ar atstarpi.)" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        int numbers[4];                                 //Izveidojam masīvu.

        numbers[0] = a;                                 //Saliekam masīva skaitļus, ko ievadījis lietotājs.
        numbers[1] = b;
        numbers[2] = c;
        numbers[3] = d;

        int temp;
                for(int i=0;i<4;i++){
                    for(int j=i+1;j<4;j++){
                        if(numbers[i]>numbers[j]){
                            temp  =numbers[i];          // Sakārtojam masīvu augošā secībā.
                            numbers[i] = numbers[j];
                            numbers[j]=temp;
                        }
                    }
                }

        cout << "Pirmais pāris: " << numbers[0] << " + " << numbers[3] << " = " << numbers[0] + numbers[3] << endl;
        cout << "Otrais pāris: " << numbers[1] << " + " << numbers[2] << " = " << numbers[1] + numbers[2] << endl;
        //Izdrukājam rezultātu, saskaitot pirmo(mazāko) un pēdējo(lielāko) elementu masīvā, un 2. un 3. elementu masīvā.

        cout << "Turpināt (1) vai beigt (0) ?" << endl;
        cin >> ok;
    }while(ok == 1);


    return 0;
}

    /************************************************
    *    INPUT:                 OUTPUT:             *
    *   1   2   3   4           5   5               *
    *   4   3   2   1           5   5               *
    *   1   1   1   1           2   2               *
    *   -1  1   1   1         Parliecinaties vai    *
    *                          ievaditie dati       *
    *                            ir pareizi         *
    *   1.1 1   1   1         Parliecinaties vai    *
    *                          ievaditie dati       *
    *                            ir pareizi         *
    *    a   1  2   3         Parliecinaties vai    *
    *                          ievaditie dati       *
    *                            ir pareizi         *
    *                                               *
    *                                               *
    *                                               *
    *                                               *
    *                                               *
    *                                               *
    *************************************************/
