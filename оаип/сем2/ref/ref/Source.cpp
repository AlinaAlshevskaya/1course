#include <iostream>

void functionO2n ( int array[]) {
    // Первый проход по массиву
    for (int i = 0; i < array[].size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Второй проход по массиву
    for (int i = 0; i < array[].size(); i++) {
        std::cout << array[i] << " ";
    }
}

int main() {
     int array[5] = {1, 2, 3, 4, 5};
    functionO2n(array);
    return 0;
}