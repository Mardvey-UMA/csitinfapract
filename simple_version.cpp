#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
//Глобальные переменные//
string black_pix = "\033[30;40m  \033[m";
string white_pix = "\033[37;47m  \033[m";
string red_pix = "\033[31;41m  \033[m";
string blue_pix = "\033[34;44m  \033[m";

string num_pix = "\033[32;42m  \033[m";
string letter_pix = "\033[33;43m  \033[m";
string empty_pix = "\033[36;46m  \033[m";

string alphavile = "*ABCDEFGH*";
string numbers = "*87654321*";
//////////////////////////////////////

void Sleep(int x){
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void setcp(char naprav, int pix){
    //    \033[#A передвинуть курсор вверх на # строк
    //    \033[#B передвинуть курсор вниз на # строк
    //    \033[#С передвинуть курсор вправо на # столбцов
    //    \033[#D передвинуть курсор влево на # столбцов
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

void out_put_pole(char **pole){
    system("clear");
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
    //cout << "##########";
}

void set_figure(char **pole, string start_pos, string fin_pos){
    
}

int main(){
system("clear");
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
//setcp('B',5);
//setcp('C',10);
//paint_number_block('1');
//paint_letter_block('A');
out_put_pole(pole);
Sleep(3000);
//set_figure(pole, 'N', 5, 4);
Sleep(500);
//set_figure(pole, 'R', 5, 4);
out_put_pole(pole);
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
