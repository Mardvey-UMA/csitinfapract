#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int randomInt(int a, int b) {
	return rand() % (b - a + 1) + a;
}
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
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n = 10;
	string* colors = new string[10];
	colors[0] = "red";
	colors[1] = "green";
	colors[2] = "purple";
	colors[3] = "pink";
	colors[4] = "blue";
	colors[5] = "magenta";
	colors[6] = "yellow";
	colors[7] = "white";
	colors[8] = "black";
	colors[9] = "gray";
	cout << "Не отсортированные\n\n";
	BowlingBall* balls = new BowlingBall[n];
	int randWeight, col;
	for (int i = 0; i < n; i++) {
		randWeight = randomInt(1, 11);
		col = randomInt(0, 9);
		balls[i].setParams(randWeight, colors[col]);
		balls[i].print();
	}
	cout << "\nОтсортированные\n\n";
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && (balls[j] < balls[j - 1]); j--) // пока j>0 и элемент j-1 > j, x-массив int
			swap(balls[j - 1], balls[j]);
	for (int i = 0; i < n; i++)
		balls[i].print();
}
