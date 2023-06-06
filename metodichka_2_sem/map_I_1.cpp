// Во входном файле задан набор слов и целых чисел, разделённых пробелами.
// Подсчитать, сколько раз встречается каждое присутствующее в файле число
#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
map<int, int> numbers_counter(string s, char c = ' ') { 
	string temp = "";
	map<int, int> res;
    s += c;
	for (int k = 0; k < s.size(); k++) {
		if (s[k] != c) {
			temp += s[k];
		}
		else {
            int coef = 1;
            if (temp[0] == '-') {
                temp.erase(temp.begin());
                coef = -1;
            }
            auto it = temp.begin();
            while (it != temp.end() && isdigit(*it)) ++it;
            if (!temp.empty() && it == temp.end()){
                int u = (coef * stoi(temp));
                res[u]++;
            }
                temp = "";
		}
	}
    return res;
}
int main(){
    ifstream fin;
    fin.open("mapI_input.txt");
    string s = "", tmp;
    while (fin.peek() != EOF){
        getline(fin, tmp);
        tmp = " " + tmp;
        s += tmp;
    }
    auto ans = numbers_counter(s);
    cout << "Number | Count\n";
    for (auto x: ans){
        cout << setw(5);
        cout << x.first << "  |  " << x.second << "\n";
    }
    cout << endl;
    system("pause");
}