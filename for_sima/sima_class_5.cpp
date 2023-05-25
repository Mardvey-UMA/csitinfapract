#include <iostream>
#include <string>

using namespace std;

class Complex{
private:
    double realPart;
    double imaginaryPart;
public:
    void setReal(double realPart){
        this -> realPart = realPart;
    }
    void setImaginary(double imaginaryPart){
        this -> imaginaryPart = imaginaryPart;
    }
    double getRealpart(){
        return realPart;
    }
    double getImaginary(){
        return imaginaryPart;
    }
    void print(){ // Вывод числа комплексного
        cout << realPart << " ";
        if (imaginaryPart < 0){
            cout << "- " << (-1)*imaginaryPart << "i" << endl;
        }else if (imaginaryPart > 0){
            cout << "+ " << imaginaryPart << "i" << endl;
        }
    }
    void print_sopryag(){ // Вывод сопряженного комплексного
        cout << realPart << " ";
        if (imaginaryPart > 0){
            cout << "- " << imaginaryPart << "i" << endl;
        }else if (imaginaryPart < 0){
            cout << "+ " << (-1)*imaginaryPart << "i" << endl;
        }
    }
    bool compare_numbers(const Complex &other){ // Сравнение с другим числом, если они равны - возращаем тру, иначе 
    //возвращаем фалсе (комплексные числа нельзя сранивать вообще они либо равны либо не равны)
        if (this->realPart == other.realPart && this->imaginaryPart == other.imaginaryPart){
            return true;
        }
        return false;
    }
    // Перегрузка оператора сложения
    Complex operator+(Complex other){
        Complex result;
        result.setReal(this->getRealpart() + other.getRealpart());
        result.setImaginary(this->getImaginary() + other.getImaginary());
        return result;
    }
    // Перегрузка оператора вычитания
    Complex operator-(const Complex &other) const{
        Complex result;
        result.setReal(this->realPart - other.realPart);
        result.setImaginary(this->imaginaryPart - other.imaginaryPart);
        return result;
    }
    // Перегрузка оператора умножения
    Complex operator*(const Complex &other) const{
        Complex result;
        result.setReal(this->realPart * other.realPart - this->imaginaryPart * other.imaginaryPart);
        result.setImaginary(this->realPart * other.imaginaryPart + this->imaginaryPart * other.realPart);
        return result;
    }
    //Перегрузка оператора деления
    Complex operator/(const Complex &other) const{
        Complex result;
        double denominator = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        result.setReal((this->realPart * other.realPart + this->imaginaryPart * other.imaginaryPart) / denominator);
        result.setImaginary((this->imaginaryPart * other.realPart - this->realPart * other.imaginaryPart) / denominator);
        return result;
    }
};
int main(){
Complex c1, c2;
c1.setReal(1);
c1.setImaginary(-3);
c2.setReal(5);
c2.setImaginary(8);
cout << "Printing complex numbers\n";
c1.print();
c2.print();
cout << "Printing sopryag numbers\n";
c1.print_sopryag();
c2.print_sopryag();
Complex c3 = c1 * c2;
Complex c4 = c1 / c2;
Complex c5 = c1 - c2;
Complex c6 = c1 + c2;
cout << "Mulpitpy\n";
c3.print();
cout << "Delenie\n";
c4.print();
cout << "Minus\n";
c5.print();
cout << "Plus\n";
c6.print();
system("pause");
// Собственно создаешь два комплексных числа c1 c2
// Потом их выводишь, выводишь их сопряженные
// Потом создаешь c3, c4, c5, c6 туда сохраняешь результаты
// Сложения, вычитания и т.п. то есть что ты перегружал
// Я проверил кальклуятором там все работает верно
}