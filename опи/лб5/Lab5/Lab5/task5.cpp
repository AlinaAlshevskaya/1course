#include <iostream>
#include <windows.h>
#include <cwctype>
int main()
{
setlocale(LC_CTYPE, "Russian");
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
int code, remainder,u,com;
char Letter,number ;
std::cout << ".�������� ������������� :\n";
std::cout << " 1 � ����������� ������� �������� ����� � ASCII ����� � ��������� � �������� ���������, ���� ������ ������ ���������� ��������, ����� ����� ��������� �� ������;\n";
std::cout << "2 � ����������� ������� �������� ����� � Windows - 1251 ����� � ��������� � �������� ���������, ���� ������ ������ �������� ��������, ����� ����� ��������� �� ������;\n";
std::cout << "3 � ����� � ������� ���� �������, ���������������� ��������� �����, ����� ����� ��������� �� ������;\n";
std::cout << " 4� ����� �� ���������.����� ��������� �� ������ ������������.\n";
std::cout << "������� ����� ��������� (�� 1 �� 4): ";
std::cin >> com;
switch (com)
{
case 1: {
	
	std::cout << "������� ���������� ��������: ";
	std::cin >> u;
	for (int i = 1; i < (u + 1);) {
		std::cout << "������� ����� ���������� �������� ";
		std::cin >> Letter;
		if ('A' <= Letter && Letter <= 'z')
		{
			remainder = tolower(Letter) - toupper(Letter);
			std::cout << remainder;
		}
		else
			std::cout << "�� ����� �� ����� ���������� �������� ";
		i++;
	}break; }
case 2:{  
	std::cout << "������� ���������� ��������: ";
	std::cin >> u;
	for (int i = 1; i < (u + 1);) {
		std::cout << "������� ����� �������� �������� ";
		std::cin >> Letter;
		if ('�' <= Letter && Letter <= '�')
		{
			remainder = tolower(Letter) - toupper(Letter);
			std::cout << remainder;
		}
		else std::cout << "�� ����� �� ����� �������� �������� ";
		i++;
	}break; }
case 3: {
	std::cout << "������� ���������� ��������: ";
	std::cin >> u;
	for (int i = 1; i < (u + 1);) 
		{
			std::cout << "������� ����� ";
			std::cin >> number;
			if ('1' <= number && number <= '9')
			{
				code = number;
				std::cout << "��� ������� : " << code;
			}
			else std::cout << "��� �� �����";
			i++;
		}break;
	}
case 4:{
	std::cout << "��������� ����������";
	return 0;
}
default:
	std::cout << "��� ����� ���������";
}
return 0;
}