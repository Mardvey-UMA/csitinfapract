#include <iostream>
using namespace std;

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
}
