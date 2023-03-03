#include <iostream>
#include <cmath>

using namespace std;
double N;
double kor(double n){
    if (n == N){
        return sqrt(N);
    }else{
        return sqrt(n + kor(n + 1));
    }
}
int main(){
double c;
setlocale(LC_ALL, "Russian");
cout << "Введите N" << endl;
cin >> c;
N = c;
cout << "Значение функции:\n";
//cout << kor2(1) << endl;
cout << N / kor(1) << endl;
}

// N = 10 5.688
// N = 9 5.119
// N = 8 4.550