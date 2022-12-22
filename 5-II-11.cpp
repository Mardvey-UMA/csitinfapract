//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/95
#include <iostream>

using namespace std;
typedef long long li;

double binpow(double x, li n){
    double res = 1;
    while (n){
        if (n & 1){
            res *= x;
            --n;
        }else{
            x *= x;
            n >>= 1;
        }
    }
    return res;
}

double MULT(double x, li k){
    double multiplie = 1;
    for (li n = 1; n <= k; n++){
        multiplie*=(1 + (binpow(x, n) / binpow(n, 2)));
    }
    return multiplie;
}
int main() {
    setlocale(LC_ALL, "Russian");
    li k;
    double x;
    cout << "Введите k x\n";
    cin >> k >> x;
    cout << MULT(x, k);
    //Тесты:
    //Ввод: 100 0.1 Вывод 1.10288
    //Ввод: 1 100 Вывод 101
    //Ввод: 1000000 0.001 Вывод 1.001
    //Ввод: 1 2 Вывод 3
    //Ввод: 20 0.1 Вывод 1.10288

}