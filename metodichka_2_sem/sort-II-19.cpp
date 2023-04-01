#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;
int n = 0;
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
pair<int, int> diag_iter_r(pair<int, int>& coord, int flag = 1) {
	diag_iter(coord, flag);
	return coord;
}

int get_diff(pair<int, int> p1, pair<int, int> p2, int n, int flag = 1) {
	double r1, r2;
	r1 = sqrt((p1.first - (n - 1)) * (p1.first - (n - 1)) + (p1.second * p1.second));
	r2 = sqrt((p2.first - (n - 1)) * (p2.first - (n - 1)) + (p2.second * p2.second));
	if (flag == 1)
		if (r1 >= r2) return 1;
		else return 0;
	else if (flag == 0)
		if (r1 > r2) return 1;
		else return 0;
}
pair <int, int> findpivot(int** a, pair <int, int> e1, pair <int, int> e2) {
	pair <int, int> mx_idx;
	int mx_elem = -10000000;
	pair<int, int> t = e1;
	for (t; (get_diff(t, e2, n, 0) == 0); diag_iter(t)) {
		if (a[t.first][t.second] >= mx_elem) {
			mx_elem = a[t.first][t.second];
			mx_idx = t;
		}
	}
	return mx_idx;
}
pair<int, int> partition(int** a, pair<int, int> l, pair<int, int> r, int pivot, bool flag) {
	if (flag == false) {
		do {
			while (a[l.first][l.second] < pivot && l.first > 0 && l.second < n - 1) diag_iter(l);
			while (a[r.first][r.second] >= pivot && r.second > 0 && r.first < n - 1) diag_iter(r, 0);
			if (l.second < r.second) swap(a[r.first][r.second], a[l.first][l.second]);
			if (l == r) break;
		} while (l.second <= r.second);
	}
	else {
		do {
			while (a[l.first][l.second] >= pivot && l.first > 0 && l.second < n - 1) diag_iter(l);
			while (a[r.first][r.second] < pivot && r.second > 0 && r.first < n - 1) diag_iter(r, 0);
			if (l.second < r.second) swap(a[r.first][r.second], a[l.first][l.second]);
			if (l == r) break;
		} while (l.second <= r.second);
	}
	return l;
}
void quicksort(int** a, pair<int, int> start, pair<int, int> end, bool r = false) {
	auto pivotindex = findpivot(a, start, end);
	int pivot = a[pivotindex.first][pivotindex.second];
	pair<int, int> k = partition(a, start, end, pivot, r);
	if (end.second <= start.second)
		return;
	if (start.first != end.first && start.second != end.second && a[start.first][start.second] != a[end.first][end.second]) {
		quicksort(a, start, diag_iter_r(k, 0), r);
		quicksort(a, diag_iter_r(k), end, r);
	}
	}

int main() {
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
		pair <int, int> bot1;
		bot1.first = i;
		bot1.second = 0;
		pair <int, int> top1;
		top1.first = 0;
		top1.second = i;
		pair <int, int> bot2;
		bot2.second = i;
		bot2.first = n - 1;
		pair <int, int> top2;
		top2.second = n - 1;
		top2.first = i;
		quicksort(arr, bot1, top1, true);
		quicksort(arr, bot2, top2);
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
