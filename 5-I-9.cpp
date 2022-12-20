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
}
