// Измененный код на C++
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
    string name, surname, patronymic;
    int birth_year, mark1, mark2, mark3, mark4, mark5, group;

    Student();
    Student(int group_, string surname_, string name_, string patronymic_, int birth_year_, int mark1_, int mark2_, int mark3_, int mark4_, int mark5_);
    void put_in_file();
    void print();
};

Student::Student(int group_, string surname_, string name_, string patronymic_, int birth_year_, int mark1_, int mark2_, int mark3_, int mark4_, int mark5_) {
    group = group_;
    name = name_;
    surname = surname_;
    patronymic = patronymic_;
    birth_year = birth_year_;
    mark1 = mark1_;
    mark2 = mark2_;
    mark3 = mark3_;
    mark4 = mark4_;
    mark5 = mark5_;
}

Student::Student() {
    group = 0;
    name = " ";
    surname = " ";
    patronymic = " ";
    birth_year = 0;
    mark1 = 0;
    mark2 = 0;
    mark3 = 0;
    mark4 = 0;
    mark5 = 0;
}

void Student::put_in_file() {
    fout << group << " " << surname << " " << name << " " << patronymic << " ";
    fout << birth_year << " " << mark1 << " " << mark2 << " " << mark3 << " " << mark4 << " " << mark5 << endl;
}

void Student::print() {
    cout << group << " " << surname << " " << name << " " << patronymic << " ";
    cout << birth_year << " " << mark1 << " " << mark2 << " " << mark3 << " " << mark4 << " " << mark5 << endl;
}

int diff_func(Student s1, Student s2) {
    if (((s1.surname < s2.surname) || ((s1.surname == s2.surname) && (s1.name < s2.name)) || ((s1.surname == s2.surname) && (s1.name == s2.name) && (s1.patronymic < s2.patronymic))))
        return 1;
    else
        return 0;
}

int partition(Student* a, int start, int end)
{
    auto pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (diff_func(a[i], pivot) == 1)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[end]);
    return pIndex;
}

void quicksort(Student* a, int start, int end)
{
    if (start >= end) {
        return;
    }
    int pivot = partition(a, start, end);
    quicksort(a, start, pivot - 1);
    quicksort(a, pivot + 1, end);
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
        students[c].patronymic = tmp[3];
        students[c].birth_year = stoi(tmp[4]);
        students[c].mark1 = stoi(tmp[5]);
        students[c].mark2 = stoi(tmp[6]);
        students[c].mark3 = stoi(tmp[7]);
        students[c].mark4 = stoi(tmp[8]);
        students[c].mark5 = stoi(tmp[9]);
        c++;
    }
    quicksort(students, 0, c - 1);
    for (int i = 0; i < c; i++)
        students[i].put_in_file();
    for (int i = 0; i < c; i++)
        students[i].print();
}
