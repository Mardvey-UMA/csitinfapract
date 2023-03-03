#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream out ("output1.txt");

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "Введите n" << endl;
    int n, cnt = 1;
    string s, temp = "";
    cin >> n;
    if (n <= 0){
        cout << "Извините число должно быть натуральным" << endl;
        exit(0);
    }
    for (int d = 1; d <= n; d++)
        out << d * d << "\n";

    out.close();

    ifstream out ("output1.txt");

    while (out.peek() != EOF){
        getline(out, s);
        if (cnt % 2 != 0)
            cout << s << " ";
        cnt++;
    }
    
    out.close();

}

//10
//1 9 25 49 81
//11
//1 9 25 49 81 121
//-10
//Извините число должно быть натуральным
