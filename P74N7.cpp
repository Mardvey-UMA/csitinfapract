#include <iostream>
#include <cmath>
// 7 2 16 12 10 16 6 12 9
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    // y = |x|
    // y^2 + x^2 = 15
    // кусочек пиццы сверху
    double x, y;
    cout << "Vvedite coordinaty tochek x y:\n";
    cin >> x >> y;
    double r = x*x + y*y, eps = pow(10, -9);
    if (r < 15 && y > 0 && y > x && y > -x){
        cout << "Yes";
    }else if ((y >= 0 && y >= x && y >= -x && (r >= (15-eps) && r <= (15+eps))) || (y == abs(x) && r <= (15 + eps) )){
        cout << "On board";
    }else{
        cout << "No";
    }
    // Тесты:
    // 0 3.872983346207417 - Граница
    // 1 1 - Граница
    // 0 3 - Да
    // 0 -3.872983346207417 - Нет
    // 0 0 - Граница
    // 0 -0.000001 - Нет
    // 0 0.000001 - Да
}
