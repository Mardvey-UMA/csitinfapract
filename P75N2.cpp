#include <iostream>
#include <cmath>
//16 12 10 16 6 12 9
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "������ ���浪��� ����� ��� �����:\n";
    int n;
    cin >> n;
    if (abs(n) > 31 || n <= 0){
        cout << "��� ⠪��� ��� �����\n";
    }else if (abs(31 - n) == 0){
        cout << "�� ����� �����";
    }else{
        cout << "��� �⮫쪮 ���� �� ���� �����: " << abs(31 - n);
    }
�����
 10 ��� �⮫쪮 ���� �� ���� �����: 21
 -1 ��� ⠪��� ��� �����
 31 �� ����� �����
}
