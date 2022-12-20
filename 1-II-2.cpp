#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double p;
	cout << "Введите значение периметра треугольника:\n";
	cin >> p;
	cout << "Значение площади треугольника: ";
	cout << fixed << setprecision(3) << (sqrt(3) * pow((p / 3), 2)) / 4 << endl;
	// 1 S = 0.048
	// 3 S = 0.433
	// 0.3 S = 0.004
	// 999 S = 48016.346
	// 3333 S = 534476.671
	return 0;
}