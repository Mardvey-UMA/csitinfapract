#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool is_upper(char c){
    if (((int)c >= 53392 && (int)c <= 53423) || ((int)c >= 65 && (int)c <= 90))
        return true;
    return false;
}

string replace_propis(string s, int i, int flag){
    // flag = 1 // Встретил слово с большой
    // flag = 0 // Слово с маленькой
    if (i == s.size()){
        return s;
    }else{
        if (is_upper(s[i]) && flag == 0 && (s[i - 1] == ' ' || i == 0)){
            flag = 1;
            s[i] = '.';
        }else if (s[i] == ' '){
            flag = 0;
        }else if (flag == 1){
            s[i] = '.';
        }
        return replace_propis(s, i + 1, flag);
    }

}

int main(){
setlocale(LC_ALL, "Russian");
string s;
cout << "Введите строку\n";
getline(cin, s);
cout << replace_propis(s, 0, 0);
}
//Aboba Ahhhh afffggfdAfjdfkj fdjgfkjgl HHhfghfHHH
//..... ..... afffggfdAfjdfkj fdjgfkjgl ..........
//ZzZzZzZ 0001243FFFhh jjjjJJJK Koala Drink Kumis aga)))
//....... 0001243FFFhh jjjjJJJK ..... ..... ..... aga)))
//putau Botinok S koshachim Lotkom
//putau ....... . koshachim ......
//      A     f     g    G
//      .     f     g    .
