#include<iostream>
using namespace std;
class employee {
public:
	virtual void calculatesalary() = 0;
};

class fulltimeemployee : public employee {
public:
	void calculatesalary() override {
		cout << "Your salary as  an  Full time employee is : 100000 pkr" << endl;
	}
};

class parttimeemployee : public employee {
private:
	double hoursworked;
	double hourrate;
public:
	parttimeemployee(double hw ,double hr) {
		hoursworked = hw;
		hourrate = hr;
	}
	void calculatesalary() override {
		cout << "Your salary as a part time employee is : " << (hoursworked * hourrate) * 30 <<" pkr" << endl;
	}
};


int main() {
	fulltimeemployee f1;
	f1.calculatesalary();
	parttimeemployee p1(8,200);
	p1.calculatesalary();
}