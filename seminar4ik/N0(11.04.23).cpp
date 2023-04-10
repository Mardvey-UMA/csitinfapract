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
	// используем префиксный инкримент
	BowlingBall ball1(10, "purple");
	(++ball1).print();
	// out: 11 (purple)
	//Создается объект с весом 10 и цветом purple, после
	//Приминения префиксного инкримента к весу, вес увеличивается на 1
	// Префиксный инкримент изменяет поле данных веса шара
	//Пример с постфиксным инкриментом
	BowlingBall ball2(3, "green");
	ball2++.print();
	// out: 3 (green)
	// Постфиксный инкримент возвращает старое значение веса
}
