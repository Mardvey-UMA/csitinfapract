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
}
