#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	unsigned int A;//������ ���������� �
	cout << "���� �:";
	cin >> A;
	unsigned int mask = 1 << 2;//������ ����� ��� ���������� �
	if ((A & mask) == 0) {//�������� �� ��������� ������
		cout << "� ������ ������";
	}
	else {
		cout << "� �� ������ �����";//������� , ���� � �� ������ ������
	}
}










