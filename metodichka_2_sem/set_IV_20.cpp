#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;
//20)   Для каждой пары из i-й с конца и i-й c начала строки найти числа, 
//которые встречаются в обеих ровно один раз
vector<int> split(string s, char c = ' ') { 
	string temp = "";
	vector <int> res;
    s += c;
	for (int k = 0; k < s.size(); k++) {
		if (s[k] != c) {
			temp += s[k];
		}
		else {
            if (temp != "" && temp != " "){
                int u = stoi(temp);
                res.push_back(u);
            }
			temp = "";
		}
	}
    return res;
}

set <int> unique_num(vector <int> v1, vector <int> v2){
    set <int> s1, s2, s3;
    for (int i = 0; i < v1.size(); i++){
        if (s1.find(v1[i]) == s1.end() && s3.find(v1[i]) == s3.end()){
            s1.insert(v1[i]);
            s3.insert(v1[i]);
        }else{
            s1.erase(v1[i]);
        }
    }
    s3.clear();
    for (int i = 0; i < v2.size(); i++){
        if (s2.find(v2[i]) == s2.end() && s3.find(v2[i]) == s3.end()){
            s2.insert(v2[i]);
            s3.insert(v2[i]);
        }else{
            s2.erase(v2[i]);
        }
    }
    s3.clear();
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
    return s3;
}

int main(){
    ifstream fin;
    fin.open("setIV_input.txt");
    string tmp;
    vector<vector<int>> nums;
    while (fin.peek() != EOF){
        getline(fin, tmp);
        nums.push_back(split(tmp));
    }
    int start = 0;
    int end = nums.size() - 1;
    while (true){
        cout << "-------------------------------\n";
        for (auto x: nums[start])
            cout << x << " ";
        cout << endl;
        for (auto x: nums[end])
            cout << x << " ";
        cout << endl;
        for (auto x: unique_num(nums[start], nums[end]))
            cout << x << " ";
        cout << endl;
        
        end--;
        start++;
    if (end <= start) break;    
    }
    system("pause");

}