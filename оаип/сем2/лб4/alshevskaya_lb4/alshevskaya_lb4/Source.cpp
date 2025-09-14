#include <iostream>
using namespace std;

struct Sanatorium {
	string name;
	string location;
	string profile;
	int quantity;
};

void printSanatorium(const Sanatorium& sanatorium) {
	std::cout << sanatorium.name << "\t" << sanatorium.location << "      " << sanatorium.profile << "     " << sanatorium.quantity << std::endl;
}

int main() {
	const int MAX_SANATORIUMS = 5;
	Sanatorium sanatoriums[MAX_SANATORIUMS] = {
	{"Relax   ", "Belarus", "joints   ", 1},
	{"Holidays", "Russia ", "lungs    ", 3},
	{"Family  ", "Italy  ", "legs     ", 15},
	{"InForest", "Filand ", "nevrology", 11},
	{"Green   ", "Filand ", "heart    ", 18}
	};
	// ��������� ��������� �� �������� ��������
	for (int i = 0; i < MAX_SANATORIUMS - 1; i++) {
		for (int j = 0; j < MAX_SANATORIUMS - i - 1; j++) {
			if (sanatoriums[j].profile > sanatoriums[j + 1].profile) {
				Sanatorium temp = sanatoriums[j];
				sanatoriums[j] = sanatoriums[j + 1];
				sanatoriums[j + 1] = temp;
			}
		}
	}

	// P����� �������������� ���������
	std::cout << "Name            Location     Profile       Quantity" << std::endl;
	for (int i = 0; i < MAX_SANATORIUMS; i++) {
		printSanatorium(sanatoriums[i]);
	}

	// ����� ��������� �� �����
	std::string searchName;
	std::cout << "\nEnter the name of the sanatorium you want to search for: ";
	std::cin >> searchName;

	bool found = false;
	for (int i = 0; i < MAX_SANATORIUMS; i++) {
		if (sanatoriums[i].name == searchName) {
			std::cout << "Sanatorium found:" << std::endl;
			printSanatorium(sanatoriums[i]);
			found = true;
			break;
		}
	}

	if (!found) {
		std::cout << "Sanatorium not found." << std::endl;
	}

	return 0;
}


/*
void input(int size)
{
	
		for (int p = 0; p < size; p++)
		{
			cout << "\n��� "; 	cin >> list_of_people[p].fio;
			cout << "���� �������� ( � ������� ��.��.����)  "; 	cin >> list_of_people[p].date;
			cout << "�����(�����, �����, ���, ��������) ";    cin >> list_of_people[p].adres;
			cout << "��� (�/�) ";     cin >> list_of_people[p].sex;
			
		}
}

void output( )
{
		for(int i=0;i<number;i++)
		{
			cout << "\n��� " << list_of_people[i].fio << endl;
			cout << "���� �������� ( � ������� ��.��.����)  "<< list_of_people[i].date << endl;
			cout << "�����(�����, �����, ���, ��������)"<< list_of_people[i].adres <<endl;
			cout << "��� (�/�)" << list_of_people[i].sex << endl;
		}
}
void del()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� " << endl;  cin >> d;
	for (int de1 = (d - 1); de1 < number-1; de1++) {
		list_of_people[de1] = list_of_people[de1+1];
	}
	number = number - 1;
}


void find(char date[10])
{
	bool flag = false; 
	for(int i=0; i<number; i++)
			if (strcmp(date, list_of_people[i].date) == 0)   //��������� �����
			{
				cout << "��� " << list_of_people[i].fio << endl;
				cout << "���� �������� ( � ������� ��.��.����)  " << list_of_people[i].date << endl;
				cout << "�����(�����, �����, ���, ��������)" << list_of_people[i].adres << endl;
				cout << "��� (�/�)" << list_of_people[i].sex << endl;
				flag = true; break;
			}
		if (!flag) cout << "������ �� �������\n";
}

void filewriting() {
	ofstream file("data.txt");
	for (int i = 0; i < number; i++)

	{
		file<< "\n��� " << list_of_people[i].fio << endl;
		file << "���� �������� ( � ������� ��.��.����)  " << list_of_people[i].date << endl;
		file << "�����(�����, �����, ���, ��������)" << list_of_people[i].adres << endl;
		file << "��� (�/�)" << list_of_people[i].sex << endl;
	}
		file.close();

}
void filereading() {
	ifstream file("data.txt");
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	file.close();

}
*/

