#include<iostream>
#include <algorithm>
#include <unordered_set>
#include <iterator>
#include <sstream>
using namespace std;
int main() {
    setlocale(LC_CTYPE, "rus");
    const string s1{ "��� ����� �������� ������ �� ������� ���������������� � ����������������" };//��������� ����������� ������ � ��������� ����������
    const string s2{ "� ����� ������ �� ������� ���������������� � ����������������" };
    cout << s1<<"\n";//������� ������ �� �����
    cout << s2<<"\n";
    stringstream sss(s2);//������� ��������� ����� sss � ��������� ��� ���������� ������ s2
    unordered_set<string>sal{ istream_iterator<string>(sss),istream_iterator<string>() };//������� ��������������� ��������� sal � ��������� ��� ������� �� ������ sss
    sss.str("");
    sss.clear();//������� ����� sss � ��������� ��� ���������� ������ s1
    sss << s1;
    cout << *min_element(istream_iterator<string>(sss), istream_iterator<string>(), [&sal](const string& a, const string& b) {//������� �� ����� ����������� �� ����� ����� �� ������ sss, �������� ��� � ��������� sal
        return a.length() < b.length() && sal.find(a) == sal.end();
        });
    return 0;
}