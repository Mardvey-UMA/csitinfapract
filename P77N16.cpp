#include <iostream>
//12 9
using namespace std;

int main() {
    for (int i = 8; i > 4; i--){

        for (int j = 1; j <= (8 - i) + 1; j++){
            cout << i << "  ";
        }
        cout << endl;

        for (int j = 1; j <= (8 - i) + 1; j++){
            cout << i - 1 << "  ";
        }
        cout << endl;
    }

}
