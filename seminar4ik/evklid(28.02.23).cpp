#include <iostream>

using namespace std;

int nod(int a, int b) {
	if (a == 0 || b == 0)
		return a + b;
	else
		if (a > b)
			return nod(a % b, b);
		else
			return nod(a, b % a);	
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << "НОД(" << a << "," << b << ") = " << nod(a, b);
}
