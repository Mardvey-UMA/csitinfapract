#include <iostream>
#include <iomanip>
#include <cmath>
double eps = 1e-9;
using namespace std;
double f(double x){
    double t = (x*x + 2*x + 1);
    if (t < 2){
        return x*x;
    }else if (2 <= t && t < 3){
        return 1./(x*x - 1);
    }else if (t >= 3){
        return 0;
    }
}
int main(){
    cout << fixed << setprecision(3);
    double a, b, h;
    cin >> a >> b >> h;
    cout << "   x  |  f(x)" << endl;
    while (a <= (b + eps)){
        cout << a << " | " << f(a) << endl;
        a+=h;
    }
