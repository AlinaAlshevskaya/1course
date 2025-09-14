#include <iostream>
#include <windows.h>
#include <cwctype>
int main()
{
setlocale(LC_CTYPE, "Russian");
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
int code, remainder,u,com;
char Letter,number ;
std::cout << ".Варианты использования :\n";
std::cout << " 1 – определение разницы значений кодов в ASCII буквы в прописном и строчном написании, если введен символ латинского алфавита, иначе вывод сообщения об ошибке;\n";
std::cout << "2 – определение разницы значений кодов в Windows - 1251 буквы в прописном и строчном написании, если введен символ русского алфавита, иначе вывод сообщения об ошибке;\n";
std::cout << "3 – вывод в консоль кода символа, соответствующего введенной цифре, иначе вывод сообщения об ошибке;\n";
std::cout << " 4– выход из программы.Текст сообщения об ошибке произвольный.\n";
std::cout << "Введите номер программы (от 1 до 4): ";
std::cin >> com;
switch (com)
{
case 1: {
	
	std::cout << "Введите количество символов: ";
	std::cin >> u;
	for (int i = 1; i < (u + 1);) {
		std::cout << "Введите букву латинского алфавита ";
		std::cin >> Letter;
		if ('A' <= Letter && Letter <= 'z')
		{
			remainder = tolower(Letter) - toupper(Letter);
			std::cout << remainder;
		}
		else
			std::cout << "Вы ввели не букву латинского алфавита ";
		i++;
	}break; }
case 2:{  
	std::cout << "Введите количество символов: ";
	std::cin >> u;
	for (int i = 1; i < (u + 1);) {
		std::cout << "Введите букву русского алфавита ";
		std::cin >> Letter;
		if ('А' <= Letter && Letter <= 'я')
		{
			remainder = tolower(Letter) - toupper(Letter);
			std::cout << remainder;
		}
		else std::cout << "Вы ввели не букву русского алфавита ";
		i++;
	}break; }
case 3: {
	std::cout << "Введите количество символов: ";
	std::cin >> u;
	for (int i = 1; i < (u + 1);) 
		{
			std::cout << "Введите цифру ";
			std::cin >> number;
			if ('1' <= number && number <= '9')
			{
				code = number;
				std::cout << "Код символа : " << code;
			}
			else std::cout << "Это не цифра";
			i++;
		}break;
	}
case 4:{
	std::cout << "Программа завершенна";
	return 0;
}
default:
	std::cout << "Нет такой программы";
}
return 0;
}