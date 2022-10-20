#include <iostream>

using namespace std;

int main(){
    int x, s, p;
    cin >> x;
    s = x/10 + x%10;
    p = (x/10) * (x%10);
    if (s > p){
        swap(s, p);
    }
    for (int n = s; n <= p; n++){
        cout << n << " ";
    }
}