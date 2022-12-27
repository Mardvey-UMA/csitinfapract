#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt");

int main() {
	string s;
	unsigned int max_len = 0, pos, cnt = 1;
	while (getline(in, s)) {
		if (s.size() > max_len) {
			max_len = s.size();
			pos = cnt;
		}
		cnt++;
	}
	cout << pos;
	
}