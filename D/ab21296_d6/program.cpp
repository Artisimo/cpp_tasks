#include <iostream>
#include "program.h"
using namespace std;

rinda::rinda(){                     //Konstruktors
    this -> elementuSkaits = 0;
    this -> rindasSakums = 0;
    this -> rindasBeigas = 0;
    cout << "Izveidota rinda.\n" << endl;
}

rinda::~rinda(){            // Destruktors
    cout << "Iznīcināts objekts ar " << this-> elementuSkaits << " elementiem." << "\n" << endl;
}

void rinda::enqueue(int n){

    if(this-> elementuSkaits > 0 && this-> rindasBeigas == this -> rindasSakums){       // Pārbauda, vai rinda nav pilna
        cout << "Nevar pievienot elementu rindai, jo tā ir pilna.\n" << endl;
    }else{
        this-> vertibas[rindasBeigas] = n;
        this -> rindasBeigas = (rindasBeigas + 1) % 5;
        cout << "Rindai pievienots elements ar vērtību " << n << "\n" << endl;
        this -> elementuSkaits++;
    }
}

int rinda::dequeue(){
    int iznemtaVertiba;
    if(this-> elementuSkaits == 0){     // Tiek pārbaudīts, vai rinda nav tukša
        cout << "Rinda ir tukša, no tās netika izņemts neviens elements\n" << endl;
    }else{
        iznemtaVertiba = this->vertibas[rindasSakums];
        cout << "No rindas tika izņemts elements ar vērtību " << iznemtaVertiba << "\n" << endl;
        this-> rindasSakums++;
        this -> elementuSkaits--;
    }
    return iznemtaVertiba;
}

int rinda::Count(){
    return this-> elementuSkaits;
}

bool rinda::isEmpty(){
    if(this-> elementuSkaits == 0){
        return true;
    }
    return false;
}



