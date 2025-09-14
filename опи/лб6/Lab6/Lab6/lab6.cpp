#include <iostream>
#include <Windows.h>
#include "case1.h"
#include "case2.h"
#include "case3.h"
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    unsigned char code;
    char c;
    int n = 0;
    int int_nSymbol=0;
    setlocale(LC_CTYPE, "Russian");
    while (n != 4) {
        cout << "¬ыберите вариант использовани€ программы" << endl;
        cout << "1 Ц определение разницы значений кодов в ASCII буквы в прописном и строчном написании, если введен символ латинского алфавита, иначе вывод сообщени€ об ошибке " << endl;
        cout << "2 Ц определение разницы значений кодов в Windows-1251 буквы в прописном и строчном написании, если введен символ русского алфавита, иначе вывод сообщени€ об ошибке " << endl;
        cout << "3 Ц вывод в консоль кода символа, соответствующего введенной цифре, иначе вывод сообщени€ об ошибке " << endl;
        cout << "4 Ц выход из программы." << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            Case1(int_nSymbol);
            break;
        case 2:
            Case2(int_nSymbol);
            break;
        case 3:
            Case3(int_nSymbol);
            break;
        case 4:{
            std::cout << "ѕрограмма завершенна";
            return 0;
        }
        default:
         std::cout << "Ќет такой программы";
        }
    
    }
        
}

