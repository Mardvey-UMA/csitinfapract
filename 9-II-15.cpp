#include <iostream>
#include <algorithm>
#include "fstream"

using namespace std;

int main(){
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    string s, s1;
    int x, x1;
    while (in.peek() != EOF){
        getline(in, s);
        getline(in, s1);
        x = stoi(s);
        x1 = stoi(s1);
        out << min(x, x1) << endl;
    }
}
//input.txt
// 12
// 13
// 14
// 225
// 1243
// 6465
// -100
// 0
// 12
// 666
//output.txt
// 12
// 14
// 1243
// -100
// 12
