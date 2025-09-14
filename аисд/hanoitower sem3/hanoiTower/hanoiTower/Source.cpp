
#include <iostream>
using namespace std;
void HanoiTower( int N, int k,  int i){
    if (N == 1) 
        cout << "����������� ���� 1 � ������� "<< i <<" �� �������� "<<k<<endl;
    else {
        int helper = 6 - i - k;
        HanoiTower(N-1, helper, i);
        cout << "����������� ���� " << N << " � ������� " << i << " �� �������� " << k << endl;
        HanoiTower(N-1, k, helper);
    }
}
int main() {
    setlocale(LC_ALL, "russian");
    int N;
    cout << "������� ���������� ������ :";
    cin >> N;
    if (N < 1)
        cout << "������� �������� ������";
    else
    {
        int k;
        cout << "������� ����� �������, �� ������� ���� ��������� :";
        cin >> k;
        if (k > 3 || k < 2)
            cout << "������� �������� ������";
        else
            HanoiTower(N, k, 1);
    }

    return 0;
}