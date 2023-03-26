#include <iostream>

using namespace std;

template <typename T>
void f(T n) {
    T* a = new T[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete[]a;
}
int main() {
    int n; cin >> n;
    f(n);
    return 0;

}
