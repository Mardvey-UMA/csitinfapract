#include <iostream>
#include <cmath>
using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    // + - вошел в область
    // - не вошел в область
    // граница
    double x, y, k;
    cout << "Введите координаты точки:\n";
    cout << "X Y\n";
    cin >> x >> y;
    k = sqrt(x*x + y*y);
    if (k > 2 && (abs(y) < 3 && abs(x) < 1)){
        cout << "+";
    }else if (((k == 2) && (abs(x) <= 1))  || (abs(y) == 3 && abs(x) <= 1) || (abs(x) == 1 && abs(y) >= sqrt(3) && abs(y) <= 3)){
        cout << "Граница";
    }else{
        cout << "-";
    }
}