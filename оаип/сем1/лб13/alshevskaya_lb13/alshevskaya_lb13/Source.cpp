#include<iostream>
#include <algorithm>
#include <unordered_set>
#include <iterator>
#include <sstream>
using namespace std;
int main() {
    setlocale(LC_CTYPE, "rus");
    const string s1{ "Мне очень нравятся лекции по основам аргоритмитизации и программирования" };//объявляем константные строки и заполняем содержимым
    const string s2{ "Я люблю лекции по основам алгоритмитизации и программирования" };
    cout << s1<<"\n";//выводим строки на экран
    cout << s2<<"\n";
    stringstream sss(s2);//Создаем строковый поток sss и заполняет его содержимым строки s2
    unordered_set<string>sal{ istream_iterator<string>(sss),istream_iterator<string>() };//Создаем неупорядоченное множество sal и заполняет его словами из потока sss
    sss.str("");
    sss.clear();//Очищаем поток sss и заполняем его содержимым строки s1
    sss << s1;
    cout << *min_element(istream_iterator<string>(sss), istream_iterator<string>(), [&sal](const string& a, const string& b) {//Выводим на экран минимальное по длине слово из потока sss, которого нет в множестве sal
        return a.length() < b.length() && sal.find(a) == sal.end();
        });
    return 0;
}