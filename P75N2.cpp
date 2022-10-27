#include <iostream>
#include <cmath>
//16 12 10 16 6 12 9
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите порядковый номер дня месяца:\n";
    int n;
    cin >> n;
    if (abs(n) > 31 || n <= 0){
        cout << "Нет такого дня месяца\n";
    }else if (abs(31 - n) == 0){
        cout << "Это конец месяца";
    }else{
        cout << "Вот столько дней до конца месяца: " << abs(31 - n);
    }
Тесты
 10 Вот столько дней до конца месяца: 21
 -1 Нет такого дня месяца
 31 Это конец месяца
}
