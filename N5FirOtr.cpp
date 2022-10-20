#include <iostream>

using namespace std;

int main(){
    int x, n = 1;
    while (true){
        cin >> x;
        n++;
        if (x < 0) {
            cout << n - 1;
            break;
        }
    }
}