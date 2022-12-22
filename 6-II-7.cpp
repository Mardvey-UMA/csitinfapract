//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/140
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "������ ࠧ��୮��� ���ᨢ�\n";
    int n, pos = 0;
    cin >> n;
    int arr[n];
    cout << "������ �������� ���ᨢ�\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int min = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] < min && pos <= i){
            pos = i;
            min = arr[i];
        }
    }
    cout << pos << endl;
}