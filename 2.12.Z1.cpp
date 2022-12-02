#include <iostream>

using namespace std;

int main(){
   int n;
   cin >> n;
   double b1 = 1, b2 = 2, b_n;
   if (n == 1)
       cout << "b1 - " << b1;
   if (n == 2)
       cout << "b1 - " << b1 << " b2 - " << b2;
   else{
       int nn = n;
       n = 3;
       cout << "b1 - " << b1 << " b2 - " << b2 << " ";
       for (int h = n; h <= nn; h++){
           b_n = b2 / (double)(b1 + 1);
           cout << "b" << h << " - " << b_n << " ";
           b1 = b2;
           b2 = b_n;
       }
   }
}
