#include <iostream>
using namespace std;
int main(){
    int m;
    cin >> m;
    setlocale(LC_ALL, "Russian");
    switch (m) {
        case 1:
            cout << "Направо";
            break;
        case 2:
            cout << "Вверх";
            break;
        case 3:
            cout << "Вправо";
            break;
        case 4:
            cout << "Вниз";
            break;
    }
}