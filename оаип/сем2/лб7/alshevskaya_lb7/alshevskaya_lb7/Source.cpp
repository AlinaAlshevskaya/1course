#include <fstream> // Для работы с файлами
#include <string>  // Для работы со строками
#include <queue>   // Для работы с очередью
#include <iostream>


using namespace std;

// Функция для обработки файла
void processFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName); // Открываем файл для чтения
    ofstream outputFile(outputFileName); // Открываем файл для записи

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Ошибка открытия файлов." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) { // Читаем строки из файла
        queue<char> charQueue; // Очередь для символов
        queue<char> digitQueue; // Очередь для цифр

        // Разделяем строку на символы и цифры
        for (char c : line) {
            if (isdigit(c)) {
                digitQueue.push(c);
            }
            else {
                charQueue.push(c);
            }
        }

        // Записываем символы и цифры в файл
        while (!charQueue.empty()) {
            outputFile << charQueue.front();
            charQueue.pop();
        }
        while (!digitQueue.empty()) {
            outputFile << digitQueue.front();
            digitQueue.pop();
        }
        outputFile << endl; // Переходим на новую строку в файле
    }

    inputFile.close(); // Закрываем файл для чтения
    outputFile.close(); // Закрываем файл для записи
}

int main() {
    setlocale(LC_ALL, "ru"); // Устанавливаем локаль
    processFile("f.txt", "g.txt"); // Обрабатываем файл
    return 0; // Завершаем программу
}




