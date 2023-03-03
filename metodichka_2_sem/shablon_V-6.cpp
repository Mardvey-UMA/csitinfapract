#include <iostream>

using namespace std;

template <class Type>
double mean_val(Type** arr, int n, int m){
    double ans = 0;
    int otr_cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if (arr[i][j] < 0){
            ans += arr[i][j];
            otr_cnt++;
            }
        }
    if (otr_cnt != 0)
        return ans / otr_cnt;
    else
        return 0.;
}
template <class Type>
void input_array(Type** arr, int n, int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
}

template <class Type>
void print_array(Type** arr, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
        }
}
int main(){
setlocale(LC_ALL, "Russian");
cout << "Введите размерность массива\n";
int n, m;
cin >> n >> m;
// Создаем интовский двумерный массив
int** int_arr;
int_arr = new int*[n];
for (int i = 0; i < m; i++)
    int_arr[i] = new int[m];
///////////////////////////////////
// Создаем вещественный двумерный массив
double** double_arr;
double_arr = new double*[n];
for (int i = 0; i < m; i++)
    double_arr[i] = new double[m];
///////////////////////////////////
cout << "Введите целочисленный массив" << n << " на " << m << "\n";
input_array(int_arr, n, m);
cout << "Ваш массив:\n";
print_array(int_arr, n, m);
cout << "Введите вещественный массив " << n << " на " << m << "\n";
input_array(double_arr, n, m);
cout << "Ваш массив:\n";
print_array(double_arr, n, m);
cout << "Среднее значение первого массива = " << mean_val(int_arr, n, m) << endl;
cout << "Среднее значение второго массива = " << mean_val(double_arr, n, m) << endl;
}
// Введите целочисленный массив 3 x 3
// 1 2 3
// 4 5 6
// 7 8 9
// Ваш массив:
// 1 2 3 
// 4 5 6 
// 7 8 9 
// Введите вещественный массив 3 x 3
// 1.5 6.8 -1.
// 5.7 3.444 6.08
// -10.5 3.1234 5.888
// Ваш массив:
// 1.5 6.8 -1 
// 5.7 3.444 6.08 
// -10.5 3.1234 5.888 
// Среднее значение первого массива = 5
// Среднее значение второго массива = 2.33727
