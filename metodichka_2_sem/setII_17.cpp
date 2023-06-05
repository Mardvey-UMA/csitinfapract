#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<char> count_prep(string s){
    set <char> sym1;
    set <char> sym2;
    for (auto c: s){
        if(sym1.find(c) == sym1.end() && ispunct(c))
            sym1.insert(c);
        else if (ispunct(c)){
            sym2.insert(c);
        }
    }
    return sym2;
}


int main(){
    // Даны N строк, состоящих из латинских букв, цифр, знаков препинания и пробельных символов.
    // Для каждой строки вывести знаки препинания, которые встречаются не менее двух раз.
    vector <string> text;
    int u = 4; // кол-во строк
    string s;
    while (u--){
        getline(cin, s);
        text.push_back(s);
    }
    for (auto d: text){ 
        set<char> tmp = count_prep(d);
        for (auto g: tmp){
            cout << g << " ";
        }
        cout << endl;
    }
    /*
Aboba, Aboba, Aboba, Aboba!!
Aboba AbobaAboba...
AbobaAboba Aboba Aboba))
.....Aboba,...Aboba....Aboba,,,,.!!!!?
    */
   cout << endl;
   system("pause");
}