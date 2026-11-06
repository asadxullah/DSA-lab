#include<iostream>
using namespace std;
class shape {
public:
	virtual void area() = 0;
};

class circle : public  shape {
private:
	double radius;
public:
	circle(double r) {
		radius = r;
	}
	void area()override {
		cout << "The area of circle is " << 3.1415 * (radius * radius) << endl;
 	}
};

class rectangle : public shape {
private:
	double length;
	double width;
public:
	rectangle(double l, double w) {
		length = l;
		width = w;
	}
	void area()override {
		cout << "The area of rectangle is " << length*width << endl;
	}
};

int main() {
	circle c1(4.5);
	c1.area();
	rectangle r1(5.5, 6.6);
	r1.area();
	return 0;
}