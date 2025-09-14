#include <fstream> // ��� ������ � �������
#include <string>  // ��� ������ �� ��������
#include <queue>   // ��� ������ � ��������
#include <iostream>


using namespace std;

// ������� ��� ��������� �����
void processFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName); // ��������� ���� ��� ������
    ofstream outputFile(outputFileName); // ��������� ���� ��� ������

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "������ �������� ������." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) { // ������ ������ �� �����
        queue<char> charQueue; // ������� ��� ��������
        queue<char> digitQueue; // ������� ��� ����

        // ��������� ������ �� ������� � �����
        for (char c : line) {
            if (isdigit(c)) {
                digitQueue.push(c);
            }
            else {
                charQueue.push(c);
            }
        }

        // ���������� ������� � ����� � ����
        while (!charQueue.empty()) {
            outputFile << charQueue.front();
            charQueue.pop();
        }
        while (!digitQueue.empty()) {
            outputFile << digitQueue.front();
            digitQueue.pop();
        }
        outputFile << endl; // ��������� �� ����� ������ � �����
    }

    inputFile.close(); // ��������� ���� ��� ������
    outputFile.close(); // ��������� ���� ��� ������
}

int main() {
    setlocale(LC_ALL, "ru"); // ������������� ������
    processFile("f.txt", "g.txt"); // ������������ ����
    return 0; // ��������� ���������
}




