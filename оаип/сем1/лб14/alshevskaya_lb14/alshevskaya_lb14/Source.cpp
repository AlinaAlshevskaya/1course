#include <iostream> 
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	double t; 
	int a[10][10];
	double x[400] = { 0 };
	int k = 0;
	cout << "������� ������ �������  ";
	cin >> n;
	for (int i = 0; i < n; i++) { // �������� ��������� �������� ������� � ���������� �� � ��������� ������ ��� ����������
		for (int j = 0; j < n; j++) {
			a[i][j] = -5 + rand() % 41;
			x[k] = a[i][j];
			k++;
		}
	}
	for (int i = 0; i < k; i++) { //��������� ������ ��� ������� ���������
		for (int j = (k - 1); j >= (i + 1); j--) {
			if (x[j] < x[j - 1]) {
				t = x[j];
				x[j] = x[j - 1];
				x[j - 1] = t;
			}
		}
	}
	k--;
	for (int i = 0; i < n; i++) { // ������ �������� ������� ���������
		a[i][i] = x[k];
		k--;
	}
	for (int i = 0; i < n; i++) { // ������� ������� �� �����
		for (int j = 0; j < n; j++) {
			cout << setw(3) << a[i][j] << " ";
		}
		cout << endl;
	}
}




