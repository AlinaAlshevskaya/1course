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
        cout << "�������� ������� ������������� ���������" << endl;
        cout << "1 � ����������� ������� �������� ����� � ASCII ����� � ��������� � �������� ���������, ���� ������ ������ ���������� ��������, ����� ����� ��������� �� ������ " << endl;
        cout << "2 � ����������� ������� �������� ����� � Windows-1251 ����� � ��������� � �������� ���������, ���� ������ ������ �������� ��������, ����� ����� ��������� �� ������ " << endl;
        cout << "3 � ����� � ������� ���� �������, ���������������� ��������� �����, ����� ����� ��������� �� ������ " << endl;
        cout << "4 � ����� �� ���������." << endl;
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
            std::cout << "��������� ����������";
            return 0;
        }
        default:
         std::cout << "��� ����� ���������";
        }
    
    }
        
}

