#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
void Case3(int int_nSymbol)
{
	char  char_number;
	int  int_code;
	cout << "Введите количество символов:  ";
	cin >> int_nSymbol;
	for (int i = 1; i < (int_nSymbol + 1); )
	{
		std::cout << "Введите цифру ";
		std::cin >> char_number;
		if ('0' <= char_number && char_number <= '9')
		{
			int_code = char_number;
			std::cout << "Код символа : " << int_code << endl;
		}
		else std::cout << "Это не цифра" << endl;
		i++;
	}
}
