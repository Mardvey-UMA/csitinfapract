#include <iostream>
#include <string>

using namespace std;

bool is_digit(char c){
    if (((int)c >= (int)('0') && (int)c <= (int)('9')))
        return true;
    return false;
}

bool is_sybmol(char c){
    if (c == 'e' || c == '.' || c == ',' || c == '-' || c == '+')
        return true;
    return false; 
}

bool is_float(string s){
    bool flag = true;
    if ((s.size() == 1 && is_sybmol(s[0]) == true))
        if (is_digit(s[0]) == false)
            flag = false;

    if ((s.size() == 2 && is_sybmol(s[0]) == true && is_sybmol(s[1]) == true))
        if (is_digit(s[0]) == false || is_digit(s[1]) == false)
            flag = false;

    if (s[0] == '-' || s[0] == '+')
        s[0] = '1';
    
    int cnt_p = 0, cnt_e = 0, e_pos, m_pos, p_pos;

    e_pos = s.find('e');
    m_pos = s.find('-');
    p_pos = s.find('+');

    if ((e_pos == -1 && m_pos != -1) || (e_pos == -1 && p_pos != -1))
        flag = false;
    else if ((e_pos != -1 && m_pos != -1)){
        if ((not(m_pos - e_pos == 1))){
            flag = false;
        }
    }else if ((e_pos != -1 && m_pos != -1)){
        if ((not(p_pos - e_pos == 1))){
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
        return true;
    else
        return false;
}

int main(){
    string s;
    getline(cin, s);
    if (is_float(s))
        cout << "Правильное десятичное число" << endl;
    else
        cout << "Неправильное десятичное число" << endl;
}
