#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void split(vector<string> &split_string, string s) { 
	string temp = "";
	for (int k = 0; k < s.size(); k++) {
		if (s[k] != '!' && s[k] != '?' && s[k] != '.') {
			temp += s[k];
            if (s[k + 1] == '!' || s[k + 1] == '?' || s[k + 1] == '.'){
                temp += s[k + 1];
            }
		}
		else {
            if (*temp.begin() == ' ') temp.erase(temp.begin());
			split_string.push_back(temp);
			temp = "";
		}
	}
}
void split(set<string> &words, string s, char c = ' ') { 
	string temp = "";
    s.pop_back();
    s += c;
	for (int k = 0; k < s.size(); k++) {
		if (s[k] != c) {
			temp += s[k];
		}
		else {
			words.insert(temp);
			temp = "";
		}
	}
}
int main(){
    //Найти слова (без учёта регистра) и их количество 
    // которые встречаются только в повествовательных и вопросительных предложениях.
    string text;
    getline(cin, text);
    vector <string> sentences;
    split(sentences, text);
    set <string> question_s;
    set <string> povest_s;
    set <string> voskl_s;
    for (string w: sentences){
        if (*w.rbegin() == '!'){
            split(voskl_s, w);
        }else if(*w.rbegin() == '?'){
            split(question_s, w);
        }else if(*w.rbegin() == '.'){
            split(povest_s, w);
        }
    }
    set <string> q_p;
    set_union(question_s.begin(), question_s.end(), povest_s.begin(), povest_s.end(), inserter(q_p, q_p.begin()));
    set <string> inter_sets;
    set_intersection(q_p.begin(), q_p.end(), voskl_s.begin(), voskl_s.end(), inserter(inter_sets, inter_sets.begin()));
    set <string> ans;
    set_difference(q_p.begin(), q_p.end(), inter_sets.begin(), inter_sets.end(), inserter(ans, ans.begin()));
    cout << ans.size() << endl;
    for (string x: ans){
        cout << x << endl;
    }
    cout << endl;
    system("pause");
}

    /*
    Hi how are you? I want to eat. Let's go for a bike ride. Let's jump through puddles. Hi how's your mom doing? Hi! I ate a lemon cake! Am I sick? I have solved very difficult programming tasks! I have not solved very simple mathematical analysis problems.
    25
Am
Let's
analysis
are
bike
doing
eat
for
go
how
how's
jump
mathematical
mom
not
problems
puddles
ride
sick
simple
through
to
want
you
your
    */
