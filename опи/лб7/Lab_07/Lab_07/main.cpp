#include <iostream>
#include <Windows.h>
#include "Case_1.h"
#include "Case_2.h"
#include "Case_3.h"
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int int_nProgramm;
    int int_nSymbol = 0;
    setlocale(LC_CTYPE, "Russian");
    while (int_nProgramm != 4) {
        cout << "�������� ������� ������������� ���������" << endl;
        cout << "1 � ����������� ������� �������� ����� � ASCII ����� � ��������� � �������� ���������, ���� ������ ������ ���������� ��������, ����� ����� ��������� �� ������ " << endl;
        cout << "2 � ����������� ������� �������� ����� � Windows-1251 ����� � ��������� � �������� ���������, ���� ������ ������ �������� ��������, ����� ����� ��������� �� ������ " << endl;
        cout << "3 � ����� � ������� ���� �������, ���������������� ��������� �����, ����� ����� ��������� �� ������ " << endl;
        cout << "4 � ����� �� ���������." << endl;
        cin >> int_nProgramm;
        switch (int_nProgramm)
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
        case 4: {
            std::cout << "��������� ���������";
            return 0;
        }
        default:
            std::cout << "��� ����� ���������";
        }

    }

}
