#include <iostream>
	int main()
	{
		int ready, eggs, pan;
		setlocale(LC_CTYPE, "Russian");
		using namespace std;
		std::cout << "�������� �����\n";
		std::cout << "��������� ���������� �������\n";
		std::cout << "������� �����\n";
		std::cout << "������� ���� � ������\n";
		std::cout << "���� �������? ( 1- ��; 2-���)\n";
		std::cin >> eggs;
		if (eggs == 1)
		{
			std::cout << "������� 2 ���� � �������� 4 ����� ������\n";
		}
		else if (eggs == 2)
		{
			std::cout << "������� 3 ���� � �������� 6 ����� ������\n";
		}
		else
		{
			std::cout << "��� ������ ��������\n";
			return 0;
		}
		std::cout << "�� � ����� ����������\n";
		std::cout << "���������� �������? ( 1- ��;2-���)\n";
		std::cin >> pan;
		while (pan != 1)
		{
		std::cout<<"���";
		std::cout<<"���������� ������� ( 1- ��; 2-���)\n";
			std::cin >> pan;
		}
		std::cout << "�������� � ���������� ���������� �����.������\n";
		std::cout << "����� �����?(1- ��; 2- ���))\n";
		std::cin >> ready;
		while (ready != 1)
		{
		std::cout<<"����� � ��������� ����������\n";
		std::cout<<"����� �����?(1- ��;2-���)\n";
			std::cin >> ready;
		}
	std::cout<<"����� � �����\n";
	std::cout<<"����� �����\n";
		return 0;
	}
	