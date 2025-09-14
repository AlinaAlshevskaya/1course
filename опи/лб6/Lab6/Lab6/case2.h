#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
void Case2(int int_nSymbols)
{
	char char_letter; 
	int int_difference;
    cout << "Введите количество символов: ";
    cin >> int_nSymbols;
    for (int i = 1; i < (int_nSymbols + 1);) {
		std::cout << "Введите букву русского алфавита ";
		std::cin >> char_letter;
		if (  'А'  <=  char_letter  &&  char_letter  <=  'я'  )
		{
			int_difference  =  tolower(char_letter)  -  toupper(char_letter)  ;
			std::cout  <<  int_difference  <<  endl  ;
		}
		else  std::cout  <<  "Вы ввели не букву русского алфавита "  ;
        i ++;
    }
}
