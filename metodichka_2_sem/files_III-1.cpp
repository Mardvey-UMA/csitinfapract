#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите n" << endl;
	int n, cnt = 1;
	string s, temp = "";
	cin >> n;
	ofstream fout("txt.bin", ios_base::binary);
	ifstream fin("txt.bin", ios_base::binary);
	if (n <= 0) {
		cout << "Извините число должно быть натуральным" << endl;
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		int k = i * i;
		fout.write((char*)&k, sizeof(int));
	}
	fout.close();
	int tmp;
	while (fin.peek() != EOF) {
		fin.read((char*)&tmp, sizeof(int));
		cout << tmp << " ";
		fin.seekg(sizeof(int), ios::cur);
		if (fin.peek() == EOF)
			break;
	}
	fin.close();

}

//10
//1 9 25 49 81
//11
//1 9 25 49 81 121
//-10
//Извините число должно быть натуральным
