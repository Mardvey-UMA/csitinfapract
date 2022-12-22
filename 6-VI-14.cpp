#include <iostream>

using namespace std;

void delete_row(int **arr, int &i, int &n){
    delete [] arr[i];
    for (int ii = i; ii < n - 1; ++ii){
        arr[ii] = arr[ii + 1];
    }
    arr[n - 1] = NULL;
    --n;
    ++i;
}

void delete_column(int **arr, int &j, int &n, int &m){
    for (int jj = j; jj < m - 1; ++jj){
        for (int i = 0; i < n; ++i){
            arr[i][jj] = arr[i][jj + 1];
        }
    }
    --m;
    ++j;
}

int main(){
    int **matrix;
    int n, m;
    setlocale(LC_ALL, "Russian");
    cout << "Введите n m\n";
    cin >> n >> m;
    if (n != m){
        cout << "Извините, недопустимые значения, матрица должна быть квадратной";
        exit(0);
    }
    matrix = new int *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];
    
    cout << "Введите массив по строчкам\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    bool flag;
    for (int i = 0; i < n; i++){
        for (int f = 0; f < n; f++){
            flag = true;
            for (int k = 0; k < n; k++){
                //cout << i << " " << k << "   " << k << " " << f << endl;
                flag *= (matrix[i][k] == matrix[k][f]);
            }
            if (flag){
                delete_column(matrix, f, n, m);
                delete_row(matrix, i, n);
            }
            //cout << endl;
        }
        //cout << endl;
    }
    //////////////////
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
    cout << endl;
    }
    //input
    //3 3
    //1 2 3
    //2 1 4
    //3 8 8
    //output
    //1 4 
    //8 8
    //input
    //5 5
    //2 4 5 6 7
    //2 2 3 4 5
    //3 0 0 0 0
    //4 7 1 5 0
    //5 8 8 8 8
    //output
    //4 5 6 7 
    //0 0 0 0 
    //7 1 5 0 
    //8 8 8 8
    }