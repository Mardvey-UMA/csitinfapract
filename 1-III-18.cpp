#include <iostream>
//18)������� �� ��㣮�쭨� � ��஭��� a,b,c ��אַ㣮���
//https://urait.ru/viewer/programmirovanie-na-yazyke-s-prakticheskiy-kurs-438987#page/39

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, c, temp;
    cout << "������ ���祭�� ��஭ ��㣮�쭨��:\n";
    cin >> a >> b >> c;
    // ���஢�� �� �����⠭��, �⮡� c - �뫮 ���ᨬ���� � ���� �।���������� ����⥭㧠
    if (a > b) { // �᫨ a > b � ���塞 ���⠬� a � b
        temp = b;
        b = a;
        a = temp;

        if (b > c) { // �᫨ �����﫨 ���⠬� a � b � �஢��塞 b > c ⮣�� ���塞 �� ���⠬�
            temp = c;
            c = b;
            b = temp;

            if (a > b) { // ⠪ ��� �����﫨 ���⠬� ����� �஢��ﬥ� a > b, �� ��砩 �᫨ c �뫮 ����� a
                temp = b;
                b = a;
                a = temp;

            }
        }
    }
    else if (b > c) { // �᫨ a � b �� ���� �뫮 ������ ���⠬� �஢��塞 b � c � ���塞 ���⠬�
        temp = c;
        c = b;
        b = temp;

        if (a > b) { // �᫨ �����﫨 b � c ���⠬� �஢��塞 �� �㦭� �� �������� a � b �᫨ c ����� a
            temp = b;
            b = a;
            a = temp;

        }
    }
    cout << ((c*c == a*a + b*b) ? "��㣮�쭨� ��אַ㣮���" : "��㣮�쭨� �� ��אַ㣮���");
    // 3 4 5 ��אַ㣮���
    // 6 6 6 �� ��אַ㣮���
    // 1 2 4 �� ��אַ㣮���
    // 1 1 1.41421356237 �� ��אַ㣮���
    // 800 600 1000 ��אַ㣮���
    return 0;
}