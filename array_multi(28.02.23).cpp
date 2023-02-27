#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int multiply_array(int *arr, int n) {
	if (n == 0) {
		return arr[n];
	}
	else {
		return multiply_array(arr, n - 1) * arr[n];
	}
}

int main() {
	int n = 10, min = 1, max = 10, test = 1;
	srand(time(NULL));
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = min + rand() % (max - min + 1);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		test *= arr[i];
	}
	cout << endl;
	cout << multiply_array(arr, n - 1) << endl;
}
