#include <iostream>
//10 16 6 12 9
using namespace std;

int main() {
    for (int i = 1; i < 6; i++){
        for (int j = i; j > 0; j--){
            cout << j << "  ";
        }
        cout << endl;
    }
    // Вывод
    //1
    //2  1
    //3  2  1
    //4  3  2  1
    //5  4  3  2  1
}
