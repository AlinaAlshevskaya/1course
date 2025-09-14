#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
void Case1(int int_nSymbols) {

    int int_difference;
    char char_letter;
    cout << "Введите количество символов: ";
    cin >> int_nSymbols;
    for (int i = 1; i < (int_nSymbols + 1);) {
        cout << "Введите букву латиского алфавита ";
        cin >> char_letter;
        if ('A' <= char_letter && char_letter <= 'z')
        {
            int_difference = tolower(char_letter) - toupper(char_letter);
            std::cout  <<  int_difference  <<  endl  ;
        }
        else
            std::cout << "Вы ввели не букву латинского алфавита ";  

        i ++;
    }
}
