#include <iostream>
#include <string>

using namespace std;

class BowlingBall {
	int weight;
	string color;
public:
	static int count;
	BowlingBall() {
		count++;
	} // = default;

	BowlingBall(int weight, string color) {
		count++;
		setParams(weight, color);
	}

	BowlingBall(const BowlingBall& other) {
		setParams(other.weight, other.color);
		count++;
	}

	bool setWeight(int weight) {
		if (weight > 0) {
			this->weight = weight;
			return true;
		}
		return false;
	}
	bool setColor(string color) {
		if (color != "") {
			this->color = color;
			return true;
		}
		return false;
	}
	void setParams(int weight, string color) {
		setWeight(weight);
		setColor(color);
	}
	bool operator<(const BowlingBall& other) {
		return weight < other.weight;
	}
	bool operator==(const BowlingBall& other) {
		return (weight == other.weight) && (color == other.color);
	}

	void print() {
		cout << weight << " (" << color << ")\n";
	}

	// ++b
	BowlingBall& operator++() {
		weight++;
		return *this;
	}
	// b++
	BowlingBall operator++(int) {
		BowlingBall tmp(*this);
		weight++;
		return tmp;
	}
};

int BowlingBall::count = 0;

int main()
{
	BowlingBall b1(10, "red");
	BowlingBall b2(11, "green");
	BowlingBall b3(b2);
	BowlingBall b4(10, "red");
	cout << (b1 < b2) << endl;
	cout << (b1 == b2) << endl;
	cout << (b3 == b2) << endl;
	cout << (b1 == b4) << endl;
	cout << (b3 < b1) << endl;
	// Примеры сравнения различных шаров
}
