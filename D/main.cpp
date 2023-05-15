#include <iostream>
#include "program.h"

using namespace std;

int displayMenu(bool vaiRindaEksiste){              // Izdrukā izvēlni atkarībā no tā, vai jau ir izveidota rinda.

    int izvele;
    if(!vaiRindaEksiste){
        cout << "Izveidot jaunu rindu: 1\n"
             << "Beigt programmas izipildi: 0 \n";
    }else{
        cout << "Pievienot jaunu elementu rindai: 2\n"
             << "Izņemt elementu no rindas: 3\n"
             << "Noskaidrot, cik elementu ir rindā: 4\n"
             << "Noskaidrot, vai rinda ir tukša: 5\n"
             << "Izdzēst rindu: 6\n"
             << "Beigt programmas izpildi: 0\n";
    }

    cin >> izvele;
    return izvele;
}

int main()
{
    rinda *x;
    int izvele;
    int pievienojamaisElements;
    bool vaiRindaEksiste = false;
    do{
        izvele = displayMenu(vaiRindaEksiste);
        switch(izvele){         // Izpilda lietotāja izvēlēto darbību.
            case 1:
                x = new rinda();
                vaiRindaEksiste = true;
            break;
            case 2:
                cout << "Ievadiet vērtību elementam, ko vēlaties pievienot rindai." << endl;
                cin >> pievienojamaisElements;
                x -> enqueue(pievienojamaisElements);
            break;
            case 3:
                x -> dequeue();
            break;
            case 4:
                cout << "Elementu skaits rindā ir: " << x -> Count() << endl;
            break;
            case 5:
                if(x -> isEmpty()){
                    cout << "Rinda ir tukša." << endl;
                }else{
                    cout << "Rinda nav tukša." << endl;
                }
            break;
            case 6:
                x -> ~rinda();
                vaiRindaEksiste = false;
            break;
        }

    }while(izvele != 0);
    return 0;

}
