//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/140
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    int flag;
    cout << "������ : �������� - 1 ��㬥�� - 2\n";
    cin >> flag;
    if (flag == 1){
        int n;
        cout << "������ ࠧ��୮��� ���ᨢ� - n\n";
        cin >> n;
        int *arr = new int[n];
        cout << "������ ������ ���ᨢ�\n";
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << "�⢥�:" << endl;
        for (int i = 0; i < n; i++){
            if (!(i & 1))
                cout << arr[i] << " ";
        }
    }else if (flag == 2){
        int m, n;
        cout << "������ ������⢮ ����� � �������� ���ᨢ� ᮮ⢥�ᢥ���:\n";
        cin >> n >> m;
        cout << "������ ���ᨢ �� ���窠�:\n";
        int **arr;
        arr = new int *[n];
        for(int i = 0; i < n; ++i)
            arr[i]= new int [m];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> arr[i][j];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if ((i + j) % 2 == 0)
                    cout << arr[i][j] << " ";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }else{
        cout << "��� ⠪��� ��ਠ�� .....";
    }
    //�����:
    //����
    // 2
    // 3 5
    // 1 2 3 4 5
    // 1 2 3 4 5
    // 1 2 3 4 5
    // �뢮�:
    // 1  3  5
    //  2  4
    // 1  3  5
    //����
    // 1
    // 5
    // 1 2 3 4 5
    // �뢮�:
    // 1  3  5
    // ����
    // 100
    // �뢮�
    // ��� ⠪��� ��ਠ�� .....

}