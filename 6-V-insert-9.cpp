#include <iostream>

using namespace std;

void swap(int& x1, int& x2) {
    int temp;
    temp = x2;
    x2 = x1;
    x1 = temp;
}

void insert(int pos, int* arr, int &lenghts){
    for (int i = lenghts; i > pos; i--){
        swap(arr[i], arr[i - 1]);
    }
    lenghts++;
}


int main(){
int n, x, m;
setlocale(LC_ALL, "Russian");
    cout << "Введите n\n";
    cin >> n;
    cout << "Введите число для вставки\n";
    cin >> x;
    cout << "Введите последнюю цифра элемента, после которого вставить\n";
    cin >> m;
    cout << "Введите массив поэлементo\n";
    int *mas = new int[n*2];

    for (int i = 0; i < 2*n; i++)
        mas[i] = x;
    
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    
    int k = n;

    for (int i = 0; i < n; i++){
        if (mas[i] % 10 == m){
            i++;
            insert(i, mas, k);
        }
    }

    for (int i = 0; i < k + 1; i++)
        cout << mas[i] << " ";
    cout << endl;
    //input 
    //6
    //0
    //1
    //11 12 13 21 22 11
    //output
    //11 0 12 13 21 0 22 11 0
    //input 
    //3
    //-1
    //5
    //15 15 15
    //15 -1 15 -1 15 -1
    
}


