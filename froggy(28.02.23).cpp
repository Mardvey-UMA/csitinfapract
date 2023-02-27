#include <iostream>
using namespace std;

int froga(int n, int x) {
    if (n > x)
        return 0;
    else if (n == x)
        return 1;
    else if (n < x)
        return froga(n + 3, x) + froga(n + 5, x);
}

int main() {
    int x, n = 0;
    cin >> x;
    cout << froga(n, x);
}
