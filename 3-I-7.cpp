#include <iostream>
#include <cmath>
//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/74
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    // y = |x|
    // y^2 + x^2 = 15
    // ���祪 ����� ᢥ���
    double x, y;
    cout << "Vvedite coordinaty tochek x y:\n";
    cin >> x >> y;
    double r = sqrt(x*x + y*y), eps = pow(10, -9);
    if (r < 15 && y > 0 && y > x && y > -x){
        cout << "Yes";
    }else if ((y >= 0 && y >= x && y >= -x && (r >= (15-eps) && r <= (15+eps))) || (y == abs(x) && r <= (15 + eps) )){
        cout << "On board";
    }else{
        cout << "No";
    }
    // �����:
    // 0 3.872983346207417 - �࠭��
    // 1 1 - �࠭��
    // 0 3 - ��
    // 0 -3.872983346207417 - ���
    // 0 0 - �࠭��
    // 0 -0.000001 - ���
    // 0 0.000001 - ��
}