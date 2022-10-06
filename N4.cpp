#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double x, f;
	cout << "Введите значение x\n";
	cin >> x;
	f = pow(cosh(x), -7) - (log10(2*x))/log10(7.0/8.0);
	cout << "Значение функции: ";
	cout << f;
	return 0;
}