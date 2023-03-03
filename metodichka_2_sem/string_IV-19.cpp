#include <iostream>
#include <string>

using namespace std;

bool is_digit(char c){
    if (((int)c >= (int)('0') && (int)c <= (int)('9')))
        return true;
    return false;
}

bool is_sybmol(char c){
    if (c == 'e' || c == '.' || c == ',' || c == '-')
        return true;
    return false; 
}

int main(){
    string s;
    bool flag = true;
    getline(cin, s);

    if (s[0] == '-')
        s[0] = '1';
    
    int cnt_p = 0, cnt_e = 0, e_pos, m_pos;

    e_pos = s.find('e');
    m_pos = s.find('-');

    if (e_pos == -1 && m_pos != -1)
        flag = false;
    else if (e_pos != -1 && m_pos != -1){
        if (not(m_pos - e_pos == 1)){
            flag = false;
        }
    }
    if (e_pos == -1){
        e_pos = s.size() + 1;
    }
    if (flag){
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ',' || s[i] == '.'){
            cnt_p++;
            if (e_pos < i){
                flag = false;
                break;
            }
            }
        else if (s[i] == 'e'){
            cnt_e++;
            e_pos = i;
        }
        if (cnt_e > 1 || cnt_p > 1){
            flag = false;
            break;
            }
    }
    }
    bool flag2 = true;          
    if (flag){
        for (int i = 0; i < s.size(); i++)
            flag2 *= (is_digit(s[i]) || is_sybmol(s[i]));
    }
    if ((flag && flag2) == true)
        cout << "Правильное десятичное число" << endl;
    else
        cout << "Неправильное десятичное число" << endl;
}

//test
//input
//1e-100 Правильное десятичное число
//0. Правильное десятичное число
//-10e-10 Правильное десятичное число
//--1000e-1000 Неправильное десятичное число
// 5. Правильное десятичное число
// 103e45 Правильное десятичное число
// aaae-gggg0 Неправильное десятичное число
