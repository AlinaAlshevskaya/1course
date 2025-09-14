#include <iostream>
int fsum(int n, ...);

int main()
{
	std::cout << fsum(6, 4, 5, 1, 2, 3, 0) << std::endl;//используем фунцкцию
	std::cout << fsum(2, 34, 4445);//используем функцию
}

int fsum(int n, ...)
{

	int* p = &n;
	int sum = 0;
	p++;
	int k = *p;

	for (int i = 1; i < n; i++) {// использу€ цикл находим суммы
		k=k* *(++p);
		sum = sum + k;
		k = *p;
	}

	return sum;// возвращаем результат
}





