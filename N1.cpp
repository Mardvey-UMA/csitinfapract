#include <iostream>
#include <cmath>
#include <iomanip>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
using namespace std;

int main() {
	double PI = 3.141592653589793;
	double PI2 = acos(-1.0);
	setlocale(LC_ALL, "Russian");
	double r;
	cout << fixed << setprecision(10);
	cout << "Введите значение радиуса окружности\n";
	cin >> r;
	cout << "Длина окружности: \n" << "PI(15) = " << 2 * PI * r << "\nPI(lib) = " << 2 * M_PI * r;
	cout << "\nPI(acos) = " << PI2 * 2 * r << endl;
	cout << "Площадь окружности: \n" << "PI(15) = " << r * PI * r << "\nPI(lib) = " << r * M_PI * r;
	cout << "\nPI(acos) = " << PI2 * r * r;
	return 0;
}