#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    setlocale(LC_ALL, "Russian");
    getline(cin, s);
    for (int i = 0; i < s.size() - 2; i++){
        if (s[i] == ' ' && s[i + 2] == ' '){
            s.erase(i, 3);
        }
    }
    cout << endl;
    cout << s << endl << endl << endl;
}