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
    cout << "Введите e\n";
    cin >> e;
    int i = 1;
    while (fabs(curr) > e){
        curr = f(i);
        s+=curr;
        i++;
    }
    cout << s;
    //Тесты:
    //Ввод 0.00001 Вывод 0.996845
    //Ввод 1 Вывод 0
    //Ввод 0.02 Вывод 0.875
    //Ввод 0.00000001 Вывод 0.9999
    //Ввод 0.999999 Вывод 0.5
}