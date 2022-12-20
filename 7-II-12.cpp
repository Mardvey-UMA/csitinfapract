#include <iostream>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    int N1, N2;
    string S1, S2, S3;
    cout << "Введите N1, N2\n";
    cin >> N1 >> N2;
    cout << "Введите S1 S2\n";
    getline(cin, S1, ' ');
    getline(cin, S2);
    S3 = S1.substr(0, N1 + 1) + S2.substr(S2.size() - N2, S2.size() - 1);
    cout << S3 << endl;
    //input
    //2 3
    //abcd abcdef
    //output
    //abdef
    //input
    //1 1
    //dada netnet
    //output
    //dt
    //input
    //4 5
    //ovsyaboba krkrankin
    //ovsyankin
}