#pragma once
// Макрос для обозначения удаленного элемента в хеш-таблице.
#define HASHDEL (void*) -1

// Структура для представления хеш-таблицы.
struct Object
{
    void** data; // Массив указателей на элементы хеш-таблицы.
    int size; // Размер хеш-таблицы.
    int N; // Количество элементов в хеш-таблице.
    int(*getKey)(void*); // Указатель на функцию для получения ключа элемента.

    // Конструктор с параметрами.
    Object(int, int(*)(void*));

    // Методы для работы с хеш-таблицей.
    bool insert(void*);
    int searchInd(int key);
    void* search(int key);
    void* deleteByKey(int key);
    bool deleteByValue(void*);
    void scan(void(*f)(void*));
};

// Указатель на удаленный элемент.
static void* DEL = (void*)HASHDEL;

// Функция для создания объекта хеш-таблицы.
Object create(int size, int(*getkey)(void*));

// Отмена определения макроса HASHDEL.
#undef HASHDEL

