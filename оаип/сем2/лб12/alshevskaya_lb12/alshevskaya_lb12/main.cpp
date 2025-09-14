#include "Heap.h"
#include <iostream>
#include <Windows.h>
using namespace std;

// ������� ��� ��������� ���� �������� ���� AAA � ����.
heap::CMP cmpAAA(void* a1, void* a2)
{
	// ���������� ���������� � ���� AAA.
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)

// ������������� ���������� ��������� ��� EQUAL (���������).
	heap::CMP rc = heap::EQUAL;

	// ��������� �������� 'x' �������� AAA.
	if (A1->x > A2->x)
		rc = heap::GREAT; // ���� A1.x > A2.x, ��������� GREAT (������).
	else if (A2->x > A1->x)
		rc = heap::LESS; // ���� A2.x > A1.x, ��������� LESS (������).

	// ������� ���������� ���������.
	return rc;

	// �������� �������� ��� �������������� ��������� ����������.
#undef A2
#undef A1
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// ���������� ����������.
	int k, choice, index;

	// �������� ���������� ���� h1 � �������� 30 � �������������� ������� ��������� cmpAAA.
	heap::Heap h1 = heap::create(30, cmpAAA);

	// ����������� ���� ��� �������������� � �������������.
	for (;;)
	{
		// ����������� ��������� ����.
		cout << "1 - ����� ���� �� �����" << endl;
		cout << "2 - �������� �������" << endl;
		cout << "3 - ������� ������������ �������" << endl;
		cout << "4 - ������� ����������� �������" << endl;
		cout << "5 - ������� ������� �� �������" << endl;
		cout << "6 - ���������� ��� ����" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;

		// ������ ������ ������������.
		cin >> choice;

		// ���������� switch � ����������� �� ������ ������������.
		switch (choice)
		{
		case 0: // ����� �� ���������.
			exit(0);
		case 1: // ���������� ���������� ����.
			h1.scan(0);
			break;
		case 2: // �������� ������� � ����.
		{
			// ������������ ��������� ������ ��� ������� AAA.
			AAA* a = new AAA;
			cout << "������� ����" << endl;
			cin >> k;
			a->x = k;
			// �������� ������� � ����.
			h1.insert(a);
		}
		break;
		case 3: // ������� ������������ ������� �� ����.
			h1.extractMax();
			break;
		case 4: // ������� ����������� ������� �� ����.
			h1.extractMin();
			break;
		case 5: // ������� ������� �� ������� �� ����.
			cout << "������� ������ �������� ��� ��������" << endl;
			cin >> index;
			h1.extractI(index);
			break;
		case 6: // ���������� ��� ����.
		{
			cout << "�������� ������ ���� ��� �����������..." << endl;
			heap::Heap h2 = heap::create(2, cmpAAA);
			for (size_t i = 0; i < 2; i++)
			{
				// ������������ ��������� ������ ��� ������� AAA.
				AAA* a = new AAA;
				cout << "������� ����" << endl;
				cin >> k;
				a->x = k;
				// �������� ������� � ����.
				h2.insert(a);
			}
			// ����� �������� �������� � h2 �� ���� �������������.
			cout << "����������� ���� ���" << endl;
			h1.unionHeap(h2);
		}
		break;
		default: // ������� ��������� � ������������ �������.
			cout << endl << "������� ������������ �������!" << endl;
		}
	}
	return 0;
}