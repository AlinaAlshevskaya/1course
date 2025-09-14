#include <iostream>
#include <vector>
#include <string>
using namespace std;


void printMatrix(vector<vector<int>>matrix, int lines, int columns) {
	cout << "Матрица:" << endl;
	cout << '\t';
	for (int w = 0; w < columns; w++) {
		cout << w << '\t';
	}
	cout << endl << endl;
	for (int i = 0; i < lines; i++) {
		cout << '\t';
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << '\t' << i << endl;
	}
}



void packBag(int MAX_bag_weight, int number_of_things) {

	vector<int>weights(number_of_things);
	vector<int>profits(number_of_things);
	vector<string>names(number_of_things);


	for (int i = 0; i < number_of_things; i++) {
		cout << "Вещ номер " << i + 1 << endl;
		
		cout << "Введите название вещи: ";
		cin >> names[i];
		cout << "Введите вес вещи: ";
		cin >> weights[i];
		cout << "Введите стоимость вещи: ";
		cin >> profits[i];
		cout << endl;
		
	}
	for (int i = 0; i < number_of_things; i++) {
		cout << "{" << names[i] << ',' << weights[i] << ',' << profits[i] << '}';
	}
	cout << endl << endl;

	vector<vector<int>>matrix(number_of_things + 1, vector<int>(MAX_bag_weight + 1));
	for (int i = 0; i < number_of_things + 1; i++) {
		for (int j = 0; j < MAX_bag_weight + 1; j++) {
			matrix[i][j] = 0;
		}
	}
	printMatrix(matrix, number_of_things + 1, MAX_bag_weight + 1);

	for (int i = 0; i < number_of_things + 1; i++) {
		for (int j = 0; j < MAX_bag_weight + 1; j++) {
			
			if (i == 0 || j == 0) {
				matrix[i][j] = 0;
			}
			else if (weights[i - 1] <= j) {
				matrix[i][j] = max(profits[i - 1] + matrix[i - 1][j - weights[i - 1]], matrix[i - 1][j]);
			}
			else { 
				matrix[i][j] = matrix[i - 1][j];
			}
			
		}
	}
	printMatrix(matrix, number_of_things + 1, MAX_bag_weight + 1);

	cout << "Максимальная стоимость: " << matrix[number_of_things][MAX_bag_weight] << endl;


	vector<int>itemsInBackpack;
	int current_row = number_of_things;
	int current_column = MAX_bag_weight;
	while (current_column > 0 && current_row > 0) {
		if (matrix[current_row][current_column] != matrix[current_row - 1][current_column]) {
			itemsInBackpack.push_back(current_row - 1);
			current_column -= weights[current_row - 1];
		}
		current_row--;
	}
	cout << "<-----Элементы в рюкзаке----->" << endl;
	for (int i = 0; i < itemsInBackpack.size(); i++) {
		cout << "Номер вещи " << i + 1 << ": ";
		cout << '{';
		cout << "Назвиние: " << names[itemsInBackpack[i]] << " , ";
		cout << "Вес: " << weights[itemsInBackpack[i]] << " , ";
		cout << "Стоимость: " << profits[itemsInBackpack[i]] << "}";
		cout << endl;
	}
}


void main() {
	setlocale(LC_ALL, "Russian");
	int MAX_bag_weight;
	cout << "Введите максимальный вес рюкзака: ";
	cin >> MAX_bag_weight;
	int amount_of_stuff;
	cout << "Введите количесво имеющихся вещей: ";
	cin >> amount_of_stuff;
	packBag(MAX_bag_weight, amount_of_stuff);
}
