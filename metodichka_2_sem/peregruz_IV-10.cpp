#include <iostream>

using namespace std;

float F(float x){
    if ((x + 2) <= 1)
        return x*x;
    else if ((x + 2) > 1 && (x + 2) < 10)
        return 1 / (x + 2);
    else if ((x + 2) >= 10)
        return x + 2;
}
void F (float x, float &y){
    y = F(x);
}

int main(){
float x, y, step;
setlocale(LC_ALL, "Russian");
cout << "Введите шаг расчета значений\n";
cin >> step;
cout << "x  f(x)" << endl;
for (x = -1.; x <= 13.; x += step){
    cout << x << "  " << F(x) << endl;
}
cout << "------------\n";
cout << "x  f(x)" << endl;
for (x = -1.; x <= 13.; x += step){
    F(x, y);
    cout << x << "  " << y << endl;
}
}

// Введите шаг расчета значений
// 1
// x  f(x)
// -1  1
// 0  0.5
// 1  0.333333
// 2  0.25
// 3  0.2
// 4  0.166667
// 5  0.142857
// 6  0.125
// 7  0.111111
// 8  10
// 9  11
// 10  12
// 11  13
// 12  14
// 13  15
// ------------
// x  f(x)
// -1  1
// 0  0.5
// 1  0.333333
// 2  0.25
// 3  0.2
// 4  0.166667
// 5  0.142857
// 6  0.125
// 7  0.111111
// 8  10
// 9  11
// 10  12
// 11  13
// 12  14
// 13  15
