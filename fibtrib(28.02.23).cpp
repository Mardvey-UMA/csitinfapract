#include <iostream>
#include <map>

using namespace std;

map <int, int> fib_cash;
map <int, int> trib_cash;

int tripponach(int n) {
	if (n == 1 || n == 2 || n == 3)
		return 1;
	else {
		if (trib_cash.count(n - 1) == 0)
			trib_cash[n - 1] = tripponach(n - 1);
		if (trib_cash.count(n - 2) == 0)
			trib_cash[n - 2] = tripponach(n - 2);
		if (trib_cash.count(n - 1) == 0)
			trib_cash[n - 3] = tripponach(n - 3);

		return trib_cash[n - 1] + trib_cash[n - 2] + trib_cash[n - 3];
	}
}

int fibonnach(int n) {
	if (n == 2 || n == 1)
		return 1;
	else
	{	
		if (fib_cash.count(n - 1) == 0)
			fib_cash[n - 1] = fibonnach(n - 1);
		if (fib_cash.count(n - 2) == 0)
			fib_cash[n - 2] = fibonnach(n - 2);
		return fib_cash[n - 1] + fib_cash[n - 2];
	}
}

void print_n_fib(int n) {
	if (n == 1)
		cout << " ";
	else {
		cout << fibonnach(n - 1) << " ";
		print_n_fib(n - 1);
	}
}

void print_n_trib(int n) {
	if (n == 1)
		cout << " ";
	else {
		cout << tripponach(n - 1) << " ";
		print_n_trib(n - 1);
	}
}


int main() {
	int n;
	cin >> n;
	n++;
	cout << "N чисел фибонначи: \n";
	print_n_fib(n);
	cout << "\nN чисел триибонначи: \n";
	print_n_trib(n);

}
