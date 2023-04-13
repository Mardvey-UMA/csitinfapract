#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// В Алфавитном порядке по фамилии, имени, Отчеству, а затем по убыванию года рождения

ifstream fin("students.txt");
ofstream fout("output2.txt");

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
bool predicatic(Student s1, Student s2){
	return ((s1.surname < s2.surname) || ((s1.surname == s2.surname) && (s1.name < s2.name)) || ((s1.surname == s2.surname) && (s1.name == s2.name) && (s1.otch < s2.otch)) || ((s1.surname == s2.surname) && (s1.name == s2.name) && (s1.otch == s2.otch) && (s1.yearbirth > s2.yearbirth)));
}
// Ф1 < Ф2 ||
// Ф1 == Ф2 && И1 < И2 ||
// Ф1 == Ф2 && И1 == И2 && О1 < О2 ||
// Ф1 == Ф2 && И1 == И2 && О1 == О2 && Г1 > Г2 ||
// Ф1 == Ф2 && И1 == И2 && О1 == О2 && Г1 == Г2

void bubble_sort(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 1 < n - i; j++) {
			auto s1 = students[j + 1];
			auto s2 = students[j];
			if (predicatic(s1, s2)) {
				auto t = students[j + 1];
				students[j + 1] = students[j];
				students[j] = t;
			}
		}
	}
}
void insertion_sort(Student* students, int n) {
	for (int i = 1; i < n; i++) {
		auto d = students[i];
		int j = i;
		while (j > 0 && (predicatic(d, students[j - 1]))) {
			students[j] = students[j - 1];
			j--;
		}
		students[j] = d;
	}
}

void selection_sort(Student* students, int n) {
	int key, j, i;
	for (i = 0; i < n - 1; i++) {
		key = i;
		for (j = i + 1; j < n; j++) {
			auto s1 = students[j];
			auto s2 = students[key];
			if (predicatic(s1, s2)) {
				key = j;
			}
		}
		if (key != j) {
			auto t = students[i];
			students[i] = students[key];
			students[key] = t;
		}
	}
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
	//bubble_sort(students, c);
	//insertion_sort(students, c);
	selection_sort(students, c);
	for (int i = 0; i < c; i++)
		students[i].put_in_file();

}
