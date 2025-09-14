#include <iostream>
//AlshevskayaAlina2005
//представление строки в Windows-1251 : 41 6c 73 68 65 76 73 6b 61 79 61 41 6c 69 6e 61 32 30 30 35
//в UTF-8 : 41 6c 73 68 65 76 73 6b 61 79 61 41 6c 69 6e 61 32 30 30 35
//в UTF-16 :41 6c 73 68 65 76 73 6b 61 79 61 41 6c 69 6e 61 32 30 30 35

//АльшевскаяАлина2005
//представление строки в Windows-1251 :c0 eb fc f8 e5 e2 f1 ea e0 ff c0 eb e8 ed e0 32 30 30 35 
//в UTF-8 :d090 d0bb d18c d188 d0b5 d0b2 d181 d0ba d0b0 d18f d090 d0bb d0b8 d0bd d0b0 32 30 30 35 
//в UTF-16 :410 43b 44c 448 435 432 441 43a 430 44f 410 43b 438 43d 430 32 30 30 35 

//Альшевская2005Alina
//представление строки в Windows-1251 :c0 eb fc f8 e5 e2 f1 ea e0 ff 32 30 30 35 41 6c 69 6e 61  
//в UTF-8 :d090 d0bb d18c d188 d0b5 d0b2 d181 d0ba d0b0 d18f 32 30 30 35 41 6c 69 6e 61 
//в UTF-16 :410 43b 44c 448 435 432 441 43a 430 44f 32 30 30 35 41 6c 69 6e 61 

int main()
{
    int number = 0x12345678;
    char hello[] = "Hello, ";
    char lfie[] = "AlshevskayaAlina2005";
    char rfie[] = "АльшевскаяАлина2005";
    char lr[] = "Альшевская2005Alina";

    wchar_t Lrie[] = L"AlshevskayaAlina2005";
    wchar_t Rfie[] = L"АльшевскаяАлина2005";
    wchar_t LR[] = L"Альшевская2005Alina";
    std::cout << hello << lfie << std::endl;
    return 0;

  
}

