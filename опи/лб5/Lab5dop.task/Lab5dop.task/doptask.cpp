#include <iostream>
	int main()
	{
		int ready, eggs, pan;
		setlocale(LC_CTYPE, "Russian");
		using namespace std;
		std::cout << "Включить плиту\n";
		std::cout << "Поставить сковородку греться\n";
		std::cout << "Достать миску\n";
		std::cout << "Достать яйца и молоко\n";
		std::cout << "Яйца большие? ( 1- да; 2-нет)\n";
		std::cin >> eggs;
		if (eggs == 1)
		{
			std::cout << "Разбить 2 яйца и добавить 4 ложки молока\n";
		}
		else if (eggs == 2)
		{
			std::cout << "Разбить 3 яйца и добавить 6 ложки молока\n";
		}
		else
		{
			std::cout << "Нет такого варианта\n";
			return 0;
		}
		std::cout << "Всё в миске перемешать\n";
		std::cout << "Сковородка горячая? ( 1- да;2-нет)\n";
		std::cin >> pan;
		while (pan != 1)
		{
		std::cout<<"Ждём";
		std::cout<<"Сковородка горячая ( 1- да; 2-нет)\n";
			std::cin >> pan;
		}
		std::cout << "Выливаем в сковородку содержимое миски.Мешаем\n";
		std::cout << "Омлет готов?(1- да; 2- нет))\n";
		std::cin >> ready;
		while (ready != 1)
		{
		std::cout<<"Жарим и постоянно помешиваем\n";
		std::cout<<"Омлет готов?(1- да;2-нет)\n";
			std::cin >> ready;
		}
	std::cout<<"Снять с плиты\n";
	std::cout<<"Омлет готов\n";
		return 0;
	}
	