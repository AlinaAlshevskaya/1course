#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
void Case2(int int_nSymbols)
{
	char char_letter; 
	int int_difference;
    cout << "������� ���������� ��������: ";
    cin >> int_nSymbols;
    for (int i = 1; i < (int_nSymbols + 1);) {
		std::cout << "������� ����� �������� �������� ";
		std::cin >> char_letter;
		if (  '�'  <=  char_letter  &&  char_letter  <=  '�'  )
		{
			int_difference  =  tolower(char_letter)  -  toupper(char_letter)  ;
			std::cout  <<  int_difference  <<  endl  ;
		}
		else  std::cout  <<  "�� ����� �� ����� �������� �������� "  ;
        i ++;
    }
}
