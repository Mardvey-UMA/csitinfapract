#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    vector <int> vec{ 1, 3, 76, 98, 34, 22, 11, 7, 6, 5, 2, 0 };
    list <int> lst{ 4, 1, 8, 9, 0, 3, 2, 7, 5, 11, 345 };
    // A.1
    vector <int> tmp;
    cout << "Start(vector)\n";
    for (auto x : vec)
        cout << x << " ";
    cout << endl;
    cout << "Rukami\n";
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (isPrime(*it)) {
            tmp.push_back(*it);
            vec.erase(--it);
        }
    }
    for (auto it = vec.begin(); it != vec.end(); it++)
        tmp.push_back(*it);
    
    for (auto x : tmp)
        cout << x << " ";
    cout << endl;
    //A.2
    cout << "Partition\n";
    vector <int> vec2{ 1, 3, 76, 98, 34, 22, 11, 7, 6, 5, 2, 0 };
    auto it = partition(vec2.begin(), vec2.end(), isPrime);
    for (auto x : vec2)
        cout << x << " ";
    cout << endl << endl;
    //B.1
    list <int> tmp_l;
    cout << "Start(list)\n";
    for (auto x : lst)
        cout << x << " ";
    cout << endl;
    auto itd = lst.begin();
    while (itd != lst.end()) {
        if (isPrime(*itd)) {
            tmp_l.push_back(*itd);
            itd = lst.erase(itd);
        }else{
            ++itd;
        }
    }
    for (auto it = lst.begin(); it != lst.end(); it++)
        tmp_l.push_back(*it);
    cout << "Rukami\n";
    for (auto x : tmp_l)
        cout << x << " ";
    cout << endl;
    //B.2
    cout << "Partition\n";
    list <int> lst2{ 4, 1, 8, 9, 0, 3, 2, 7, 5, 11, 345 };
    auto it2 = partition(lst2.begin(), lst2.end(), isPrime);
    for (auto x : lst2)
        cout << x << " ";
    cout << endl;
    system("pause");
}