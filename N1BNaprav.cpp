#include <iostream>
using namespace std;
int main(){
    int m;
    cin >> m;
    setlocale(LC_ALL, "Russian");
    switch (m) {
        case 1:
            cout << "Горизонтально";
            break;
        case 2:
            cout << "Вертикально";
            break;
        case 3:
            cout << "Горизонтально";
            break;
        case 4:
            cout << "Вертикально";
            break;
    }
}