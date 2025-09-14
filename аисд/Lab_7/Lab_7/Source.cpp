#include <iostream>
#include <cstdlib>
using namespace std;




void main() {
    setlocale(LC_ALL, "RUS");
    int N;
    cout << "�����: "; cin >> N;
    int* arr = new int[N];
    int* lengthes = new int[N];
    int* path = new int[N];

    for (int i = 0; i < N; i++)
    {
        cout << "������� " << i + 1 << ": "; cin >> arr[i];
        lengthes[i] = 1;
        path[i] = -1;
    }
    cout << endl;

    cout << "������������������: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lengthes[i] <= lengthes[j]) {
                lengthes[i] = lengthes[j] + 1;
                path[i] = j;
            }
        }
    }

    int max = 0;
    int max_versh = 0;
    for (int i = 0; i < N; i++)
    {
        if (lengthes[i] >= max)
        {
            max_versh = i;
            max = lengthes[i];
        }
    }
    cout << "����� ���� ���������������������: " << max << endl;


    cout << "����� ���������������������� �� ������: ";
    for (int i = 0; i < N; i++)
    {
        cout << lengthes[i] << " ";
    }
    cout << endl;

    cout << "���� �� ������� � �������: ";
    for (int i = 0; i < N; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;


    int out[100];
    for (int i = max; i >= 0; i--)
    {
        out[i] = arr[max_versh];
        max_versh = path[max_versh];
    }

    cout << "������������ ������������ ���������������������: ";
    for (int i = 1; i < max + 1; i++)
    {
        cout << out[i] << " ";
    }
    delete[] arr;
    delete[] lengthes;
    delete[] path;
}