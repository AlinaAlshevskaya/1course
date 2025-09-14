
#include <iostream>
using namespace std;
void HanoiTower( int N, int k,  int i){
    if (N == 1) 
        cout << "ѕереместить диск 1 с стержн€ "<< i <<" на стержень "<<k<<endl;
    else {
        int helper = 6 - i - k;
        HanoiTower(N-1, helper, i);
        cout << "ѕереместить диск " << N << " с стержн€ " << i << " на стержень " << k << endl;
        HanoiTower(N-1, k, helper);
    }
}
int main() {
    setlocale(LC_ALL, "russian");
    int N;
    cout << "¬ведите количество дисков :";
    cin >> N;
    if (N < 1)
        cout << "¬ведены неверные данные";
    else
    {
        int k;
        cout << "¬ведите номер стрежн€, на который надо перенести :";
        cin >> k;
        if (k > 3 || k < 2)
            cout << "¬ведены неверные данные";
        else
            HanoiTower(N, k, 1);
    }

    return 0;
}