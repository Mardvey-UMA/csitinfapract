#include <iostream>
#include <cmath>
//16 12 10 16 6 12 9
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "‚¢¥¤¨â¥ ¯®àï¤ª®¢ë© ­®¬¥à ¤­ï ¬¥áïæ :\n";
    int n;
    cin >> n;
    if (abs(n) > 31 || n <= 0){
        cout << "¥â â ª®£® ¤­ï ¬¥áïæ \n";
    }else if (abs(31 - n) == 0){
        cout << "â® ª®­¥æ ¬¥áïæ ";
    }else{
        cout << "‚®â áâ®«ìª® ¤­¥© ¤® ª®­æ  ¬¥áïæ : " << abs(31 - n);
    }
//’¥áâë
 //10 ‚®â áâ®«ìª® ¤­¥© ¤® ª®­æ  ¬¥áïæ : 21
 //-1 ¥â â ª®£® ¤­ï ¬¥áïæ 
 //31 â® ª®­¥æ ¬¥áïæ 
}
