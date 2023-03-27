#include <iostream>

using namespace std;

void printPattern(int n, int size) {
    if (n == 0) {
        return;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < (n + size) - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    printPattern(n - 1, size + 1);
}

int main() {
    int n;
    cin >> n;
    printPattern(n, 2);
}
