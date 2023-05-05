#include <iostream>
#include <vector>
#include <set>

using namespace std;
//Найти цифры которое нечетное число раз встречаются
int main(){
    int n, x;
    vector <int> nums;
    vector <int> cif(10);
    vector <set<int>> ans;
    vector <int> null_vec{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    set <int> tmp;
    cout << "Enter n, and n numbers" << endl;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        nums.push_back(x);
    }
    for (int i = 0; i < n; i++){
        x = nums[i];
        ///
        for (int f = 0; f < 10; f++)
            cif[f] = 0;
        //cif = cif * null_vec;
        tmp.clear();
        ///
        while (x){
            cif[x % 10]++;
            tmp.insert(x % 10);
            x /= 10;
        }
        for (int c = 0; c < 10; c++){
            if (cif[c] % 2 == 0){
                tmp.erase(cif[c]);
            }
        }
        ans.push_back(tmp);
    }
    for (int i = 0; i < n; i++){       
        cout << nums[i] << "(";
        for (auto x: ans[i])
            cout << x;
        cout << "), ";
    }
    cout << endl;
    system("pause");
}
/*
5
1122333 456 1011011 12345 888898
*/
//1122333(13), 456(456), 1011011(1), 12345(12345), 888898(89)