#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x){
    return 3./abs(x*x*x + 8);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << fixed << setprecision(6);
    double  a, b, h, m = 0.00000999;
    cout << "Введите значения A B и шаг h:\n";
    cin >> a >> b >> h;
    while (a <= (b + m)){
        if (a >= -2 - m && a <= -2 + m)
            cout << a << "\tundefined" << endl;
        else
            cout << a << "\t" << f(a) << endl;
        a+=h;
    }
}