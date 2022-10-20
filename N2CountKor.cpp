#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    setlocale(LC_ALL, "Russian");
    cout << "Введите коээфиценты квадратного уравнения\n";
    cout << "a b c\n";
    cin >> a >> b >> c;
    if (b*b - 4*a*c == 0){
        cout << "1 корень";
    }else if (b*b - 4*a*c > 0){
        cout << "2 корня";
    }else{
        cout << "Нет корней";
    }
}