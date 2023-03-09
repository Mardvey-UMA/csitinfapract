#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool is_upper(char c){
    if (((int)c >= 53392 && (int)c <= 53423) || ((int)c >= 65 && (int)c <= 90))
        return true;
    return false;
}

void split(string* split_string, string s, int& n){
    string temp =  "";
    s+=' ';
    for(int k = 0; k < s.size(); k++){
        if (s[k] != ' '){
            temp += s[k];
        }else{
            split_string[n] = temp;
            temp = "";
            n++;
        }
    }
}



void replace_propis(string* s, int i, int n){
    if (n == i){
        cout << "";
    }else{
        string h = s[i];
        if (is_upper(h[0])){
            s[i] = "...";
        }
        replace_propis(s, i + 1, n);
    }


}

int main(){
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Введите строку\n";
    getline(cin, s);
    string* split_string = new string[s.size()];
    int n = 0;
    split(split_string, s, n);
    replace_propis(split_string, 0, n);
    for (int i = 0; i < n; i++){
        cout << split_string[i] << " ";
    }
}
//Aboba Ahhhh afffggfdAfjdfkj fdjgfkjgl HHhfghfHHH
//..... ..... afffggfdAfjdfkj fdjgfkjgl ..........
//ZzZzZzZ 0001243FFFhh jjjjJJJK Koala Drink Kumis aga)))
//....... 0001243FFFhh jjjjJJJK ..... ..... ..... aga)))
//putau Botinok S koshachim Lotkom
//putau ....... . koshachim ......
//      A     f     g    G
//      .     f     g    .
