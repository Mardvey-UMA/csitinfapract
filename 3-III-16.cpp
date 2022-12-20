#include <iostream>
#include <cmath>
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
    cout << "Введите диапазон A B\n";
    int A,B;
    cin >> A >> B;
    realization_for(A,B);
    realization_while(A,B);
    realization_do_while(A,B);
}
