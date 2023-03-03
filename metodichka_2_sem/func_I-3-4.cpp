#include <iostream>

using namespace std;

int sum_of_divisors(int n, int d){
    if (d == n)
        return d;
    else
        if (n % d == 0)
            return d + sum_of_divisors(n, d + 1);
        else
            return sum_of_divisors(n, d + 1);
}

int found_sum_div_equal(int n, int A){
    if (n == 0)
        return -1;
    else
        if (sum_of_divisors(n, 1) == sum_of_divisors(A, 1))
            return n;
        else
            return found_sum_div_equal(n - 1, A);
}


int main(){
    setlocale(LC_ALL, "Russian");
    cout << "Введите A" << endl;
    int A, res;
    cin >> A;
    res = found_sum_div_equal(A - 1, A);
    if (res == -1)
        cout << "Нет такого числа:(" << endl;
    else
        cout << res << endl;
}
//15 14
//1 Нет такого числа:(
//17 10
//244 208
