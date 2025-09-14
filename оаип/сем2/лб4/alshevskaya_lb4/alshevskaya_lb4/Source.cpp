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
	// сортируем сонатории по лечебным профилям
	for (int i = 0; i < MAX_SANATORIUMS - 1; i++) {
		for (int j = 0; j < MAX_SANATORIUMS - i - 1; j++) {
			if (sanatoriums[j].profile > sanatoriums[j + 1].profile) {
				Sanatorium temp = sanatoriums[j];
				sanatoriums[j] = sanatoriums[j + 1];
				sanatoriums[j + 1] = temp;
			}
		}
	}

	// Pвывод отсортированой структуры
	std::cout << "Name            Location     Profile       Quantity" << std::endl;
	for (int i = 0; i < MAX_SANATORIUMS; i++) {
		printSanatorium(sanatoriums[i]);
	}

	// посик санотория по имени
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
			cout << "\nФИО "; 	cin >> list_of_people[p].fio;
			cout << "дата рождения ( в формате дд.мм.гггг)  "; 	cin >> list_of_people[p].date;
			cout << "Адрес(Город, улица, дом, квартира) ";    cin >> list_of_people[p].adres;
			cout << "Пол (м/ж) ";     cin >> list_of_people[p].sex;
			
		}
}

void output( )
{
		for(int i=0;i<number;i++)
		{
			cout << "\nФИО " << list_of_people[i].fio << endl;
			cout << "дата рождения ( в формате дд.мм.гггг)  "<< list_of_people[i].date << endl;
			cout << "Адрес(Город, улица, дом, квартира)"<< list_of_people[i].adres <<endl;
			cout << "Пол (м/ж)" << list_of_people[i].sex << endl;
		}
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить " << endl;  cin >> d;
	for (int de1 = (d - 1); de1 < number-1; de1++) {
		list_of_people[de1] = list_of_people[de1+1];
	}
	number = number - 1;
}


void find(char date[10])
{
	bool flag = false; 
	for(int i=0; i<number; i++)
			if (strcmp(date, list_of_people[i].date) == 0)   //сравнение строк
			{
				cout << "ФИО " << list_of_people[i].fio << endl;
				cout << "дата рождения ( в формате дд.мм.гггг)  " << list_of_people[i].date << endl;
				cout << "Адрес(Город, улица, дом, квартира)" << list_of_people[i].adres << endl;
				cout << "Пол (м/ж)" << list_of_people[i].sex << endl;
				flag = true; break;
			}
		if (!flag) cout << "Ничего не найдено\n";
}

void filewriting() {
	ofstream file("data.txt");
	for (int i = 0; i < number; i++)

	{
		file<< "\nФИО " << list_of_people[i].fio << endl;
		file << "дата рождения ( в формате дд.мм.гггг)  " << list_of_people[i].date << endl;
		file << "Адрес(Город, улица, дом, квартира)" << list_of_people[i].adres << endl;
		file << "Пол (м/ж)" << list_of_people[i].sex << endl;
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

