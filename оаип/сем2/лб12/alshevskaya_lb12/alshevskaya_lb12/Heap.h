#pragma once
struct AAA
{
	int x;
	void print();
};
namespace heap
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Heap
	{
		int size; // Текущий размер кучи
		int maxSize; // Максимальный размер кучи
		void** storage; // Массив указателей на данные
		CMP(*compare)(void*, void*); // Указатель на функцию сравнения
		Heap(int maxsize, CMP(*f)(void*, void*))
		{
			size = 0;
			storage = new void* [maxSize = maxsize]; // Выделение памяти под массив хранения данных
			compare = f; // Инициализация указателя на функцию сравнения
		};
		int left(int ix); // Возвращает индекс левого потомка для элемента с индексом ix.
		int right(int ix); // Возвращает индекс правого потомка для элемента с индексом ix.
		int parent(int ix); // Возвращает индекс родительского элемента для элемента с индексом ix.

		bool isFull() const
		{
			return (size >= maxSize); // Проверка, заполнена ли куча
		};
		bool isEmpty() const
		{
			return (size <= 0); // Проверка, пуста ли куча
		};
		bool isLess(void* x1, void* x2) const
		{
			return compare(x1, x2) == LESS; // Проверка, является ли x1 меньшим чем x2
		};
		bool isGreat(void* x1, void* x2) const
		{
			return compare(x1, x2) == GREAT; // Проверка, является ли x1 большим чем x2
		};
		bool isEqual(void* x1, void* x2) const
		{
			return compare(x1, x2) == EQUAL; // Проверка, равны ли x1 и x2
		};

		void swap(int i, int j); // Меняет местами элементы с индексами i и j
		void heapify(int ix); // Поддерживает свойство кучи, начиная с элемента с индексом ix
		void insert(void* x); // Вставляет новый элемент в кучу
		void* extractMax(); // Извлекает и возвращает максимальный элемент кучи
		void scan(int i) const; // Сканирует элемент с индексом i
		void* extractMin(); // Извлекает и возвращает минимальный элемент кучи
		void extractI(int i); // Извлекает элемент с индексом i
		void unionHeap(Heap& h2); // Объединяет две кучи

	};
	Heap create(int maxsize, CMP(*f)(void*, void*)); // Создание кучи

};