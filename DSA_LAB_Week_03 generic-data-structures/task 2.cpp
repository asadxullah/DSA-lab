#include<iostream>
#include<string>
using namespace std;

class Employee {
public:
	virtual void calculateSalary() = 0;
};

class FullTimeEmployee : public Employee {
private:
	int fixedSalary=60000;
	int id;
	string name;

public:
	FullTimeEmployee(int id, string name) {
		this->id = id;
		this->name = name;
	}

	void calculateSalary() override {
		cout << "Salary of fulltime worker" << name << " is " << fixedSalary << endl;
	}
};


class PartTimeEmployee : public Employee {
private:
	int hoursWorked;
	int id;
	string name;
	int hourlyRate;

public:
	PartTimeEmployee(int hours, int id,string name,int rate) {
		hoursWorked = hours;
		this->id = id;
		this->name = name;
		hourlyRate = rate;

	}

	void calculateSalary() override {
		cout << "Salary of Parttime worker" << name << " is " << hourlyRate*hoursWorked << endl;
	}

};

int main() {
	FullTimeEmployee obj3(101, "asad");
	PartTimeEmployee obj4(40, 206, "ali", 20);

	obj3.calculateSalary();
	obj4.calculateSalary();

}