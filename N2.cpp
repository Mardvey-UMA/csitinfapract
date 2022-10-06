#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	double p;
	cout << "Введите стороны треугольника a, b, c\n";
	cin >> a >> b >> c;
	p = (a + b + c) / 2;
	cout << fixed << setprecision(6);
	cout << "Площадь заданного треугольника: S = " << sqrt(p * (p - a) * (p - b) * (p - c));
	return 0;
}