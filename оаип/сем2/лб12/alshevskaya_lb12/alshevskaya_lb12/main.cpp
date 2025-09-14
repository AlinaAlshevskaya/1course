#include "Heap.h"
#include <iostream>
#include <Windows.h>
using namespace std;

// Функция для сравнения двух объектов типа AAA в куче.
heap::CMP cmpAAA(void* a1, void* a2)
{
	// Приведение указателей к типу AAA.
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)

// Инициализация результата сравнения как EQUAL (равенство).
	heap::CMP rc = heap::EQUAL;

	// Сравнение значений 'x' объектов AAA.
	if (A1->x > A2->x)
		rc = heap::GREAT; // Если A1.x > A2.x, результат GREAT (больше).
	else if (A2->x > A1->x)
		rc = heap::LESS; // Если A2.x > A1.x, результат LESS (меньше).

	// Возврат результата сравнения.
	return rc;

	// Удаление макросов для предотвращения возможных конфликтов.
#undef A2
#undef A1
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// Объявление переменных.
	int k, choice, index;

	// Создание экземпляра кучи h1 с емкостью 30 и использованием функции сравнения cmpAAA.
	heap::Heap h1 = heap::create(30, cmpAAA);

	// Бесконечный цикл для взаимодействия с пользователем.
	for (;;)
	{
		// Отображение вариантов меню.
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - удалить минимальный элемент" << endl;
		cout << "5 - удалить элемент по индексу" << endl;
		cout << "6 - объединить две кучи" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;

		// Чтение выбора пользователя.
		cin >> choice;

		// Инструкции switch в зависимости от выбора пользователя.
		switch (choice)
		{
		case 0: // Выход из программы.
			exit(0);
		case 1: // Отобразить содержимое кучи.
			h1.scan(0);
			break;
		case 2: // Добавить элемент в кучу.
		{
			// Динамическое выделение памяти для объекта AAA.
			AAA* a = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			a->x = k;
			// Вставить элемент в кучу.
			h1.insert(a);
		}
		break;
		case 3: // Удалить максимальный элемент из кучи.
			h1.extractMax();
			break;
		case 4: // Удалить минимальный элемент из кучи.
			h1.extractMin();
			break;
		case 5: // Удалить элемент по индексу из кучи.
			cout << "введите индекс элемента для удаления" << endl;
			cin >> index;
			h1.extractI(index);
			break;
		case 6: // Объединить две кучи.
		{
			cout << "Создание второй кучи для объединения..." << endl;
			heap::Heap h2 = heap::create(2, cmpAAA);
			for (size_t i = 0; i < 2; i++)
			{
				// Динамическое выделение памяти для объекта AAA.
				AAA* a = new AAA;
				cout << "введите ключ" << endl;
				cin >> k;
				a->x = k;
				// Вставить элемент в кучу.
				h2.insert(a);
			}
			// Можно добавить элементы в h2 по мере необходимости.
			cout << "Объединение двух куч" << endl;
			h1.unionHeap(h2);
		}
		break;
		default: // Вывести сообщение о неправильной команде.
			cout << endl << "Введена неправильная команда!" << endl;
		}
	}
	return 0;
}