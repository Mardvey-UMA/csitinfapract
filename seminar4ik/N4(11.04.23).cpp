#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Point {
	double x, y;
public:
	Point(const double x = 0, const double y = 0) {
		this->x = x;
		this->y = y;
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	void setX(double x) {
		this->x = x;
	}
	void setY(double y) {
		this->y = y;
	}
	static double getR(Point& p1, Point& p2) {
		double R = sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
		return R;
	}
};
class Rectangle {
private:
	Point p1, p2, p3, p4;
	// p1 - левый верхний типо центр прямоугольника
	// p2 - правый верхний
	// p3 - правый нижний
	// p4 - левый нижний
	double height, width, diag;
public:
	bool setHeight(double height) {
		if (height > 0) {
			this->height = height;
			return true;
		}
		return false;
	}
	bool setWidth(double width) {
		if (width > 0) {
			this->width = width;
			return true;
		}
		return false;
	}
	double getHeight() {
		return height;
	}
	double getWidth() {
		return width;
	}
	void setP1(Point p1){
		this->p1 = p1;
	}
	void setP2(Point p2) {
		this->p2 = p2;
	}
	void setP3(Point p3) {
		this->p3 = p3;
	}
	void setP4(Point p4) {
		this->p4 = p4;
	}

	Point getP1() {
		return p1;
	}
	Point getP2() {
		return p2;
	}
	Point getP3() {
		return p3;
	}
	Point getP4() {
		return p4;
	}
	bool setNewHeight(double height) {
		if (height > 0) {
			double delta = height - this->height;
			this->height = height;
			p4.setY(p4.getY() + delta);
			p3.setY(p3.getY() + delta);
			return true;
		}
		return false;
	}
	bool setNewWidth(double width) {
		if (width > 0) {
			double delta = width - this->width;
			this->width = width;
			p2.setX(p2.getX() + delta);
			p3.setX(p3.getX() + delta);
			return true;
		}
		return false;
	}
	void setCenter(Point p1) {
		double delta_x = p1.getX() - this->p1.getX();
		double delta_y = p1.getY() - this->p1.getY();
		this->p1 = p1;
		p2.setX(p2.getX() + delta_x);
		p2.setY(p2.getY() + delta_y);
		p3.setX(p3.getX() + delta_x);
		p3.setY(p3.getY() + delta_y);
		p4.setX(p4.getX() + delta_x);
		p4.setY(p4.getY() + delta_y);
	}
	double getPerimeter() {
		return 2 * (width + height);
	}
	double getArea() {
		return width * height;
	}
	void printInfo() {
		cout << "p1: (" << p1.getX() << ", " << p1.getY() << ")" << endl;
		cout << "p2: (" << p2.getX() << ", " << p2.getY() << ")" << endl;
		cout << "p3: (" << p3.getX() << ", " << p3.getY() << ")" << endl;
		cout << "p4: (" << p4.getX() << ", " << p4.getY() << ")" << endl;
		cout << "Высота: " << height << endl;
		cout << "Ширина: " << width << endl;
		cout << "Периметр: " << getPerimeter() << endl;
		cout << "Площадь: " << getArea() << endl << endl;
	}
	Rectangle(double height, double width) {
		// Конструктор создания по длине и ширине
		if (setHeight(height) && setWidth(width)) {
			Point tp1, tp2, tp3, tp4;
			tp1.setX(0);
			tp1.setY(height);

			tp2.setX(width);
			tp2.setY(height);

			tp3.setX(height);
			tp3.setY(0);

			setP1(tp1);
			setP2(tp2);
			setP3(tp3);
			setP4(tp4);
		}
	}
	Rectangle(Point lh, Point rb) {
		Point tp2, tp4;
		//Создание по левой верхней и правой нижней координате
		tp2.setX(rb.getX());
		tp2.setY(lh.getY());

		tp4.setX(lh.getX());
		tp4.setY(rb.getY());

		setP1(lh);
		setP3(rb);
		setP2(tp2);
		setP4(tp4);
		double h = Point::getR(lh, tp4);
		double w = Point::getR(lh, tp2);
		setHeight(h);
		setWidth(w);
	}
	Rectangle(Point lh, double height, double width) {
		// Создание по левой верхней точке и длине и ширине
		if (setHeight(height) && setWidth(width)) {
			setP1(lh);
			Point tp2, tp3, tp4;
			tp2.setX(width + lh.getX());
			tp2.setY(lh.getY());

			tp3.setX(tp2.getX());
			tp3.setY(lh.getY() - height);

			tp4.setX(lh.getX());
			tp4.setY(tp3.getY());

			setP2(tp2);
			setP3(tp3);
			setP4(tp4);
		}
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	
	Rectangle r(Point(1, 1), 5, 10); // левая точка + длина ширина
	cout << "Исходный прямоугольник:" << endl;
	r.printInfo();
	cout << "Прямоугольник после изменения высоты:" << endl;
	r.setNewHeight(7);
	r.printInfo();
	cout << "Прямоугольник после изменения ширины:" << endl;
	r.setNewWidth(15);
	r.printInfo();
	cout << "Прямоугольник после изменения координаты p1:" << endl;
	r.setCenter(Point(2, 3));
	r.printInfo();

	Rectangle e(6, 11); // длина ширина
	cout << "Исходный прямоугольник:" << endl;
	e.printInfo();
	cout << "Прямоугольник после изменения высоты:" << endl;
	e.setNewHeight(3);
	e.printInfo();
	cout << "Прямоугольник после изменения ширины:" << endl;
	e.setNewWidth(9);
	e.printInfo();
	cout << "Прямоугольник после изменения координаты p1:" << endl;
	e.setCenter(Point(4, 0));
	e.printInfo();

	Rectangle f(Point(8, 8), Point(3,3)); // левая верхняя + нижняя правая
	cout << "Исходный прямоугольник:" << endl;
	f.printInfo();
	cout << "Прямоугольник после изменения высоты:" << endl;
	f.setNewHeight(10);
	f.printInfo();
	cout << "Прямоугольник после изменения ширины:" << endl;
	f.setNewWidth(6);
	f.printInfo();
	cout << "Прямоугольник после изменения координаты p1:" << endl;
	f.setCenter(Point(-4, 0));
	f.printInfo();
}
