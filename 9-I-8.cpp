#include <iostream>
#include "fstream"
using namespace std;

int main(){
    ifstream in ("input.txt");
    string s;
    while (in.peek() != EOF){
        getline(in, s);
        cout << s[0] << endl;
    }
}
//input.txt
// 32432
// 245235
// zzz
// 32143
// 12
// fdfdf
// 05
// 2004
// s
// 456
// 123
// 45346
// aaa
// bbb
// 0
//output
// 3
// 2
// z
// 3
// 1
// f
// 0
// 2
// s
// 4
// 1
// 4
// a
// b
// 0
