#include <iostream>
using namespace std;

// Функция, которая преобразует двумерный массив в одномерный
void flatten(int** arr2d, int rows, int cols, int* arr1d) {
    for (int i = 0; i < rows; i++) {  
        for (int j = 0; j < cols; j++) {
            arr1d[i*cols+j] = arr2d[i][j];
        }
    }
}

// Функция, которая преобразует одномерный массив в двумерный
void unflatten(int* arr1d, int rows, int cols, int** arr2d) {
    for (int i = 0; i < rows; i++) {
        arr2d[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr2d[i][j] = arr1d[i*cols+j];
        }
    }
}

// Функция, которая выводит двумерный массив на экран
void print2d(int** arr2d, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr2d[i][j] << " ";
        }
        cout << endl;
    }
}

// Функция, которая выводит одномерный массив на экран
void print1d(int* arr1d, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr1d[i] << " ";
    }
    cout << endl;
}

//Функция для заполнения одномерного массива с клавиатуры
void exist1d(int* arr1d, int size) {
    cout << "Введите элементы массива (" << size << ") : \n";
    for (int i = 0; i < size; i++) {
        cin >> arr1d[i];
    }
    cout << endl;
 }

//Функция для заполнения двумерного массива с клавиатуры
void exist2d(int** arr2d, int rows, int cols) {
    cout << "Введите элементы массива (" << rows*cols << ") : \n";
    for (int i = 0; i < rows; i++) {
        arr2d[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> arr2d[i][j];
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

   
    const int rows = 3;
    const int cols = 4;
    int prog=0;
    int size = rows * cols;
    int* arr1d = new int[size];
    int**arr2d = new int* [rows];
   
    while(prog!=3){
        cout << "Какую программу надо выполнить?\n";
        cout << "1-одномернный массив в двумерный\n";
        cout << "2 - двумерный массив в одномерный\n";
        cout << "3 - завершить программу \n ";
    cin >> prog;
    switch (prog) {
       case 1: 
       {
           exist1d(arr1d, size);
           cout << "Одномерный массив:" << endl;
           print1d(arr1d, size);
           unflatten(arr1d, rows, cols, arr2d);
           cout << "Двумерный массив:" << endl;
           print2d(arr2d, rows, cols);
           break;
       }
       case 2:
       {
           int** arr2d = new int* [rows];
           exist2d(arr2d, rows, cols);
           cout << "Двумерный массив :" << endl;
           print2d(arr2d, rows, cols);
           flatten(arr2d, rows, cols, arr1d);
           cout << "Одномерный массив:" << endl;
           print1d(arr1d, size);
           break;
       }
       case 3: {
           std::cout << "Программа завершенна";
           return 0;
       }
       default:
           std::cout << "Нет такой программы";
    }
    }
}