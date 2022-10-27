#include <iostream>
//9
#define ll unsigned long long
using namespace std;

ll factor(ll x){
    if (x == 0){
        return 1;
    }
    return x * factor(x - 1);
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите n\n";
    ll n, s = 0, i = 1;
    cin >> n;
    while (i <= n){
        s += factor(i);
        i++;
    }
    cout << "S = " << s;
    // 1 - 1
    // 2 - 3
    // 3 - 9
    // 20 - 2561327494111820313
    // 100 - 1005876315485501977
}
