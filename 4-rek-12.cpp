//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/84

#include <iostream>
using namespace std;

//b1 = 0.5 b2 = 0.2 b(n+1) = b^2(n) + b(n-1)/n

int main() {
    setlocale(LC_ALL, "Russian");
    double b1 = 0.5, b2 = 0.2,b_n;
    int n;
    cout << "Введите n:\n";
    cin >> n;
    if (n == 1){
        cout << "b1" << " - " << b1;
    }else if (n == 2){
        cout << "b1" << " - " << b1 << " " << "b2" << " - " << b2;
    }else{
        cout << "b1" << " - " << b1 << " " << "b2" << " - " << b2 << " ";
        int y = n;
        n = 3;
        while(n <= y){
            b_n = b2*b2 + (b1 / n);
            b1 = b2;
            b2 = b_n;
            cout << "b" << n << " - " << b_n << " ";
            n++;
        }
    }
    // Ввод 5
    // b1 - 0.5 b2 - 0.2 b3 - 0.206667 b4 - 0.0927111 b5 - 0.0499287
    // Ввод 10
    // b1 - 0.5 b2 - 0.2 b3 - 0.206667 b4 - 0.0927111 b5 - 0.0499287 b6 - 0.0179447 b7 - 0.00745468 b8 - 0.00229866 b9 - 0.0008
    // Ввод 3
    // b1 - 0.5 b2 - 0.2 b3 - 0.206667
    // Ввод 1
    // b1 - 0.5
    // Ввод 2
    // b1 - 0.5 b2 - 0.2
}