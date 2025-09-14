#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
#include <algorithm>
using namespace std;




struct Symbol {
	char sym;
	int amount;
	Symbol* left;
	Symbol* right;
};
struct SymCodes {
	string code;
	char sym;
};
bool isLeaf(Symbol* root) {
	return root->left == nullptr && root->right == nullptr;
}


void printVector(vector<Symbol*> vector) {
	for (int i = 0; i < vector.size(); i++) {
		cout << "'" << vector[i]->sym << "'---" << vector[i]->amount << endl;
	}
}
bool compareByAmount(const Symbol* a, const Symbol* b)
{
	if(a->amount==b->amount){ return  a->sym > b->sym;
	}
	return a->amount > b->amount;

}
vector<Symbol*> Summ(vector<Symbol*> vector) {
	Symbol* tmp=new Symbol();
	tmp->amount=vector[vector.size() - 1]->amount+vector[vector.size()-2]->amount;
	tmp->left = vector[vector.size() - 2];
	tmp->right = vector[vector.size() - 1];
	tmp->sym = '$';
	vector.pop_back();
	vector.pop_back();
	vector.push_back(tmp);
	return vector;

}
void GetCode(Symbol* root, string code, map<char, string>& codes) {
	if (!root) {
		return;
	}
	if (isLeaf(root)) {
		codes[root->sym] = code;
		return;
	}
	GetCode(root->left, code + "0", codes);
	GetCode(root->right, code + "1", codes);

}
void printCodes(map<char, string>codes) {
	string encoded_line;
	for (const auto& pair : codes) {
		cout << pair.first << " : " << pair.second << endl;
		encoded_line += pair.second;
	}
	cout << endl << endl << "Encoded line: " << encoded_line << endl;
}


string haffman(string str) {
	vector<Symbol*>symbols;
	map<char, string>codes;
	
	for (int i = 0; i < str.length(); i++) {
		bool flag = false;
		for (int j = 0; j < symbols.size(); j++) {
			if (str[i]  == symbols[j]->sym) {
				flag = true;
				symbols[j]->amount++;
			}
		}
		if (!flag) {
			Symbol* symbol = new Symbol();
			symbol->sym = str[i];
			symbol->amount=1;
			symbol->left = nullptr;
			symbol->right = nullptr;
			symbols.push_back(symbol);
		}
	}
	sort(symbols.begin(), symbols.end(), compareByAmount);
	cout << "Отсортированный :" << endl;
	printVector(symbols);
	while (symbols.size() > 1) {
		Symbol* tmp = new Symbol();
		tmp->amount = symbols[symbols.size() - 1]->amount + symbols[symbols.size() - 2]->amount;
		tmp->left = symbols[symbols.size() - 2];
		tmp->right = symbols[symbols.size() - 1];
		tmp->sym = '$';
		symbols.pop_back();
		symbols.pop_back();
		symbols.push_back(tmp);
		sort(symbols.begin(), symbols.end(), compareByAmount);
	}
	GetCode(symbols[0], "", codes);
	cout << "Символы и их код:" << endl;
	printCodes(codes);
	return 0;
}

void main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	cout << "Введите строку: ";
	string str;
	getline(cin, str);
		haffman(str);

}
