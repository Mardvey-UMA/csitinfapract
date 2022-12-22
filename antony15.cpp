#include <iostream>

using namespace std;

int main(){
    int **matrix;
    int n, m;
    setlocale(LC_ALL, "Russian");
    cout << "Введите n m\n";
    cin >> n >> m;
    cout << "Введите k1, k2\n";
    int k1, k2;
    cin >> k1 >> k2;
    int *ans = new int[m];
    for (int i = 0; i < m; i++)
        ans[i] = 1;

    matrix = new int *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];
    
    cout << "Введите массив по строчкам\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    for (int j = 0; j < m; j++){
        for (int i = k1; i <= k2; i++){
            ans[j]*=matrix[i][j];
        }
    }



    for (int i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
}