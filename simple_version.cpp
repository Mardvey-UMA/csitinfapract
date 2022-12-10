#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>

using namespace std;
//Глобальные переменные//
string black_pix = "\033[30;40m  \033[m";
string white_pix = "\033[37;47m  \033[m";
string red_pix = "\033[31;41m  \033[m";
string blue_pix = "\033[34;44m  \033[m";
string alphavile = "*abcdefgh*";
string numbers = "*87654321*";
//////////////////////////////////////

    //    \033[#A передвинуть курсор вверх на # строк
    //    \033[#B передвинуть курсор вниз на # строк
    //    \033[#С передвинуть курсор вправо на # столбцов
    //    \033[#D передвинуть курсор влево на # столбцов

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

void out_put_pole(char **pole){
    system("clear");
    for (int i = 1; i < 9; i++){
        for (int j = 1; j < 9; j++){
            if ((i + j) % 2 == 0)
                paint_white(pole[i][j]);
            else
                paint_black(pole[i][j]);
        }
        cout << "\n\n\n";

    }
}

void set_figure(char **pole, char color, int x, int y){
    if (x > 8 || y > 8)
        cout << "error";
    pole[x][y] = color;
}

int main(){
char **pole = new char*[10];
for (int k = 0; k < 10; k++)
    pole[k] = new char [10];
/// Инициализация игрового поля ///
    for (int j = 0; j <= 9; j++){
        pole[0][j] = alphavile[j];
        pole[9][j] = alphavile[j];
    }

    for (int i = 0; i <= 9; i++){
        pole[i][0] = numbers[i];
        pole[i][9] = numbers[i];
    }
 
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++){
            if (i >= 1 && i <= 3 && (i + j) % 2 != 0)
                pole[i][j] = 'R';
            else if (i >= 6 && i <= 8 && (i + j) % 2 != 0)
                pole[i][j] = 'B';
            else
                pole[i][j] = 'N';
        }
    }
///////////////////////////////////////

out_put_pole(pole);
cout << "\n\n\n\n\n\n\n";
}