#include<iostream>
using namespace std;
class course {
public:
	virtual double duration() = 0;
};

class onlinecourse : public course {
private:
	int hoursperday;
	int week;
public:
	onlinecourse(int hpd , int w) {
		hoursperday = hpd;
		week = w;
	}
	double duration() override {
		return week * hoursperday;
	}
};

class offlinecourse : public course {
private:
	int month;
	int hoursperday;
public:
	offlinecourse(int m, int hpd) {
		month = m;
		hoursperday = hpd;
	}
	double duration()override{
		return month * 30 * hoursperday;
	}
};

int main(){
	onlinecourse online(8, 3);
	cout << "Online course duration  : " << online.duration() << endl;

	offlinecourse offline(2, 4);
	cout << "Offline course duration  : " << offline.duration() << endl;
	return 0;
}