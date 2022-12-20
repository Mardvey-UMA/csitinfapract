#include <iostream>

using namespace std;

void delet_el(int &length, int *arr, int &idx){
    for (int i = idx; i < length; i++){
        arr[i] = arr[i+1];
    }
    --length;
    --idx;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, x;
    cout << "Введите n\n";
    cin >> n;
    cout << "Введите цифру, которая должна быть последней, чтобы удалить элемент\n";
    cin >> x;
    cout << "Введите массив поэлементo\n";
    int *mas = new int[n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    
    for (int i = 0; i < n; i++)
        if (mas[i] % 10 == x)
            delet_el(n, mas, i);
    
    cout << "Полученный массив\n";
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    cout << "\n";
    //input 
    //5
    //4
    //14 13 24 15 26
    //output
    //13 15 26
    //input
    //10
    //0
    //100 100 100 100 100 0 0 10 10 1
    //output
    //1

}

