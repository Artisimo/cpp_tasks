/*
B6. Doti naturāli skaitļi m un n.
Atrast visus skaitļus, kas atrodas intervālā [n,m]
un kuru ciparu k-tās pakāpes summa ir vienāda ar doto skaitli.
(piemēram, 153 = 1+125 + 27).
Risinājumā izmantot funkciju, kas izrēķina skaitļa ciparu k-tās pakāpes summu.
*/

//autors: Artis Birznieks ab21296
//datums: 04.10.2021.

#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;
bool vaiSaturTikai0un1(int skaitlis){
    int cipars;
    do{
        cipars = skaitlis % 10;
        if(cipars > 1){
            return false;                       // Pārbauda, vai dotais skaitlis satur tikai 1 un 0. Ja skaitlis satur tikai 1 un 0, tad pakāpei augot ciparu k-tās pakāpes summa nemainās. Tas liek ciklam iesprūst un programmai neizpildīties līdz galam.
        }
        skaitlis = skaitlis /  10;
    }while(skaitlis >= 1);
    return true;
}


int kTasPakapesCiparuSumma(int skaitlis, int pakape){
    int cipars;
    int summa = 0;
    do{
        cipars = skaitlis % 10;
        skaitlis = skaitlis / 10;                       // Katru dotā skaitļa ciparu kāpina dotajā pakāpē un saskaita. Rezultātā iegūst dotā skaitļa k-tās pakāpes ciparu summu.
        summa += pow(cipars, pakape);
    }while(skaitlis >= 1);
    return summa;
}

void izdrukatRezultatu(int skaitlis, int pakape){
    int n = skaitlis, reversedNumber = 0, remainder;

    if(skaitlis > 10){
        do{                                                 // Uzraksta doto skaitli virzienā no labās uz kreiso, lai izdrukātais rezultāts būtu vieglāk salasāms. (153 = 1 + 125 + 27 nevis 153 = 27 + 125 + 1)
            remainder = n%10;
            reversedNumber = reversedNumber*10 + remainder;
            n /= 10;
        }while(n >= 1);
    }else{
        reversedNumber = skaitlis;
    }

    cout << skaitlis << " = ";
    int cipars;
    do{
        cipars = reversedNumber % 10;
        if(reversedNumber < 10){
            cout << pow(cipars, pakape) << endl;            // Izdrukā viegli lasāmu un saprotamu rezultātu.
                                                            // Ja dotā skaitļa pēdējais cipars ir 0 , programma šo "+ 0" neizdrukās.
        }else{
            cout << pow(cipars, pakape) << " + ";
        }

        reversedNumber = reversedNumber / 10;

    }while(reversedNumber >= 1);
}


int main(){
    int ok, n, m, summa, pakape;
    do{
        while(true){
            cout << "Ievadi naturālu skaitli n: " << endl;

            if(cin >> n && n > 0){
                break;
            }else{
                cout << "Pārliecinies, vai ievadīji naturālu skaitli." << endl;     // Pārliecinamies,ka pareizi ievadīts n.
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        while(true){
            cout << "Ievadi naturālu skaitli m: " << endl;

            if(cin >> m && m > 0){
                break;
            }else{
                cout << "Pārliecinies, vai ievadīji naturālu skaitli." << endl;     // Pārliecinamies,ka pareizi ievadīts m.
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        summa = 0;
        pakape = 0;
        if(n < m){
            for(int i = n; i <= m; i++){                                    // Katrai i vērtībai [n; m] pārbaudam, vai skaitļa ciparu k-tās pakāpes summa ir vienāda ar i.
                pakape = 0;
                if(i >= 10 && !vaiSaturTikai0un1(i)){               // Kad i ir viencipara skaitlis, tā vērtība vienmēr ir vienāda ar ciparu 1. pakāpē.
                                                                    // Ja skaitļa cipari būs tikai 1 un 0, tad cikls iesprūdīs, jo pakāpe augs, bet summa nemainīsies.
                    do{
                        summa = (kTasPakapesCiparuSumma(i, pakape));        // Aprēķinu skaitļa ciparu k-tās pakāpes summu.
                        if(summa == i){
                            izdrukatRezultatu(i, pakape);
                        }
                        pakape++;
                    }while(summa < i);                                      // Ja summa ir lielāka par i vērtību, pārbaudu nākamo i vērtību.
                }else if(i == 1){
                    cout << i << "^ (jebkurā veselā, naturālā pakāpē) = " << i << endl;
                }else if(i < 10 && !vaiSaturTikai0un1(i)){                  // // Kad i ir viencipara skaitlis, tā vērtība vienmēr ir vienāda ar ciparu 1. pakāpē.
                    izdrukatRezultatu(i, 1);
                }
            }
        }else if(n > m){
            for(int i = m; i <= n; i++){                        //Cikls gadījumam, ja lietotājs ievada n, kas mazāks par m.

                pakape = 0;
                if(i >= 10 && !vaiSaturTikai0un1(i)){
                    do{
                        summa = (kTasPakapesCiparuSumma(i, pakape));
                        if(summa == i){
                            izdrukatRezultatu(i, pakape);
                        }
                        pakape++;
                    }while(summa < i);
                }else if(i == 1){
                    cout << i << "^ (jebkurā veselā, naturālā pakāpē) = " << i << endl;
                }else if(i < 10 && !vaiSaturTikai0un1(i)){
                    izdrukatRezultatu(i, 1);
                }
            }
        }

        cout << "Turpināt (1) vai beigt (0) ?" << endl;
        cin >> ok;
    }while(ok == 1);
    return 0;
}


/***********************************| Testa plāns |***************************************
*        n, m                            Paredzamais rezultāts                           *
*                                                                                        *
*      100 , 200                           153 = 1 + 125 + 27                            *
*                                                                                        *
*                                                                                        *
*                                       1 ^ (jebkurā naturālā pakāpē) = 1                *
*                                       2 = 2                                            *
*       1  , 10                         3 = 3                                            *
*                                       .....                                            *
*                                       9 = 9                                            *
*                                                                                        *
*       99 , 102                                                                         *
*                                                                                        *
*       1.1 ,                           Pārliecinaties, ka ievadīji naturālu skaitli     *
*                                                                                        *
*       a ,                             Pārliecinies, ka ievadīji naturālu skaitli       *
*                                                                                        *
*                                                                                        *
*****************************************************************************************/




