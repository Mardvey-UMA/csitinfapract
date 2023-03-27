#include <iostream>

using namespace std;

template<typename Type>
Type* createArray(int n) {
    Type* arr = new Type[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return arr;
}

int main() {
    int* arr = createArray<int>(10);
    delete[] arr;
}
