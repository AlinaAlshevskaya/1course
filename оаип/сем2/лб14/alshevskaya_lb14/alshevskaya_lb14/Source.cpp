#include <iostream>
#include <chrono> // ��� ��������� ������� ���������� ����������
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime> // ��� ������������� ���������� ��������� �����

using namespace std;

// ������� ��� ���������� ������� ������� ������
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

// ������� ��� ���������� ������� ������� �������
void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// ������� ��� ���������� ������� ������� �����
void shellSort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; ++i) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "������� ������ ������� A: ";
	cin >> n;

	// ���������� ������ A
	int* A = new int[n]; // ��������� ������ ��� ������ A
	srand(time(0)); // ������������� ���������� ��������� �����
	cout << "������ A:\n";
	for (int i = 0; i < n; ++i) {
		A[i] = rand() % 100; // ��������� ��������� ����� �� 0 �� 99
		cout << A[i] << " ";
	}
	cout << endl;

	// ������� ������������ ������� � ������� A � ��� ������
	int maxElement = A[0];
	int maxIndex = 0;
	for (int i = 1; i < n; ++i) {
		if (A[i] > maxElement) {
			maxElement = A[i];
			maxIndex = i;
		}
	}

	// ������� ������ B � ��������� �������� �������� ������ ������������� �������� �� ������� A
	int* B = new int[n]; // ��������� ������ ��� ������ B
	int countB = 0; // ���������� ��� �������� ��������� � ������� B
	for (int i = maxIndex + 1; i < n; ++i) {
		if (i % 2 != 0) {
			B[countB] = A[i];
			countB++;
		}
	}

	// �������� ����� ���������� ���������� �������
	auto start = chrono::high_resolution_clock::now(); // ������ ��������� �������
	selectionSort(B, countB);
	auto end = chrono::high_resolution_clock::now(); // ����� ��������� �������
	chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start); // ���������� ����������������� ������� � �������������
	cout << "���������� ������� ������ ������: " << duration.count() << " �����������" << endl;

	// ������� ��������������� ������ B
	cout << "������ B (��������������� ������� ������):\n";
	for (int i = 0; i < countB; ++i) {
		cout << B[i] << " ";
	}
	cout << endl;

	// �������� ������ A � ������ B � ��������� �������� �������� ������ ������������� �������� �� ������� A
	countB = 0; // ���������� ������� ��������� � ������� B
	for (int i = maxIndex + 1; i < n; ++i) {
		if (i % 2 != 0) {
			B[countB] = A[i];
			countB++;
		}
	}

	// �������� ����� ���������� ���������� ������� ������� �������
	start = chrono::high_resolution_clock::now(); // ������ ��������� �������
	insertionSort(B, countB);
	end = chrono::high_resolution_clock::now(); // ����� ��������� �������
	duration = chrono::duration_cast<chrono::microseconds>(end - start); // ���������� ����������������� ������� � �������������
	cout << "���������� ������� ������� ������� ������: " << duration.count() << " �����������" << endl;

	// ������� ��������������� ������ B
	cout << "������ B (��������������� ������� ������� �������):\n";
	for (int i = 0; i < countB; ++i) {
		cout << B[i] << " ";
	}
	cout << endl;

	// �������� ������ A � ������ B � ��������� �������� �������� ������ ������������� �������� �� ������� A
	countB = 0; // ���������� ������� ��������� � ������� B
	for (int i = maxIndex + 1; i < n; ++i) {
		if (i % 2 != 0) {
			B[countB] = A[i];
			countB++;
		}
	}

	// �������� ����� ���������� ���������� ������� �����
	start = chrono::high_resolution_clock::now(); // ������ ��������� �������
	shellSort(B, countB);
	end = chrono::high_resolution_clock::now(); // ����� ��������� �������
	duration = chrono::duration_cast<chrono::microseconds>(end - start); // ���������� ����������������� ������� � �������������
	cout << "���������� ������� ����� ������: " << duration.count() << " �����������" << endl;

	// ������� ��������������� ������ B
	cout << "������ B (��������������� ������� �����):\n";
	for (int i = 0; i < countB; ++i) {
		cout << B[i] << " ";
	}
	cout << endl;

	// ����������� ���������� ������ ��� �������� A � B
	delete[] A;
	delete[] B;

	return 0;
}
