// F1. Dots teksta fails f. Uzrakstīt programmu, kura atrod failā f visus vārdus, kas ir apakšvirkne dotajai virknei m.
//Izvadīt šos vārdus failā f1. Par vārdu uzskatīt patvaļīgu simbolu virkni, kas atdalīta ar tukšumiem vai pieturas zīmēm (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme).
//Drīkst uzskatīt, ka vārda garums nepārsniedz 40

// Autors: Artis Birznieks ab21296
// Datums: 26.02.2022.

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
    int ok;
    fstream fin, fout;
    string vards, rindina, temp;
    int wordIndex = 0;
    string substrings[1000];                    // Masīvs, kurā liek visas iespējamās dotā vārda apakšvirknes
    string strArray[100];                       // Masīvs, lai programmas izpildes gaitā iegūtos rezultātus būtu vieglāk izvadīt failā f1.txt
    string const delims{" .,()!"};              // Atdalošie simboli

    fin.open("f.txt", ios::in);
    if(!fin){
    cout << "Nav faila" << endl;
        return 13;
    }

    cout << "Ievadi vārdu, kuru meklēt failā: " << endl;
    getline(cin, vards);

    for (int c = 0; c < vards.length(); c++)                //Atrod visas iespējamās dotā vārda apakšvirknes un saliek tās masīvā.
    {
        for (int i = 1; i <= vards.length() - c; i++)
        {
            substrings[wordIndex] = vards.substr(c, i);
            //cout << substrings[wordIndex] << endl;
            wordIndex++;
        }
    }

    getline(fin, rindina);
    wordIndex = 0;
    bool jauAtrasts = false;
    while(fin){                                                                         // Nolasu rindiņu no faila, atdalu to izmantojot atdološos simbolus
        size_t beg, pos = 0;                                                            // un, ja rindiņas vārds ir dotā vārda apakšvirkne, tad ielieku rindiņas vārdu masīvā.
        while ((beg = rindina.find_first_not_of(delims, pos)) != std::string::npos)
        {
            jauAtrasts = false;
            pos = rindina.find_first_of(delims, beg + 1);
            temp = rindina.substr(beg, pos - beg);
            for(int i = 0; substrings[i] != ""; i++){
                if(substrings[i].compare(temp) == 0 && jauAtrasts == false){
                    strArray[wordIndex] = temp;
                    wordIndex++;
                    jauAtrasts = true;
                }
            }
        }
        getline(fin, rindina);
    }
    fin.close();
    fout.open ("f1.txt", ios::out);
    for(int i = 0; i < wordIndex; i++){                         // Lasu vērtības no masīva un izvadu datus failā f1.txt
        fout << strArray[i] << endl;
    }
    fout.close();
    cout << "Failā f1.txt tika ierakstīti " << wordIndex << " jauni vārdi, kuri satur " << vards << endl;
    return 0;
}


/********************************* Testa plāns **********************************
vārds                                 f.txt                     f1.txt
pasaka                           pasaka asaka saka      pasaka asaka saka aka ka a
                                    aka ka a

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
pasaka                              apasaka                     -------
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
pasaka                               apsaka                     -------
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
pasaka                          (saka),pasaka!ka.a         saka pasaka ka a
*********************************************************************************/




