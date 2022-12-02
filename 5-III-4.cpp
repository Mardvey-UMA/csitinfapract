//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/96

#include <iostream>
#include <cmath>

using namespace std;
typedef long long li;

double f(li i){
    return 1./(i*(i + 1));
}
int main() {
    setlocale(LC_ALL, "Russian");
    double e, s = 0, curr = e + 1;
    cout << "������ e\n";
    cin >> e;
    int i = 1;
    while (fabs(curr) > e){
        curr = f(i);
        s+=curr;
        i++;
    }
    cout << s;
    //�����:
    //���� 0.00001 �뢮� 0.996845
    //���� 1 �뢮� 0
    //���� 0.02 �뢮� 0.875
    //���� 0.00000001 �뢮� 0.9999
    //���� 0.999999 �뢮� 0.5
}