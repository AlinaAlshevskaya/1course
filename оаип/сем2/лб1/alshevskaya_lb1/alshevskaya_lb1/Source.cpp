#include <iostream>
int fsum(int n, ...);

int main()
{
	std::cout << fsum(6, 4, 5, 1, 2, 3, 0) << std::endl;//���������� ��������
	std::cout << fsum(2, 34, 4445);//���������� �������
}

int fsum(int n, ...)
{

	int* p = &n;
	int sum = 0;
	p++;
	int k = *p;

	for (int i = 1; i < n; i++) {// ��������� ���� ������� �����
		k=k* *(++p);
		sum = sum + k;
		k = *p;
	}

	return sum;// ���������� ���������
}





