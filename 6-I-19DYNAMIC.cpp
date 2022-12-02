//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/140
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    int flag;
    cout << "Введите : Одномерный - 1 Двумерный - 2\n";
    cin >> flag;
    if (flag == 1){
        int n;
        cout << "Введите размерность массива - n\n";
        cin >> n;
        int *arr = new int[n];
        cout << "Введите элементы массива\n";
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << "Ответ:" << endl;
        for (int i = 0; i < n; i++){
            if (!(i & 1))
                cout << arr[i] << " ";
        }
    }else if (flag == 2){
        int m, n;
        cout << "Введите количество СТРОК и СТОЛБЦОВ массива соответсвенно:\n";
        cin >> n >> m;
        cout << "Вводите массив по строчкам:\n";
        int **arr;
        arr = new int *[n];
        for(int i = 0; i < n; ++i)
            arr[i]= new int [m];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> arr[i][j];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if ((i + j) % 2 == 0)
                    cout << arr[i][j] << " ";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }else{
        cout << "Нет такого варианта .....";
    }
    //Тесты:
    //Ввод
    // 2
    // 3 5
    // 1 2 3 4 5
    // 1 2 3 4 5
    // 1 2 3 4 5
    // Вывод:
    // 1  3  5
    //  2  4
    // 1  3  5
    //Ввод
    // 1
    // 5
    // 1 2 3 4 5
    // Вывод:
    // 1  3  5
    // Ввод
    // 100
    // Вывод
    // Нет такого варианта .....

}