#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    string text;
    ofstream fout("t.txt");
    cout << "Введите строку" << endl;
    getline(cin, text);
    fout << text; // запись строки в файл

    ifstream fin("t.txt;");

    getline(fin, text);
    int i = 1;
    int counter = 1, min, pos1, pos2,wordcounter=1;
    min = 100;
    for (i; i <=text.size(); i++) {
        counter++;
        
        if (text[i] == ' ')
        {            
            if (min > counter) {
                pos2 = i - 1;
                min = counter - 1;
                pos1 = i - min;
            }
            counter = 0;
        }
    }
    for ( int j=pos1; j > 0; j--) {
        if (text[j] == ' ')
        {
            wordcounter++;
        }
    }
    for (pos1; pos1 <= pos2; pos1++) {
        cout << text[pos1];

    }
    
    cout << "\nНомер слова " << wordcounter<<" Кол-во букв "<< min;
    fin.close();
    return 0;
}



  



