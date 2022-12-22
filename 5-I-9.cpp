//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/95
#include <iostream>
using namespace std;
typedef unsigned long long ll;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите n\n";
    ll n, s = 0, t = 1;
    cin >> n;
    for (ll i = 1; i <= n; i++){
        t*=i;
        s += t;
    }
    cout << "S = " << s;
    // 1 - 1
    // 2 - 3
    // 3 - 9
    // 20 - 2561327494111820313
    //30 - 12440637075697302041
    // 100 - 1005876315485501977
}