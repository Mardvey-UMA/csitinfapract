//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/98

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

double eps = 1e-10;
using namespace std;
typedef long long li;


double binpow(double x, li n) {
    double res = 1;
    while (n) {
        if (n & 1) {
            res *= x;
            --n;
        }
        else {
            x *= x;
            n >>= 1;
        }
    }
    return res;
}


vector<double> F(double x) {
    double curr = eps + 1, s = 0;
    int n = 1;
    vector <double> res;
    while (abs(curr) > eps) {
        curr = binpow((x - 1), n) / (n * binpow((x + 1), n));
        s += curr;
        n += 2;
    }
    res.push_back(2 * s);
    res.push_back((int)(n / 2));
    return res;
}


int main() {
    cout << fixed << setprecision(2);
    double a = 1, b = 2, h = 0.1;
    cout << "# |   x  | F(x) | n \n";
    //F(x) = 2[(x-1) / (x + 1) + (x - 1)^3 / 3(x + 1)^3 + (x - 1)^5/5(x + 1)^5 + ...]
    int n = 1;
    vector <double> temp;
    while (a <= b + eps) {
        temp = F(a);
        cout << n << " | " << a << " |  " << temp[0] << "   | " << (int)temp[1] << endl;
        a += h;
        n++;
    }

}
