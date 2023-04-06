#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

void diag_iter(pair<int, int>& coord, int flag = 1) {
	if (flag == 1) { // up
		coord.first--;
		coord.second++;
	}
	else if (flag == 0) { // down
		coord.first++;
		coord.second--;
	}
}

void make_heap(int* arr, int n, int i, int flag = 1) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (flag == 1) {
		if (l < n && arr[l] > arr[largest]) largest = l;
		if (r < n && arr[r] > arr[largest]) largest = r;
	}
	else if (flag == 0) {
		if (l < n && arr[l] < arr[largest]) largest = l;
		if (r < n && arr[r] < arr[largest]) largest = r;
	}
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		make_heap(arr, n, largest);
	}
}


void pyramid_sort(int* arr, int n, int flag = 1) {
	for (int i = n / 2 - 1; i >= 0; i--) make_heap(arr, n, i, flag);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		make_heap(arr, i, 0, flag);
	}
}

int main() {
	int n;
	setlocale(LC_ALL, "Russian");
	cout << "Введите размерность массива n\n";
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	cout << "Введите массив по строчкам\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	cout << endl;

	for (int i = 1; i < n - 1; i++) {
		// СОРТИРУЕМ ВЫШЕ ПОБОЧКИ ПО УБЫВАНИЮ
		pair <int, int> bot1;
		bot1.first = i;
		bot1.second = 0;
		pair <int, int> top1;
		top1.first = 0;
		top1.second = i;
		/////////////////////
		int* u = new int[i + 1];
		int c = 0;
		for (auto t = bot1; t.second <= top1.second; diag_iter(t)) {
			u[c] = arr[t.first][t.second];
			c++;
		}
		int s = i + 1;
		pyramid_sort(u, s, 0);
		int r = 0;
		for (auto y = bot1; y.second <= top1.second; diag_iter(y)) {
			arr[y.first][y.second] = u[r];
			r++;
		}
		// НАСОРТИРОВАЛИСЬ ПО НОВОЙ ДАВАЙ
		///////////////////
		// СОРТИРУЕМ НИЖЕ ПОБОЧКИ ПО ВОЗРАСТАНИЮ
		pair <int, int> bot2;
		bot2.second = i;
		bot2.first = n - 1;
		pair <int, int> top2;
		top2.second = n - 1;
		top2.first = i;
		int* e = new int[i + 1];
		c = 0;
		for (auto t = bot2; t.second <= top2.second; diag_iter(t)) {
			e[c] = arr[t.first][t.second];
			c++;
		}
		s = n - i;
		pyramid_sort(e, s);
		r = 0;
		for (auto y = bot2; y.second <= top2.second; diag_iter(y)) {
			arr[y.first][y.second] = e[r];
			r++;
		}
		////////////////////
	}
	cout << "Отсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == 0 && j == 0) || (i + j == n - 1) || (i == n - 1 && j == n - 1))
				cout << " ";
			else
				cout << arr[i][j] << " ";

		}
		cout << endl;
	}
}
