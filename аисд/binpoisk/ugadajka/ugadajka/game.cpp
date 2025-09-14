#include <iostream>
#include <chrono>
#include <math.h>
#include <cstdlib>
#include <vector>
using namespace std;
void quicksort(vector<int> mas(), int first, int last) {
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; 
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) 
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} 
	while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}



int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введиче число N ";
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(N);
	vector<int> D(N);
	vector<int> E(N);
	for (int i = 0; i < N; i++) {
		A[i] = rand();
		cout << A[i] << " ";
	}
	cout << "\n";
	copy(A.begin(), arr.end(), B.begin());
	copy(A.begin(), arr.end(), C.begin());
	copy(A.begin(), arr.end(), D.begin());
	copy(A.begin(), arr.end(), E.begin());
	//
	//
	auto start = high_resolution_clock::now();
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - i - 2; j++) {
			if (B[j] > B[j + 1]) {
				swap(B[j], B[j + 1]);
			}
		}
	}
	auto end = high_resolution_clock::now();
	cout << "Пузырчатая сортировка \n";
	for (int i = 0; i < N; i++) {
		cout << B[i] << " ";
	}
	cout << "\n";
	cout << "Расчетное время циклом " << duration_cast<microseconds>(end - start).count() << " микросекунд\n";
	//
	//
	auto start = high_resolution_clock::now();
	for (i = 1; i < N; i++) {
		int buff;
		buff = C[i];
		for (j = i - 1; j >= 0 && C[j] > buff; j--)
			C[j + 1] = C[j];

		C[j + 1] = buff;
	}
	auto end = high_resolution_clock::now();
	cout << "Сортировка вставкой \n";
	for (int i = 0; i < N; i++) {
		cout << C[i] << " ";
	}
	cout << "\n";
	cout << "Расчетное время циклом " << duration_cast<microseconds>(end - start).count() << " микросекунд\n";
	//
	//
	auto start = high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		int min,buf;
		min = i;

		for (int j = i + 1; j < N; j++)
			min = (D[j] < D[min]) ? j : min;

		if (i != min) {
			buf = D[i];
			D[i] = D[min];
			D[min] = buf;
		}
	}
	auto end = high_resolution_clock::now();
	cout << "Сортировка выбора \n";
	for (int i = 0; i < N; i++) {
		cout << D[i] << " ";
	}
	cout << "\n";
	cout << "Расчетное время циклом " << duration_cast<microseconds>(end - start).count() << " микросекунд\n";
	//
	//
	auto start = high_resolution_clock::now();
	quicksort(E(N), 0, N);
	auto end = high_resolution_clock::now();
	cout << "быыстрая сортировка \n";
	for (int i = 0; i < N; i++) {
		cout << D[i] << " ";
	}
	cout << "\n";
	cout << "Расчетное время циклом " << duration_cast<microseconds>(end - start).count() << " микросекунд\n";

}
