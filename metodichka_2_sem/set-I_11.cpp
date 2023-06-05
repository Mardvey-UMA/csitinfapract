#include <iostream>
#include <vector>
#include <set>
typedef long long li;
using namespace std;
//Найти цифры которое нечетное число раз встречаются
int main(){
    li u, x;
    vector<int> ggg;
    cout << "Enter number n\n";
    cin >> u;
    while(u--){
        int ty;
        cin >> ty;
        ggg.push_back(ty);
    }
    for (auto n: ggg){
    n = abs(n);
    set<li> st1;
    set<li> st2;
    while (n){
        li c = n%10;
        if(st1.find(c) == st1.end() && st2.find(c) == st2.end())
            st1.insert(c);
        else if (st2.find(c) != st2.end()){
            st2.erase(c);
            st1.insert(c);
        }
        else if (st1.find(c) != st1.end()){
            st1.erase(c);
            st2.insert(c);
        }
        n/=10;
    }
    for(auto it : st1)
        cout << it << ' ';
    cout << endl;
    }
   
    cout << endl;
    system("pause");
}
/*
5
1122333 456 1011011 12345 888898
*/
//1122333(13), 456(456), 1011011(1), 12345(12345), 888898(89)
