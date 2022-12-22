#include <iostream>

using namespace std;

int main(){
    int **matrix;
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите n\n";
    cin >> n;
    matrix = new int *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
    cout << "Введите массив по строчкам\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    ///////
    int s = 0, max_;
    for (int i = 0; i < n; i++){
        max_ = matrix[i][0];
        for (int j = 0; j < n; j++){
            if (matrix[i][j] > max_)
                max_ = matrix[i][j];
            }
        s+=max_;
        }
    cout << s << endl;
    ///////
    //3
    //  1 2 3
    //  1 2 3
    //  1 2 3  
    // 9
    //4
    //1 2 3 4
    //5 4 7 8
    //9 10 11 12
    //13 14 15 16
    // 40
}


