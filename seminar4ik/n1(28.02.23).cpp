#include<iostream>

using namespace std;

int main() {
	int temp;
	int n, j; cin >> n;
	int* ar = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 1; i < n; i++) {
		j = i;
		while (ar[j] < ar[j - 1]) {
			temp = ar[j];
			ar[j] = ar[j - 1]; //swap ar[j] & ar[j-1]
			ar[j - 1] = temp;
			j--;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}
}
