#include <iostream>
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    double x, y;
    cout << "Введите координаты точек x y:\n";
    cin >> x >> y;
    double r = sqrt(x*x + y*y), eps = pow(10, -9);
    if (r < 15 && y > 0 && y > x && y > -x){
        cout << "Да";
    }else if ((y >= 0 && y >= x && y >= -x && (r >= (15-eps) && r <= (15+eps))) || (y == abs(x) && r <= (15 + eps) )){
        cout << "На границе";
    }else{
        cout << "Нет";
    }
}
