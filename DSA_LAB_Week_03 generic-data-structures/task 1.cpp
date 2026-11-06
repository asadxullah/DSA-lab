#include<iostream>
using namespace std;

class Course {
public:
	virtual void duration() = 0;

};

class OnlineCourse : public Course {
private:
	int weeks;
	int hoursPerWeek;

public:

	OnlineCourse(int weeks, int hoursPerWeek) {
		this->weeks = weeks;
		this->hoursPerWeek = hoursPerWeek;

	}

	int area() {
		return weeks * hoursPerWeek;
	}

	void duration() override {
		cout << "The duration of online classes is " << area() << endl;
	}

};

class OfflineCourse : public Course {
private:
	int months;
	int hoursPerDay;

public:
	
	OfflineCourse(int months, int hoursPerDay) {
		this->months = months;
		this->hoursPerDay = hoursPerDay;

	}

	int area() {
		return months * hoursPerDay;
	}

	void duration() override {
		cout << "The duration of offline classes is " << area() << endl;
	}

};

int main() {

	OnlineCourse obj1(5,8);
	OfflineCourse obj2(8, 8);
	obj1.duration();
	obj2.duration();

}