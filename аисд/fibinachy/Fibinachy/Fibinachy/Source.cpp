#include <iostream>
#include <chrono>
using namespace std::chrono;
int fib(int);

int main(){
	setlocale(LC_ALL, "Russian");
	int N;
	std::cout << "Введиче число N ";
	std::cin >> N;
	int Fib[100];
	Fib[0] = 0;
	Fib[1] = 1;
	auto start = high_resolution_clock::now();
	for (int i = 2; i <=N; i++) {
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	}
	std::cout <<"Число Фибоначчи =" << Fib[N - 1] << "\n";
	auto end = high_resolution_clock::now();
	std::cout << "Расчетное время циклом " <<duration_cast<microseconds>(end - start).count() << " микросекунд\n";

	auto startr = high_resolution_clock::now();
	int last;
	for (int j=0; j <N; ++j) {
		last = fib(j);
	}
	std::cout <<"Число Фибоначчи = " << last << "\n";
	auto endr = high_resolution_clock::now();
	std::cout<<"Расчетное время рекурсией " << duration_cast<microseconds>(endr - startr).count() << " микросекунд\n";
}
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}