//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/179
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int sum_of_divisors(int n){
    int s = 1;
    if (n == 0){
        return s - 1;
    }
    if (n == 1){
        return s;
    }
    for (int d = 2; d < (n / 2) + 1; d++){
        if (n % d == 0){
            s += d;
        }
    }
    s+=n;
    return s;
}



int main(){
    setlocale(LC_ALL, "Russian");
    int a;
    cout << "Введите a\n";
    cin >> a;
    int sum_div_a = sum_of_divisors(a);
    for (int i = a - 1; i >= 1; i--){
        if (sum_of_divisors(i) == sum_div_a){
            cout << i;
            return 0;
        }
    }
    cout << "Таких чисел не нашлось :(";
    //Тесты
    // Ввод 15 Вывод 14
    // Ввод 1 Вывод Таких чисел не нашлось :(
    // Ввод 15 Вывод 14
    // Ввод 17 Вывод 10
    // Ввод 244 Вывод 208

}