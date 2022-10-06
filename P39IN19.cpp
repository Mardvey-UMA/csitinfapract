#include <iostream>
#include <cmath>
#include <iomanip>
// page 37 N | *19
using namespace std;

double function(double b, double c, double a) {
	return ((sqrt(pow(b, 2) + 4 * a * c) + b) / 2 * a) - pow(a, 3) + pow(b, -2);
}
int main() {
	setlocale(LC_ALL, "Russian");
	double b, c, a;
	cout << "Здравствуйте, введите значения a, b, c\n";
	cin >> a >> b >> c;
	cout << "Значение функции: ";
	cout << fixed << setprecision(4) << function(b, c, a) << endl;
	// E(f): b^2 + 4ac > 0 => 4ac > -b^2; a!=0; b!=0;
	// a = 1000 b = 1000 c = 1000 f(a, b, c) == -998381966.0112
	// a = 0.0001 b = 0.0001 c = 0.0001 f(a, b, c) == 100000000.0000
	// a = 100 b = 100 c = 0 f(a, b, c) == -989999.9999
	return 0;
}