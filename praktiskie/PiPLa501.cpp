/* PiPLa0501. Sastādīt C++ programmu, kas izveido failu, kas satur ziņas par preses izdevumiem.
Ziņas par preses izdevumiem ir jāieraksta secīgi binārā komponenšu failā (vienāda garuma ieraksti) (prese.bin).
Faila ieraksta saturs: nosaukums, izdevuma veids (laikraksts, žurnāls, nedēļraksts),
iznākšanas reižu skaits mēnesī, valoda, izdevējs, izdevuma indekss (1-100). */

//Autors: Artis Birznieks ab21296
//Datums: 02.05.2022

#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

    int const IZDGARUMS = 15;
    int const NOSGARUMS = 20;
    int const VEIDGARUMS = 10;

class Prese{
private:
    char izdevejs[IZDGARUMS+1];
    int reizes;
    char nosaukums[NOSGARUMS+1];
    char veids[VEIDGARUMS+1];
    string valoda;
    int indekss; // 1-100
public:
    void inputPrese();
    void add_izdevums(const char* fname);
    void print();
    void printFile(const char* fname);
};

int main(){
    Prese izd;
    string fn = "prese.bin";

    //Secīgās lasīšanas shēma failam (Faila mainīgajam) cin.
    izd.inputPrese();
    while(cin){
        izd.add_izdevums(fn.c_str());
        izd.inputPrese();
    }

    //Izdrukā faila prese.bin saturu
    izd.printFile(fn.c_str());
}

void Prese::inputPrese(){
    string vertiba;
    cout << "Ievadiet informāciju par preses izdevumu (Katru vērtību jaunā līnijā)" << endl;
    cout << "Nosaukums:" << endl;
    getline(cin, vertiba);
    strncpy(nosaukums, vertiba.c_str(), NOSGARUMS);
    nosaukums[NOSGARUMS] = '\0';
    //cout << "Izdevuma Veids:" << endl;
    getline(cin, vertiba);
    strncpy(veids, vertiba.c_str(), VEIDGARUMS);
    veids[VEIDGARUMS] = '\0';
    cout << "Iznākšanas reižu skaits:" << endl;
    cin >> reizes;
    cout << "Valoda:" << endl;
    cin >> valoda;
    cout << "Izdevuma indekss:" << endl;
    cin >> indekss;
    cout << "Izdevējs:" << endl;
    getline(cin, vertiba);
    strncpy(izdevejs, vertiba.c_str(), IZDGARUMS);
    izdevejs[VEIDGARUMS] = '\0';
    cin.ignore();
}
void Prese::add_izdevums(const char* fname){
    fstream f;
    f.open(fname, ios::app | ios::binary);
    f.write((char*) this, sizeof(Prese));
    f.close();
}

void Prese::print(){
    cout << nosaukums << " " << veids << " " << reizes << " " << valoda << " " << izdevejs
    << " " << indekss << endl;
}

void Prese::printFile(const char* fname){
    fstream f;
    f.open(fname, ios::in | ios::binary);
    f.read((char*)this, sizeof(Prese));
    while(f){
        print();
        f.read((char*)this, sizeof(Prese));
    }
    f.close();
}
