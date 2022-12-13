#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <chrono>
#include <thread>
#include <map>
#include <vector>

using namespace std;
//Глобальные переменные//
string black_pix = "\033[30;40m  \033[m";
string white_pix = "\033[37;47m  \033[m";
string red_pix = "\033[31;41m  \033[m";
string blue_pix = "\033[34;44m  \033[m";

string num_pix = "\033[33;43m  \033[m";
string letter_pix = "\033[33;43m  \033[m";
string empty_pix = "\033[33;43m  \033[m";

string alphavile = "*ABCDEFGH*";
string numbers = "*87654321*";
//////////////////////////////////////

void sleep_l(unsigned int milliseconds_){
    this_thread::sleep_for(chrono::milliseconds(milliseconds_));
}
//A передвинуть курсор вверх на # строк
//B передвинуть курсор вниз на # строк
//С передвинуть курсор вправо на # столбцов
//D передвинуть курсор влево на # столбцов
void setcp(char naprav, int pix){
    string c = "\033[" + to_string(pix) + naprav;
    cout << c;
}

void paint_white(char color){
    cout << white_pix << white_pix << white_pix;
    setcp('B',1);
    setcp('D',6);
    if (color == 'N')
        cout << white_pix << white_pix << white_pix;
    else if (color == 'R')
        cout << white_pix << red_pix << white_pix;
    else if (color == 'B')
        cout << white_pix << blue_pix << white_pix;
    setcp('B',1);
    setcp('D',6);
    cout << white_pix << white_pix << white_pix;
    setcp('A',2);
}

void paint_black(char color){
    cout << black_pix << black_pix << black_pix;
    setcp('B',1);
    setcp('D',6);
    if (color == 'N')
        cout << black_pix << black_pix << black_pix;
    else if (color == 'R')
        cout << black_pix << red_pix << black_pix;
    else if (color == 'B')
        cout << black_pix << blue_pix << black_pix;
    setcp('B',1);
    setcp('D',6);
    cout << black_pix << black_pix << black_pix;
    setcp('A',2);
}

void paint_number_block(char number){
    cout << num_pix << num_pix << num_pix;
    setcp('B',1);
    setcp('D',6);
    cout << num_pix << "\033[1;37m" << number << "\033[m" << " " << num_pix;
    setcp('B',1);
    setcp('D',6);
    cout << num_pix << num_pix << num_pix;
    setcp('A',2);
}

void paint_letter_block(char letter){
    cout << letter_pix << letter_pix << letter_pix;
    setcp('B',1);
    setcp('D',6);
    cout << letter_pix << letter << ' ' << letter_pix;
    setcp('B',1);
    setcp('D',6);
    cout << letter_pix << letter_pix << letter_pix;
    setcp('A',2);
}
void paint_empty_block(){
    cout << empty_pix << empty_pix << empty_pix;
    setcp('B',1);
    setcp('D',6);
    cout << empty_pix << empty_pix << empty_pix;
    setcp('B',1);
    setcp('D',6);
    cout << empty_pix << empty_pix << empty_pix;
    setcp('A',2);
}

void out_put_pole(char **pole, map <string, int> &score){
    system("clear");
    // score - словарь счета игроков
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if ((j == 0 || j == 9) && (i != 0 && i != 9)){
                paint_number_block(pole[i][j]);
            }else if ((i == 0 || i == 9) && (j != 0 && j != 9)){
                paint_letter_block(pole[i][j]);
            }else if (pole[i][j] == '*'){
                paint_empty_block();
            }else if ((i + j) % 2 == 0){
                paint_white(pole[i][j]);
            }else{
                paint_black(pole[i][j]);
            }                
        }
        setcp('B',3);
        setcp('D',60);
    }
    setcp('A',48);
    ////////////////
    setcp('C',70);  
    setcp('B',5);
    cout << "СЧЕТ: \033[1;31mКРАСНЫЕ\033 \033[1;34m СИНИЕ\033[0m";
    setcp('B',1);
    setcp('D',19);
    cout << "         \033[1;41m"<< score["red"] << "\033[0m";
    cout << "      \033[1;44m" << score["blue"] << "\033[0m\n";
    setcp('A',8);
    //cout << "#";
    ////////////////
}

void make_hod(char **pole, char **pole2, int step){
    // step == 1 - Голубые
    // step == 0 - Красные
    vector <char> pos;
    map <char, int> coords;
    coords['A'] = 1;
    coords['B'] = 2;
    coords['C'] = 3;
    coords['D'] = 4;
    coords['E'] = 5;
    coords['F'] = 6;
    coords['G'] = 7;
    coords['H'] = 8;
    coords['a'] = 1;
    coords['b'] = 2;
    coords['c'] = 3;
    coords['d'] = 4;
    coords['e'] = 5;
    coords['f'] = 6;
    coords['g'] = 7;
    coords['h'] = 8;
    coords['1'] = 1;
    coords['2'] = 2;
    coords['3'] = 3;
    coords['4'] = 4;
    coords['5'] = 5;
    coords['6'] = 6;
    coords['7'] = 7;
    coords['8'] = 8;
    string s;
    getline(cin, s);
    for (auto x: s){
        if (x != ' '){
            pos.push_back(x);
        }
    }
    if (step == 1 && pole[coords[pos[0]]][coords[pos[1]]] == 'B' && pole[coords[pos[0]]][coords[pos[1]]] == 'N'){
        pole[coords[pos[0]]][coords[pos[1]]] == 'N';
        pole[coords[pos[0]]][coords[pos[1]]] == 'B';
        pole2[coords[pos[0]]][coords[pos[1]]] == 'N';
        pole2[coords[pos[0]]][coords[pos[1]]] == 'B';
    }else if (step == 0 && pole[coords[pos[0]]][coords[pos[1]]] == 'R' && pole[coords[pos[0]]][coords[pos[1]]] == 'N'){
        pole[coords[pos[0]]][coords[pos[1]]] == 'N';
        pole[coords[pos[0]]][coords[pos[1]]] == 'R';  
        pole2[coords[pos[0]]][coords[pos[1]]] == 'N';
        pole2[coords[pos[0]]][coords[pos[1]]] == 'B';      
    }else{
        cout << "Извините вы не можете сделать этот ход";
    }
}

int main(){
system("clear");
//Поле со стороны синих
char **pole_b = new char*[10];
for (int k = 0; k < 10; k++)
    pole_b[k] = new char [10];
//Поле со стороны красных
char **pole_r = new char*[10];
for (int k = 0; k < 10; k++)
    pole_r[k] = new char [10];
//////////////////////////////

/// Инициализация игрового поля (синие)///
    for (int j = 0; j <= 9; j++){
        pole_b[0][j] = alphavile[j];
        pole_b[9][j] = alphavile[j];
    }

    for (int i = 0; i <= 9; i++){
        pole_b[i][0] = numbers[i];
        pole_b[i][9] = numbers[i];
    }
 
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++){
            if (i >= 1 && i <= 3 && (i + j) % 2 != 0)
                pole_b[i][j] = 'R';
            else if (i >= 6 && i <= 8 && (i + j) % 2 != 0)
                pole_b[i][j] = 'B';
            else
                pole_b[i][j] = 'N';
        }
    }
///////////////////////////////////////
/// Инициализация игрового поля (синие)///
    for (int j = 0; j <= 9; j++){
        pole_r[0][j] = alphavile[9 - j];
        pole_r[9][j] = alphavile[9 - j];
    }

    for (int i = 0; i <= 9; i++){
        pole_r[i][0] = numbers[9 - i];
        pole_r[i][9] = numbers[9 - i];
    }
 
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++){
            if (i >= 1 && i <= 3 && (i + j) % 2 != 0)
                pole_r[i][j] = 'B';
            else if (i >= 6 && i <= 8 && (i + j) % 2 != 0)
                pole_r[i][j] = 'R';
            else
                pole_r[i][j] = 'N';
        }
    }
///////////////////////////////////////
int flag = 1;
cout << "Добро пожаловать в шашки\nПервыми ходят - синие, чтобы сделать ход напишите координаты в виде *буква* *цифра* - начало, далее *буква* *цифра* - конец\n";
cout << "Введите 1 для начала игры\n";
//cin >> flag;
map <string, int> score;
score["blue"] = 0;
score["red"] = 0;
int step = 1;
if (flag == 1){
    out_put_pole(pole_b, score);
    while (true){
        cout << "Введите координаты хода";
        if (step == 1){
            cout << " синие ходят";
            make_hod(pole_b, pole_r, step);
        }else{
            cout << " красные ходят";
            make_hod(pole_r, pole_b, step);
        }
        cout << "\n";
        
        // if (step == 1){
        //     out_put_pole(pole_b, score);
        //     make_hod(pole_b, pole_r, 1);
        //     sleep_l(5000);
        //     step = 0;
        // }else{
        //     out_put_pole(pole_r, score);
        //     make_hod(pole_r, pole_b, 0);
        //     sleep_l(5000);
        //     step = 1;
        // }
    }
    
}

cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
