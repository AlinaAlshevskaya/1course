#include <iostream>
#include <chrono>
#include <math.h>
#include <cstdlib>
#include <vector>
using namespace std;
//using namespace std::chrono;

void quicksort(vector<int>& mas, int first, int last) {
    int mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2];
    do {
        while (mas[f] < mid) f++;
        while (mas[l] >= mid) l--;
        if (f <= l)
        {
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f < l);
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
        A[i] = rand() % 100 + 1;
        cout << A[i] << " ";
    }
    cout << "\n";
    copy(A.begin(), A.end(), B.begin());
    copy(A.begin(), A.end(), C.begin());
    copy(A.begin(), A.end(), D.begin());
    copy(A.begin(), A.end(), E.begin());
    //
    //
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 2; j++) {
            if (B[j] > B[j + 1]) {
                swap(B[j], B[j + 1]);
            }
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Пузырчатая сортировка \n";
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }
    cout << "\n";
    cout << "Расчетное время циклом " << duration.count() << " микросекунд\n";
    //
    //
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int interval = N / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < N; i += 1) {
            int temp = B[i];
            int j;
            for (j = i; j >= interval && C[j - interval] > temp; j -= interval) {
                C[j] = C[j - interval];
            }
            C[j] = temp;
        }
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
    cout << "Сортировка вставкой \n";
    for (int i = 0; i < N; i++) {
        cout << C[i] << " ";
    }
    cout << "\n";
    cout << "Расчетное время циклом " << duration1.count() << " микросекунд\n";
    //
    //
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        int min, buf;
        min = i;

        for (int j = i + 1; j < N; j++)
            min = (D[j] < D[min]) ? j : min;

        if (i != min) {
            buf = D[i];
            D[i] = D[min];
            D[min] = buf;
        }
    }
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
    cout << "Сортировка выбора \n";
    for (int i = 0; i < N; i++) {
        cout << D[i] << " ";
    }
    cout << "\n";
    cout << "Расчетное время циклом " << duration.count() << " микросекунд\n";
    //
    //
    auto start3 = std::chrono::high_resolution_clock::now();
    vector<int> ptr = E;
    quicksort(ptr, 0, N - 1);
    auto stop3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);
    cout << "быыстрая сортировка \n";
    for (int i = 0; i < N; i++) {
        cout << D[i] << " ";
    }
    cout << "\n";
    cout << "Расчетное время циклом " << duration3.count() << " микросекунд\n";
}