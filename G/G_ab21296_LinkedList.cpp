/*
Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās, gan rezultējošās vērtības. Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu pievienošanai), kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa.

G1. Uzrakstīt funkciju, kas izmet no saraksta visus tādus elementus, kas vienādi ar iepriekšējo
*/

// Programma, kurā tiek izmantots vienvirziena saistītais saraksts.
// Autors: Artis Birznieks ab21296
// Datums : 26.03.2022.

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

class elem{
public:
  int num;
  elem *next;
  elem(int n) { num = n; next = NULL; }
};

void print(elem *&first) {              // Funkcija, kas izdrukā visu sarakstu.

    elem *p = first;
    if(p == NULL){
       cout << "Saraksts ir tukšs" << endl;
    }else{
      while (p!=NULL) {
        cout<<p->num<< " ";
        p = p->next;
      }
    }
    cout<<endl;
}

void append(elem*&first,elem*&last,int n) {  // Saliek saraksta elemetiem vērtības. Pēdējam saraksta elementam pieliek norādi "last"
    elem *p=new elem(n);
    if (first==NULL)
        first=last=p;
    else {
        last->next=p;
        last = p;
    }
}

void deleteElementsToFrom(elem *start, elem *&last, elem *&first){ // Funkcija, kas izmet elementus no *start ieskaitot, līdz *last neieskaitot.
    elem *beforeFirst = first;
    elem *p = first;
    elem *toDelete;
    while(p != NULL){           // Atrod elementu, kurš ir pirms elementa, ar ko jāsāk dzēšana, lai no tā varētu noņemt next norādi.
        if(p -> next == start){
            beforeFirst = p;
        }
        p = p -> next;
    }
    beforeFirst -> next = last;    // Elementam, kurš ir pirms pirmā dzēšamā elementa next norādi nomainam, lai tā norāda uz elementu, kas atrodas aiz pēdēja izdzēstā elementa.

    p = start;
    do{                             // Dzēš visus elementus no pirmā dzēšamā elementa ieskaitot, līdz pēdējam dzēšamajam elementam neieskaitot.
        toDelete = p;
        p = p->next;
        if(p == NULL){
            break;
        }
        toDelete -> next = NULL;
        delete(toDelete);
    }while(p != last);

}

void dzestVienaduArIeprieksejoLinkedList(elem *&first, elem *&last){ // Funkcija, kas izdzēš no vienvirziena saistītā saraksta visas vērtības, kuras vienādas ar iepriekšējo.
    elem *current = first;
    elem *p;
    elem *noKuraJadzes;
    elem *lidzKuramJadzes;
    bool shouldDelete;      // Vai ir jādzēš current elements?

    while(current != NULL){   // Noskaidro, ar kādu vērtību jāsalīdzina p elements
        shouldDelete = false;
        p = current -> next;
        while(p != NULL){     // Noskaidro, cik elementi jādzēš.
            if(p -> num == current -> num){
                shouldDelete = true;
                noKuraJadzes = current;
                p = p -> next;
                lidzKuramJadzes = p;
                current -> next = p;
            }else{
                break;
            }
        }
        if(shouldDelete){
            deleteElementsToFrom(noKuraJadzes, lidzKuramJadzes, first);
            if(current == first){
                first = p;
            }
            current = first;
        }else{
            current = current -> next;
        }
    }
}

void deleteLinkedList(elem *first){ //Funkcija, kas izdzēš visus saraksta elementus.
    elem *p = first;
    elem *deleteTemp;

    while(p != NULL){
        deleteTemp = p;
        p = p->next;
        deleteTemp->next = NULL;
        delete(deleteTemp);
    }

    p = nullptr;
    deleteTemp = nullptr;
    cout << "Saraksts izdzēsts" << endl;
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

    do{
        cout << "Ievadiet saraksta garumu: " << endl;
        sarakstaGarums = getUserNumber();
        int sarakstaVertibas[sarakstaGarums];

        for(int i = 0; i < sarakstaGarums; i++){
            cout << "Ievadi saraksta " << i + 1 << " vērtību: " << endl;
            sarakstaVertibas[i] = getUserNumber();
        }

        elem *first=NULL,*last, *firstold;
        for (int i=0;i<sarakstaGarums;++i) {
            append(first,last,sarakstaVertibas[i]);
        }

        if(first == NULL){
            cout << "Saraksts ir tukšs" << endl;
        }else{
            cout << "Sākotnējais saraksts: ";
            print(first);
            dzestVienaduArIeprieksejoLinkedList(first, last);
            cout << "Saraksts pēc dzēšanas: ";
            print(first);
        }

        deleteLinkedList(first);

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
