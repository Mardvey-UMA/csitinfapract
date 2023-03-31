#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// В Алфавитном порядке по фамилии, имени, Отчеству

ifstream fin("students.txt");
ofstream fout("output_quck_sort.txt");

void split(string* split_string, string s, int& n, char c) {
	string temp = "";
	s += c;
	for (int k = 0; k < s.size(); k++) {
		if (s[k] != c) {
			temp += s[k];
		}
		else {
			split_string[n] = temp;
			temp = "";
			n++;
		}
	}
}

struct Student {
	string name, surname, otch;
	int yearbirth, m1, m2, m3, m4, m5, group;
	void put_in_file();
	Student();
	Student(int group_, string surname_, string name_, string otch_, int yearbirth_, int m1_, int m2_, int m3_, int m4_, int m5_);
};
Student::Student(int group_, string surname_, string name_, string otch_, int yearbirth_, int m1_, int m2_, int m3_, int m4_, int m5_) {
	group = group_;
	name = name_;
	surname = surname_;
	otch = otch_;
	yearbirth = yearbirth_;
	m1 = m1_;
	m2 = m2_;
	m3 = m3_;
	m4 = m4_;
	m5 = m5_;
}
Student::Student() {
	group = 0;
	name = " ";
	surname = " ";
	otch = " ";
	yearbirth = 0;
	m1 = 0;
	m2 = 0;
	m3 = 0;
	m4 = 0;
	m5 = 0;
}
void Student::put_in_file() {
	fout << group << " " << surname << " " << name << " " << otch << " ";
	fout << yearbirth << " " << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 << endl;
}

int diff_func(int i, int j, Student* a) {
	auto s1 = a[i];
	auto s2 = a[j];
	/*if (((s1.surname < s2.surname) || ((s1.surname == s2.surname) && (s1.name < s2.name)) || ((s1.surname == s2.surname) && (s1.name == s2.name) && (s1.otch < s2.otch))))
		return 1;
	else
		return 0;*/
	if (s1.surname > s2.surname)
		return 0;
	else
		return 1;
}
int diff_func(Student s1, Student s2) {
	/*if (((s1.surname < s2.surname) || ((s1.surname == s2.surname) && (s1.name < s2.name)) || ((s1.surname == s2.surname) && (s1.name == s2.name) && (s1.otch < s2.otch))))
		return 1;
	else
		return 0;*/
	if (s1.surname <= s2.surname)
		return 0;
	else
		return 1;
}
int findpivot(int i, int j, Student* a);
int partition(int i, int j, Student pivot, Student* a);

void quicksort(int i, int j, Student* a)
{
	cout << i << " " << j << endl;
	int pivotindex = findpivot(i, j, a);
	if (pivotindex != -1)
	{
		auto pivot = a[pivotindex];
		int k = partition(i, j, pivot, a);
		quicksort(i, k - 1, a);
		quicksort(k, j, a);
	}
}

int findpivot(int i, int j, Student* a)
{
	for (int k = i + 1; k <= j; k++)
		if (diff_func(i, k, a) == 0)
			return k;
		else if (diff_func(i, k, a) == 1)
			return i;
	return -1;
}

int partition(int i, int j, Student pivot, Student* a)
{
	int l = i;
	int r = j;
	do
	{
		while (diff_func(a[l], pivot) == 0)
			l++;
		while (diff_func(a[l], pivot) == 1)
			r--;
		if (l < r)
		{
			auto temp = a[r];
			a[r] = a[l];
			a[l] = temp;
		}
	} while (l <= r);
	return l;
}

int main() {

	setlocale(LC_ALL, "Russian");
	int n = 100, c = 0, nn = 10, k = 0;
	Student* students = new Student[n];
	string info;
	while (fin.peek() != EOF) {
		getline(fin, info);
		nn = 10;
		k = 0;
		string* tmp = new string[nn];
		split(tmp, info, k, ' ');
		students[c].group = stoi(tmp[0]);
		students[c].surname = tmp[1];
		students[c].name = tmp[2];
		students[c].otch = tmp[3];
		students[c].yearbirth = stoi(tmp[4]);
		students[c].m1 = stoi(tmp[5]);
		students[c].m2 = stoi(tmp[6]);
		students[c].m3 = stoi(tmp[7]);
		students[c].m4 = stoi(tmp[8]);
		students[c].m5 = stoi(tmp[9]);
		c++;
	}
	quicksort(0, c - 1, students);
	for (int i = 0; i < c; i++)
		students[i].put_in_file();

}
