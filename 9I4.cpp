#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите размерность массива(n)\n";
	cin >> n;
	int** tab;
	tab = new int*[n];
	int *vectoritto = new int[n];
	for (int i = 0; i < n; i++)
		tab[i] = new int[n];
	cout << "Введите массив\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> tab[i][j];
	cout << "Введите вектор X\n";
	for (int i = 0; i < n; i++)
		cin >> vectoritto[i];
	for (int i = 1; i < n; i+=2)
		for (int j = 0; j < n; j++) {
			tab[i][j] = vectoritto[j];
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}