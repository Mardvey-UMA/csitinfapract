#include <iostream>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    string S, S0;
    cout << "Введите предложение:\n";
    getline(cin, S);
    cout << "Введите слово для поиска\n";
    getline(cin, S0);
    int i = 0;
    while (S.find(S0, i) != string::npos){
        auto g = S.find(S0, i);
        S.insert(g + S0.size(), "!");
        i = g + S0.size();
    }
    cout << endl << S;
    //input
    //aaaaaaaaaaaaaaaaaaaaas
    //a
    //output
    //a!a!a!a!a!a!a!a!a!a!a!a!a!a!a!a!a!a!a!a!a!s
    //input
    //aaasaaasaaassssaaasasasassssaaa
    //aaa!saaa!saaa!ssssaaa!sasasassssaaa!
    
}