#include <iostream>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    string S, S0;
    char C;
    cout << "Введите символ C\n";
    cin >> C;
    cout << "Введите S S0\n";
    getline(cin, S, ' ');
    getline(cin, S0);
    for (int i = S.size() - 1; i >= 0; i--){
        if (S[i] == C)
            S.insert(i + 1, S0);
    }
    cout << S << endl;
    //input 
    //a
    //aadaadafafavvva Z
    //output
    //aZaZdaZaZdaZfaZfaZvvvaZ
    //input
    //b
    //barbosbarbos DD
    //output
    //bDDarbDDosbDDarbDDos
    //input
    //g
    //gugugskagugushonok karkar
    //output
    //gkarkarugkarkarugkarkarskagkarkarugkarkarushonok
}