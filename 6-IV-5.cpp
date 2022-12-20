#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    int **matrix;
    int n;
    cout << "Введите n\n";
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i] = new int[n];
    cout << "Введите массив по строчкам\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    int *vectoritto = new int[n];
    int *multi = new int[n];
    for (int i = 0; i < n; i++)
        multi[i] = 0;
    cout << "Введите вектор(длины n)\n";
    for (int i = 0; i < n; i++)
        cin >> vectoritto[i];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            multi[i]+=matrix[i][j]*vectoritto[j];
        }
    }
    ///////
    for (int i = 0; i < n; i++)
        cout << multi[i] << endl;
    //input
    //3
    //1 2 3
    //1 2 3
    //1 2 3
    //5 5 5
    //output
    //30
    //30
    //30
    //input
    //3
    //1	2 3
    //3	1 2
    //2	1 3
    //4 0 -2
    //-2 8 2
}


