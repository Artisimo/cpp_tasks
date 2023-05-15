/*

Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās, gan rezultējošās vērtības. Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu pievienošanai), kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa.

G1. Uzrakstīt funkciju, kas izmet no saraksta visus tādus elementus, kas vienādi ar iepriekšējo
*/

// Programma, kurā tiek izmantots STL::list
// Autors: Artis Birznieks ab21296
// Datums : 26.03.2022.

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

void dzestVienaduArIeprieksejoSTL_List(list<int>& sar){ // Funkcija, kas dzēš no saraksta visus elementus, kas vienādi ar iepriekšējo.

  list<int>::iterator current, next, tmp;
  current = sar.begin();
  next = current;
  bool dzestCurrent;

  while(current != sar.end()){ // Noskaidro, ar kādu vērtību jāsalīdzina next elements.
    dzestCurrent = false;
    next = current;
    next++;
    while(next != sar.end()){    // Kāmēr next elementa vērtība sakrīt ar current vērtību, next vērtība tiek dzēsta.
        if(*next == *current){
            dzestCurrent = true;
            tmp = next;
            next++;
            sar.erase(tmp);
        }else{
            break;
        }
    }
    if(dzestCurrent){ // Ja tika izdzēsta kāda next vērtība, tad jādzēš arī current vērtība.
        tmp = current;
        sar.erase(tmp);
        current = sar.begin(); // Current jāuzliek uz saraksta sākumu, lai situācijā, kad saraksts ir 2, 1, 1, 2, beigās tas būtu tukšs, nevis 2, 2
    }else{
        current++;
    }
  }

}

void drukatSarakstu(list<int> &sar){
    if(sar.empty()){
        cout << "Saraksts ir tukšs" << endl;
    }else{
        for(auto e : sar){
            cout << e << " ";
        }
        cout << endl;
    }
}

int getUserNumber(){    // Funkcija, kas pārliecinās par ievadīto datu pareizumu.
    int vertiba;
    while (true) {
        if (cin >> vertiba) {
            break;
        } else {
            cout << "Pārliecinies vai ievadītie dati ir pareizi! (Vesels skaitlis)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return vertiba;
}

int main(){
    int ok;
    int sarakstaGarums;
    list<int> sar;

    do{
        cout << "Ievadiet saraksta garumu: " << endl;
        sarakstaGarums = getUserNumber();
        int sarakstaVertibas[sarakstaGarums];

        for(int i = 0; i < sarakstaGarums; i++){
            cout << "Ievadi saraksta " << i + 1 << " vērtību: " << endl;
            sar.push_back(getUserNumber());
        }
        cout << "Saraksts pirms dzēšanas: ";
        drukatSarakstu(sar);
        dzestVienaduArIeprieksejoSTL_List(sar);
        cout << "Saraksts pēc dzēšanas: ";
        drukatSarakstu(sar);

        sar.clear();

        cout << "Turpināt (1) vai beigt (0)" << endl;
        cin >> ok;
    }while (ok == 1);

    return 0;
  }

 /*--~-~-~-~-~-~-~-~-~-~-~-~-~Testa Plāns-~-~-~-~-~-~-~-~-~-~-~-~-~-~
        Sākotnējais saraksts                    Beigu saraksts
        1, 1, 1, 2, 2, 2, 3, 3                      tukšs

           5,5,4,5,5                                  4

            5, 5, 5                                 tukšs

            3, -3, 3                                3, -3, 3

            2, 1, 1, 2                              tukšs

  --~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~*/
