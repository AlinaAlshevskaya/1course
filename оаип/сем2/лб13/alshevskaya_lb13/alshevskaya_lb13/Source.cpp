#include <iostream>
#include <Windows.h>
using namespace std;

struct AAA {
    int key;
    char* mas;

    AAA(int k, char* z) {
        key = k;
        mas = z;
    }

    AAA() {}
};

int key(void* d) {
    AAA* f = (AAA*)d;
    return f->key;
}

void AAA_print(void* d) {
    std::cout << " ���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << std::endl;
}

struct Object {
    void** data;
    int size;
    int N;
    int(*getKey)(void*);

    Object(int, int(*)(void*));

    bool insert(void*);
    int searchInd(int key);
    void* search(int key);
    void* deleteByKey(int key);
    bool deleteByValue(void*);
    void scan(void(*f)(void*));
};

// ������� ���������� ���� � �������������� ����������������� ���-�������.
int HashFunction(int key, int size, int p, int i) {
    const double A = 0.6180339887499; // ��������� A ��� ����������������� ���-�������
    double hashValue = key * A; // ���������� �������������� �������� ����
    hashValue -= int(hashValue); // ��������� ������� ����� �������� ����
    return (p + int(size * hashValue) + i) % size; // ������������� �������� ������� ��� ����� ��������
}

static void* DEL = (void*)-1;

Object create(int size, int(*getkey)(void*));

Object::Object(int size, int(*getkey)(void*)) {
    N = 0;
    this->size = size;
    this->getKey = getkey;
    this->data = new void* [size];
    for (int i = 0; i < size; ++i)
        data[i] = NULL;
}

bool Object::insert(void* d) {
    bool b = false; // ������������� ����� ���������� �������

    // ��������, ��������� �� ������� �� 80% ��� ������
    if ((double)N / size >= 0.8) {
        // ���� ������� ��������� �� 80% ��� ������, ���������� �� ����������

        // ���������� ������ ������� ������� (�������� �������� �������)
        int newSize = size * 2;

        // ��������� ������ ��� ����� ������ ���������� �� �������� ��� ����� �������
        void** newData = new void* [newSize];

        // ������������� ������� �������� ����� ������� ��������� NULL
        for (int i = 0; i < newSize; ++i)
            newData[i] = NULL;

        // ����������� ��������� �� ������� ������� � �����
        for (int i = 0; i < size; ++i) {
            if (data[i] != NULL && data[i] != DEL) {
                // ��������� ����� �������� ��������
                int k = key(data[i]);

                // ���������� ������� ������ �������� � ����� �������
                int index = k % newSize;

                // ����� ������� ����� � ����� ������� ��� ������� ��������
                while (newData[index] != NULL)
                    index = (index + 1) % newSize;

                // ������� �������� � ����� �������
                newData[index] = data[i];
            }
        }

        // ������������ ������, ������� ������ ��������
        delete[] data;

        // ���������� ��������� �� ������ ��� ���������� ������ �� ����� �������
        data = newData;

        // ���������� ������� �������
        size = newSize;
    }

    // ������� ������� ������ �������� � ������� �������
    // ���� �������� �� ������ �������, ������� � �������, ������������ �� ���-�������
    for (int i = 0, t = getKey(d), j = t % size; i != size && !b; j = (j + 1) % size) {
        if (data[j] == NULL || data[j] == DEL) {
            // ���� ������� ���� ���� ��� ������, ��������� �������
            data[j] = d;
            // ����������� ������� ���������� ��������� � �������
            N++;
            // ������������� ���� �������� �������
            b = true;
        }
    }
    // ���������� ��������� ������� ������� (������� ��� ���)
    return b;
}

// ������� ��� ���������� ���������� �������� ����.
int Next_hash(int hash, int size, int p)
{
    return (hash + 5 * p + 3 * p * p) % size; // ���������� ���������� �������� ���� � ������ ��������� p.
}

// ������� ��� �������� ������� ���-�������.
Object create(int size, int(*getkey)(void*))
{
    return *(new Object(size, getkey)); // �������� � ����������� ������ ������� ���-�������.
}

// ������� ��� ������ ������� �������� � ���-�������.
int Object::searchInd(int key)
{
    int t = -1; // ������������� ������� ��������.
    bool b = false; // ���� ��� ����������� ��������� ������.
    if (N != 0) // �������� ������� ��������� � �������.
    {
        for (int i = 0, j = HashFunction(key, size, 0, i); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i, i)) // ���� ������ ��������.
        {
            if (data[j] != DEL) // �������� �� ����������� ������.
            {
                if (getKey(data[j]) == key) // �������� �� ������������ ����� ��������.
                {
                    t = j; // ���������� ������� ��������.
                    b = true; // ������� ��������� ������.
                }
            }
        }
    }
    return t; // ����������� ��������� �������� (��� -1, ���� �� ������).
}

// ������� ��� ������ �������� � ���-������� �� �����.
void* Object::search(int key)
{
    int t = searchInd(key); // ����� ������� ��������.
    return (t >= 0) ? (data[t]) : (NULL); // ����������� ���������� �������� (��� NULL, ���� �� ������).
}

// ������� ��� �������� �������� �� ���-������� �� �����.
void* Object::deleteByKey(int key)
{
    int i = searchInd(key); // ����� ������� ��������.
    void* t = data[i]; // ���������� ���������� ��������.
    if (t != NULL) // �������� �� ������� �������� ��� ��������.
    {
        data[i] = DEL; // ������� ������ ��� ���������.
        N--; // ���������� ���������� ��������� � �������.
    }
    return t; // ����������� ���������� �������� (��� NULL, ���� �� ������).
}

// ������� ��� �������� �������� �� ���-������� �� ��������.
bool Object::deleteByValue(void* d)
{
    return(deleteByKey(getKey(d)) != NULL); // �������� �������� �� �����, ����������� �� ��������.
}

// ������� ��� ������������ ����������� ���-������� � ���������� � ������� �������� ��������� �������.
void Object::scan(void(*f)(void*))
{
    for (int i = 0; i < this->size; i++) // ���� ������������ ���� ����� �������.
    {
        std::cout << "�������" << i << '\t'; // ����� ������ ������.
        if ((this->data)[i] == NULL) // �������� �� ������� ������.
            std::cout << "�����" << std::endl; // ����� ��������� � ������ ������.
        else
            if ((this->data)[i] == DEL) // �������� �� ����������� ������.
                std::cout << "������" << std::endl; // ����� ��������� �� ��������� ������.
            else
                f((this->data)[i]); // ���������� ������� � ��������.
    }
}
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int siz = 10, choice, k;
    std::cout << "������� ������ ���-�������" << std::endl;
    std::cin >> siz;
    Object H = create(siz, key);
    for (;;) {
        std::cout << "1 - ����� ���-�������" << std::endl;
        std::cout << "2 - ���������� ��������" << std::endl;
        std::cout << "3 - �������� ��������" << std::endl;
        std::cout << "4 - ����� ��������" << std::endl;
        std::cout << "0 - �����" << std::endl;
        std::cout << "�������� �����" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 0:
            exit(0);
        case 1:
            H.scan(AAA_print);
            break;
        case 2: {
            AAA* a = new AAA;
            char* str = new char[20];
            std::cout << "������� ����" << std::endl;
            std::cin >> k;
            a->key = k;
            std::cout << "������� ������" << std::endl;
            std::cin >> str;
            a->mas = str;
            if (H.N == H.size)
                std::cout << "������� ���������" << std::endl;
            else
                H.insert(a);
        }
              break;
        case 3: {
            std::cout << "������� ���� ��� ��������" << std::endl;
            std::cin >> k;
            H.deleteByKey(k);
        }
              break;
        case 4: {
            std::cout << "������� ���� ��� ������" << std::endl;
            std::cin >> k;
            if (H.search(k) == NULL)
                std::cout << "������� �� ������" << std::endl;
            else
                AAA_print(H.search(k));
        }
              break;
        }
    }
    return 0;
}

