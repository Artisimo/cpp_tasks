#include <iostream>
#include <iterator>
#include <map>
#include <fstream>
#include <string>
using namespace std;

/*H1. Dots teksta fails. Atrast tekstā visbiežāk lietotos vārdus, kas sākas ar a, b, c utt. (katram latīņu alfabēta burtam, nešķirojot reģistru). Programmai vārdi jāsaliek tabulā, kas realizēta kā vārdnīca (STL map), kur pēc pirmā burta glabājas visi vārdi, kas sākas ar šo burtu. Vārdu saraksts, kas sākas ar doto burtu, arī ir vārdnīca, kas  katram vārdam glabā tā sastapto reižu skaitu tekstā. Programmas rezultātā iegūt failu, kurā katram latīņu alfabēta burtam (a..z) izdrukāts biežāk sastopamais vārds un tā sastapšanas reižu skaits tekstā (piemēram, and 101, but 18, captain 9 utt.). Par vārdu tiek uzskatīta latīņu alfabēta burtu virkne.
*/

// Autors: Artis Birznieks ab21296
// Datums: 06.05.2022

int main() {
  fstream fin;
  fstream fout;
  fin.open("input.txt", ios::in);

  string word;
  char firstLetter;
  int count = 0;
  bool isFileEmpty = true;

  map<char, string> firstLetterAndWord;
  map<string, int> wordCount;
  map<char, string>::iterator it1;
  map<string, int>::iterator it2;

  while(fin >> word){
    isFileEmpty = false;
    it1 = firstLetterAndWord.find(word[0]);
    if(it1 == firstLetterAndWord.end()){
      firstLetterAndWord.insert({word[0], word});
    }else{
      it1 -> second += " " + word;
    }

    it2 = wordCount.find(word);
    if(it2 == wordCount.end()){
      wordCount.insert({word, 1});
    }else{
      it2->second += 1;
    }
  }
  if(isFileEmpty){
    cout << "Fails ir tukšs" << endl;
  }
  fin.close();

  fout.open("output.txt", ios::out);
  it2 = wordCount.begin();
  int counter = 0;
  for(it1 = firstLetterAndWord.begin(); it1 != firstLetterAndWord.end(); it1++)
  {
    firstLetter = it1 -> first;
    count = 0;
    while(it2 -> first[0] == firstLetter && it2 != wordCount.end()){

      if(it2->second > count){
        word = it2->first;
        count = it2->second;
      }
      it2++;
    }

    cout << word << " " << count << endl;

    if(counter == 0){
      cout << "Te" << endl;
      //cout << word << " " << count;
      //fout << word << " " << count ;
      counter++;
    }else{
        cout << "Te" << endl;
      //cout << ", " << word << " " << count;
      //fout << ", " << word << " " << count;
      counter++;
    }
  }
}

/******************************************Testu plāns**************************************
           input.txt                            |                   output.txt
             es es                              |
          jutos jutos                           |              es 2, jutos 2, labi 2
           labi labi                            |
                                                |
            Es es                               |
         Jutos jutos                            |    Es 1, Jutos 1, Labi 1, es 1, jutos 1, labi 1
          Labi labi                             |
                                                |
   Birznieks Birznieks Artis Artis              |              Artis 2, Birznieks 2
                                                |
   Man ir suns un kakis un putns                |     Man 1, ir 1, kakis 1, putns 1, suns 1, un 2
                                                |
              -                                 |                  Fails ir tukšs
*************************************************************************************************/
