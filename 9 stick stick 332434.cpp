#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main() {
	string s1, s2;
	double x1, x2;
	while (in.peek() != EOF) {
		in >> s1 >> s2;
		x1 = stod(s1);
		x2 = stod(s2);
		out << (x1 + x2) / 2. << endl;
	}
	in.close();
	out.close();
	
}