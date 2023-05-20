#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
list<int> lst;
vector<int> vec;
int n, m, k, tmp;
// A - делать с помощью list, так как вставка элементов
// в листе происходит за O(1)
cout << "Problem A\n";
n = 5;
cout << "Enter elements of list " << n << " number\n";
for (int i = 0; i < n; i++){
    cin >> tmp;
    lst.push_back(tmp);
}
m = tmp;
auto t = lst.begin();
for (auto it = lst.begin(); it != lst.end(); it++){
    if (*it < m){
        m = *it;
        t = it;
    }
}
lst.insert(t, 0);
lst.insert(++t, 0); // Используем префиксный итератор,
// так как нужно, чтобы в функцию вернуло новый
cout << "Result:\n";
for (auto x: lst)
    cout << x << " ";
cout << endl;
// Таким образом, временная оценка времени - O(n)
// Так как поиск минимального происходит за O(n) и ввод листа за O(n), а все 
// остальные действия за O(1)
cout << "Problem B\n";
// Здесь используем вектор, так как в векторе обращение 
// к элементу происходит за O(1)
cout << "Enter number of elements\n";
cin >> n;
cout << "Enter elements of vector " << n << " number\n";
bool flag = true;
for (int i = 0; i < n; i++){
    cin >> tmp;
    flag *= (tmp >= 0);
    vec.push_back(tmp);
}
if (n % 2 == 0){
    cout << "Error n must be odd number\n";
    exit(0);
}else if (flag){
    cout << "Sorry not impossible find maximum below zero\n";
    exit(0);
}
int mid = n / 2, mx = -100000;
for (int i = 0; i < n; i++)
    if (vec[i] < 0) mx = max(mx, vec[i]);
vec[mid] = mx;
cout << "Result\n";
for (auto x: vec)
    cout << x << " ";
// Таким образом, вся программа работает за O(n)
// Ввод массива - O(n), поиск максимального отрицательного
// за O(n), остальные действия за O(1)
system("pause");
// 2 -33 1 3 -4
}