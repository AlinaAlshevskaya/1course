#include <iostream>
// Определение структуры узла дерева
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Рекурсивная функция для подсчета количества листьев
int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    // Рекурсивно считаем количество листьев в левом и правом поддереве
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Пример создания бинарного дерева
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Вызываем функцию для подсчета листьев
    int leafCount = countLeaves(root);

    std::cout << "Количество листьев в дереве: " << leafCount << std::endl;

    return 0;
}