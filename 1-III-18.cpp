   #include <iostream>
   using namespace std;  
   int main() {
         setlocale(LC_ALL, "Russian");
         double a, b, c, temp;
         cout << "Введите значения сторон треугольника:\n";
         cin >> a >> b >> c;
         if (a > b) { 
            temp = b;
            b = a;
            a = temp;
    
            if (b > c) {
                temp = c;
                c = b;
                b = temp;
    
                if (a > b) {
                    temp = b;
                    b = a;
                    a = temp;
                }
            }
        }
        else if (b > c) {
            temp = c;
            c = b;
            b = temp;
    
            if (a > b) {
                temp = b;
                b = a;
                a = temp;
    
            }
        }
cout << ((c*c == a*a + b*b) ? "Треугольник прямоугольный" : "Треугольник не прямоугольный");
        return 0;
    }

