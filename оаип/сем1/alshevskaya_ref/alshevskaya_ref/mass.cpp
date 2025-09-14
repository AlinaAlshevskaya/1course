#include <iostream>
using namespace std;

// �������, ������� ����������� ��������� ������ � ����������
void flatten(int** arr2d, int rows, int cols, int* arr1d) {
    for (int i = 0; i < rows; i++) {  
        for (int j = 0; j < cols; j++) {
            arr1d[i*cols+j] = arr2d[i][j];
        }
    }
}

// �������, ������� ����������� ���������� ������ � ���������
void unflatten(int* arr1d, int rows, int cols, int** arr2d) {
    for (int i = 0; i < rows; i++) {
        arr2d[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr2d[i][j] = arr1d[i*cols+j];
        }
    }
}

// �������, ������� ������� ��������� ������ �� �����
void print2d(int** arr2d, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr2d[i][j] << " ";
        }
        cout << endl;
    }
}

// �������, ������� ������� ���������� ������ �� �����
void print1d(int* arr1d, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr1d[i] << " ";
    }
    cout << endl;
}

//������� ��� ���������� ����������� ������� � ����������
void exist1d(int* arr1d, int size) {
    cout << "������� �������� ������� (" << size << ") : \n";
    for (int i = 0; i < size; i++) {
        cin >> arr1d[i];
    }
    cout << endl;
 }

//������� ��� ���������� ���������� ������� � ����������
void exist2d(int** arr2d, int rows, int cols) {
    cout << "������� �������� ������� (" << rows*cols << ") : \n";
    for (int i = 0; i < rows; i++) {
        arr2d[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> arr2d[i][j];
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

   
    const int rows = 3;
    const int cols = 4;
    int prog=0;
    int size = rows * cols;
    int* arr1d = new int[size];
    int**arr2d = new int* [rows];
   
    while(prog!=3){
        cout << "����� ��������� ���� ���������?\n";
        cout << "1-����������� ������ � ���������\n";
        cout << "2 - ��������� ������ � ����������\n";
        cout << "3 - ��������� ��������� \n ";
    cin >> prog;
    switch (prog) {
       case 1: 
       {
           exist1d(arr1d, size);
           cout << "���������� ������:" << endl;
           print1d(arr1d, size);
           unflatten(arr1d, rows, cols, arr2d);
           cout << "��������� ������:" << endl;
           print2d(arr2d, rows, cols);
           break;
       }
       case 2:
       {
           int** arr2d = new int* [rows];
           exist2d(arr2d, rows, cols);
           cout << "��������� ������ :" << endl;
           print2d(arr2d, rows, cols);
           flatten(arr2d, rows, cols, arr1d);
           cout << "���������� ������:" << endl;
           print1d(arr1d, size);
           break;
       }
       case 3: {
           std::cout << "��������� ����������";
           return 0;
       }
       default:
           std::cout << "��� ����� ���������";
    }
    }
}