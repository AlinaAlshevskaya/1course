#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	const int n = 10;
	int Z[n], B[n], rmn = 0, rmx = 10, k = 0, counter = 0;
	int* ptrZ = Z, * ptrB = B;
	bool flag = false;
	//��������� ������ � ���������� ����������
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		*(ptrZ + i) = (int)(((double)rand() / (double)RAND_MAX) * (rmx - rmn) + rmn);
	}

	//������� ������ z
	cout << "������ Z: "; 
	for (int i = 0; i < n; i++) {
		cout << *(ptrZ + i) << " ";
	}
	cout << '\n';
	//������ ����� � ������� Z ���������� � ������� � ������� � 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (*(ptrB + j) == *(ptrZ + i)) {
				flag = true;
			}
		}
		if (!flag) {// ���� � ������� B ��� ������ ����� �� ������� ����������� �� 1
			*(ptrB + k++) = *(ptrZ + i);
			counter++;
		}
		flag = false;
	}

	//������� �������
	cout << counter;
	return 0;
}



