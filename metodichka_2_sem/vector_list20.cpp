#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main(){
    set <char> tmp;
    int n = 10;
    vector <string> vec(n);
    list <string> lst(n);
    cout << "AAA" << endl;
    //A vector
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    string second = vec[1];
    string pred = vec[n - 2];
    for (int i = 0; i < second.size(); i++){
        tmp.insert(second[i]);
    }
    vec[1] = tmp.size();
    for (int i = 0; i < pred.size(); i++){
        tmp.insert(pred[i]);
    }
    vec[n - 2] = tmp.size();
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;
    cout << "BBB" << endl;
    //B List
    for (auto i = lst.begin(); i != lst.end(); i++){
        cin >> *i;
    }
    auto f = lst.begin();
    string ff = *f;
    string rev = string(ff.rbegin(), ff.rend());
    f++;
    lst.insert(f, rev);
    for (int i = 0; i < n - 2; i++){
        f++;
    }
    ff = *f;
    string rev2 = string(ff.rbegin(), ff.rend());
    lst.insert(f, rev2);

    for (auto i = lst.begin(); i != lst.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    system("pause");
    //1 22345 3 4 5 6 7 8 991199 10
    //1234 5 6 7 8 9 10 8 9 345
}