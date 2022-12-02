#include <iostream>

using namespace std;
typedef long long li;

int main(){
    double x, s = 0, p_x;
    li k, f = 1;
    cin >> k >> x;
    p_x = x;
    for (li n = 1; n <=k; n++){
        f *= n;
        p_x*=x;
        p_x*=x;
        s += p_x * f;
    }
    cout << s;
}
