#include <iostream>
#include "fstream"
#include <cmath>

using namespace std;

struct point
{
    int x, y;
    point(int a, int b);
};
point::point(int a, int b){
    x = a;
    y = b;
}

double get_rast(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main(){
    string sx, sy;
    int x, y, cnt = 0;
    point *points[100];
    point *ans[3];
    ifstream in ("input1.txt");
    while (in.peek() != EOF){
        getline(in, sx,' ');
        getline(in, sy);
        x = stoi(sx);
        y = stoi(sy);
        points[cnt] = new point(x, y);
        cnt++;
    }
    double max_per = -1;
    double curr_p = -2;
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
            for (int t = 0; t < cnt; t++){
                if (i != j && i != t && j != t){
                    int x1 = points[i] -> x;
                    int y1 = points[i] -> y;
                    int x2 = points[j] -> x;
                    int y2 = points[j] -> y;
                    int x3 = points[t] -> x;
                    int y3 = points[t] -> y;
                    double A = get_rast(x1,y1,x2,y2);
                    double B = get_rast(x2,y2,x3,y3);
                    double C = get_rast(x3,y3,x1,y1);
                    if ( (A + B) > C && (A + C) > B && (B + C) > A){
                        curr_p = A + B + C;
                    }
                    if (curr_p > max_per){
                        max_per = curr_p;
                        ans[0] = points[i];
                        ans[1] = points[j];
                        ans[2] = points[t];
                    }
                }
            }
    if (max_per == -1){
        cout << "Треугольники не найдены\n";
        exit(0);
    }
    cout << "Максимальный периметр: " << max_per << endl;
    for (int i = 0; i < 3; i++){
        cout << "Точка " << i + 1 << endl;
        cout << "( " << ans[i] -> x << " , " << ans[i] -> y << " )" << endl;
    }
    //input.txt
//1 1
// 2 3
// 4 5
// 1 3
// 6 6
// 7 8
// 4 5
// -100 100
//output
// Максимальный периметр: 291.761
// Точка 1
// ( 1 , 1 )
// Точка 2
// ( 7 , 8 )
// Точка 3
// ( -100 , 100 )
//input.txt
//1 1
//1 1
//1 1
//1 1
//1 1
//1 1
//1 1
//1 1
//1 1
//1 1
//output
//Треугольники не найдены
}