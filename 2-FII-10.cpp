#include <iostream>
using namespace std;
void f(int &x){
      if (x % 2 == 0)
          x/=2;
      else
          x = 0;
  }
  int main() {
      setlocale(LC_ALL, "Russian");
      cout << "Введите число:\n";
      int x;
      cin >> x;
      f(x);
      cout << "Результат работы: " << x;
  }
