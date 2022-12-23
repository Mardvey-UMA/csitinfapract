#include <iostream>
#include "fstream"

using namespace std;
//члены данные
//члены функции
//вид продукции
//стоимость
//сорт
//количество
//увеличить на x% стоимость
ifstream in ("input.txt");
ofstream out ("output.txt");

struct product{
    string type, kind;
    int count, x;
    double cost;
    product(string type, double cost, string kind, int count);
    void increase_cost(int x);
    void out_data();
};
product::product(string type1, double cost1, string kind1, int count1){
    type = type1;
    cost = cost1;
    kind = kind1;
    count = count1;
}
void product::increase_cost(int x){
    cost+= (x/100.)*cost;
}
void product::out_data(){
    out << type << " " << cost << " " << kind << " " << count << endl;
}

int main(){

    string title;
    getline(in, title);
    out << title << endl;
    string type, kind, count1, cost1;
    double cost;
    int x = 50, count;
    while (in.peek() != EOF){
        getline(in, type, ' ');
        getline(in, cost1, ' ');
        getline(in, kind, ' ');
        getline(in, count1);
        cost = stod(cost1);
        count = stoi(count1);
        product *prod = new product(type, cost, kind, count);
        prod->increase_cost(x); // инфляция, хаха
        prod->out_data();
    }
    in.close();
    out.close();
}
//input.txt
// Вид Стоимость Сорт Количество
// макарошки 10 рожки 1000
// макарошки 23 спагетти 300
// макарошки 11 бантики 560
// доширак 5 говяжий 100
// доширак 6 куриный 300
// энергетик 59 драйвик 3000
// энергетик 49 пульсапик 4000
// сигареты 167 винстон(фиол.кнопка) 999
// сигареты 220 чампан(корич.) 1
// картошечка 15 мытая 345
// помидорчики 14 красные 334
// говядинка 500 мякушка 445
// говядинка 300 косточка 432
// свинина 232 ушки 3000
// сырок 40 дружба 4000
// сырок 15 янтарный 5000
// сырок 56 крутой 40
//output.txt
// Вид Стоимость Сорт Количество
// макарошки 20 рожки 1000
// макарошки 46 спагетти 300
// макарошки 22 бантики 560
// доширак 10 говяжий 100
// доширак 12 куриный 300
// энергетик 118 драйвик 3000
// энергетик 98 пульсапик 4000
// сигареты 334 винстон(фиол.кнопка) 999
// сигареты 440 чампан(корич.) 1
// картошечка 30 мытая 345
// помидорчики 28 красные 334
// говядинка 1000 мякушка 445
// говядинка 600 косточка 432
// свинина 464 ушки 3000
// сырок 80 дружба 4000
// сырок 30 янтарный 5000
// сырок 112 крутой 40
