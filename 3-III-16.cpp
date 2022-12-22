#include <iostream>
#include <cmath>
//12 10 16 6 12 9
using namespace std;
void realization_for(int A, int B){
    for (int n = A; n <= B; n++){
        if (n < 0 && abs(n) % 2 == 0){
            cout << n << " ";
        }
    }
    cout << endl;
}
void realization_while(int A, int B){
    while(A <= B){
        if (A < 0 && abs(A) % 2 == 0){
            cout << A << " ";
        }
        A++;
    }
    cout << endl;
}
void realization_do_while(int A, int B){
    do{
        if (A < 0 && abs(A) % 2 == 0){
            cout << A << " ";
        }
        A++;
    } while (A <= B);
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");
    //Отрицательные четные числа из диапазона A B
    cout << "Введите диапазон A B\n";
    int A,B;
    cin >> A >> B;
    realization_for(A,B);
    realization_while(A,B);
    realization_do_while(A,B);
    //Тесты
    // Ввод -30 0
    // Вывод:
    //-30 -28 -26 -24 -22 -20 -18 -16 -14 -12 -10 -8 -6 -4 -2
    //-30 -28 -26 -24 -22 -20 -18 -16 -14 -12 -10 -8 -6 -4 -2
    //-30 -28 -26 -24 -22 -20 -18 -16 -14 -12 -10 -8 -6 -4 -2
    // Ввод:
    // -101 -51
    // Вывод:
    //-100 -98 -96 -94 -92 -90 -88 -86 -84 -82 -80 -78 -76 -74 -72 -70 -68 -66 -64 -62 -60 -58 -56 -54 -52
    //-100 -98 -96 -94 -92 -90 -88 -86 -84 -82 -80 -78 -76 -74 -72 -70 -68 -66 -64 -62 -60 -58 -56 -54 -52
    //-100 -98 -96 -94 -92 -90 -88 -86 -84 -82 -80 -78 -76 -74 -72 -70 -68 -66 -64 -62 -60 -58 -56 -54 -52
    // Ввод: 10 20
    // Вывод ничего
}
