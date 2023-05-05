#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
// В Алфавитном порядке по фамилии, имени, Отчеству, а затем по убыванию года рождения

ifstream fin("students_stable_sort.txt");
ofstream fout("output_stable_sort.txt");

void split(string *split_string, string s, int &n, char c)
{
    string temp = "";
    s += c;
    for (int k = 0; k < s.size(); k++)
    {
        if (s[k] != c)
        {
            temp += s[k];
        }
        else
        {
            split_string[n] = temp;
            temp = "";
            n++;
        }
    }
}

struct Student
{
    string name, surname, otch;
    int yearbirth, m1, m2, m3, m4, m5, group;
    void put_in_file();
    Student();
    Student(int group_, string surname_, string name_, string otch_, int yearbirth_, int m1_, int m2_, int m3_, int m4_, int m5_);
};
Student::Student(int group_, string surname_, string name_, string otch_, int yearbirth_, int m1_, int m2_, int m3_, int m4_, int m5_)
{
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
Student::Student()
{
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

void Student::put_in_file()
{
    fout << group << " " << surname << " " << name << " " << otch << " ";
    fout << yearbirth << " " << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 << endl;
}
bool predicatic(Student s1, Student s2)
{
    return ((s1.surname < s2.surname) || ((s1.surname == s2.surname) && (s1.name < s2.name)) || ((s1.surname == s2.surname) && (s1.name == s2.name) && (s1.otch < s2.otch)) || ((s1.surname == s2.surname) && (s1.name == s2.name) && (s1.otch == s2.otch) && (s1.yearbirth > s2.yearbirth)));
}

int main()
{
    int n, nn = 10, k = 0, sort_type; // 0 - обычная, 1 - stable
    fin >> n;
    fin >> sort_type;
    vector<Student> students;
    string info;
    getline(fin, info);
    while (fin.peek() != EOF)
    {
        getline(fin, info);
        nn = 10;
        k = 0;
        string *tmp = new string[nn];
        split(tmp, info, k, ' ');
        Student t(stoi(tmp[0]), tmp[1], tmp[2], tmp[3], stoi(tmp[4]), stoi(tmp[5]), stoi(tmp[6]), stoi(tmp[7]), stoi(tmp[8]), stoi(tmp[9]));
        students.push_back(t);
    }
 
    if (sort_type == 0)
        sort(students.begin(), students.end(), predicatic);
    if (sort_type == 1)
        stable_sort(students.begin(), students.end(), predicatic);

    for (int i = 0; i < students.size(); i++)
        students[i].put_in_file();
}