#include <iostream>

using namespace std;

bool fastcheck_row(int *row, int &m){
    bool flag = true;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            flag*=(row[i] == row[j] && row[i] == m && row[j] == m);
    return flag;
}

bool fastcheck_column(int **arr, int &j, int &n, int &x){
    bool flag = true;
    for (int i = 0; i < n; i++)
        for (int g = 0; g < n; g++)
            flag*=(arr[i][j] == arr[g][j] && arr[i][j] == x && arr[g][j] == x);
    return flag;
}

void delete_row(int **arr, int &i, int &n, int &m){
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
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i] = new int[m];
    
    cout << "Введите массив по строчкам\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    
    int temp1, temp2;
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; i++){
        flag1 = fastcheck_row(matrix[i], matrix[i][0]);
        if (flag1){
            temp1 = matrix[i][0];
            for (int j = 0; j < m; j++){
                flag2 = fastcheck_column(matrix, j, n, temp1);
                if (flag2){
                    delete_column(matrix, j, n, m);
                    delete_row(matrix, i, n, m);
                }
            }
        }
        }
    cout << endl;
    //////////////////
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
    cout << endl;
    }
    //input
    //3 4
    //1 1 1 1
    //2 1 2 2
    //2 1 2 2
    //output
    //2 2 2 
    //2 2 2
    //input
    //5 6
    //1 1 1 1 1 1
    //1 7 8 1 6 5
    //1 1 1 1 1 1
    //1 4 3 1 2 1
    //1 7 6 1 5 7
    //output
    //7 8 6 5 
    //4 3 2 1 
    //7 6 5 7 
    }