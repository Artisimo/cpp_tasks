/* PiPLa0502. Sastādīt C++ programmu, kas ļauj iegūt ziņas par dotu preses izdevumu.
Preses izdevuma nosaukums jāņem no standartieejas plūsmas.
Jāizmanto fails ar ziņām par preses izdevumiem. Ziņas par preses izdevumiem ir ierakstītas
secīgi binārā komponenšu failā (vienāda garuma ieraksti) (prese.bin).
Faila ieraksta saturs: nosaukums, izdevuma veids (laikraksts, žurnāls, nedēļraksts), iznākšanas reižu skaits mēnesī, valoda, izdevējs, izdevuma indekss (1-100). */


#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

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
    bool select()
};


int main(){
}
