#include <iostream>
#include "fstream"

using namespace std;
//члены данные
//члены функции
//название игрушки
//стоимость
//цензор
//уменьшить на x% стоимость
ifstream in ("input1.txt");
ofstream out ("output1.txt");

struct toy{
    string name;
    int x, cenz;
    double cost;
    toy(string name, double cost, int cenz);
    void degrade_cost(int x);
    void out_data();
};
toy::toy(string name1, double cost1, int cenz1){
    name = name1;
    cost = cost1;
    cenz = cenz1;
}
void toy::degrade_cost(int x){
    cost = ((100 - x)/100.)*cost;
}
void toy::out_data(){
    out << name << " " << cost << " " << cenz << endl;
}

int main(){

    string title;
    getline(in, title);
    out << title << endl;
    string name, cenz1, cost1;
    double cost;
    int cenz;
    int x = 10;
    while (in.peek() != EOF){
        getline(in, name, ' ');
        getline(in, cost1, ' ');
        getline(in, cenz1);
        cost = stod(cost1);     
        cenz = stoi(cenz1);
        toy *t = new toy(name, cost, cenz);
        t->degrade_cost(x); // инфляция, хаха
        t->out_data();
    }
}
