#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "Введите размерность массива\n";
    int n, pos = 0;
    cin >> n;
    int arr[n];
    cout << "Введите элементы массива\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int min = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] < min && pos <= i){
            pos = i;
            min = arr[i];
        }
    }
    cout << pos;
}
