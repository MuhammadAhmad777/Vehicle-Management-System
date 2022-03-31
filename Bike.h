#pragma once
#include "Vehicle.h"
char* regrow(char*pArr, int &size);
class Bike :public Vehicle
{
	double height;
	bool selfStart;
	bool discBrake;
	static int numberOfBikes;
public:
	Bike(char* name = nullptr, char*col = nullptr, int no = 0, int power = 0, double hei = 0.0, bool self = false, bool brake = false);
	Bike(const Bike&B);
	Bike&operator=(const Bike&B);

	void setHeight(double h);
	void setSelfStart(bool start);
	void setDiscBrake(bool brake);
	double getHeight()const;
	bool getSelfStart()const;
	bool getDiscBrake()const;
	static int getNumberOfBikes();
	void checkType();
	void display()const;
	~Bike();
};
istream&operator>>(istream&inn, Bike&ob);
ifstream&operator>>(ifstream&inp, Bike&ob);
ostream&operator<<(ostream&out, Bike&ob);
ofstream&operator<<(ofstream&outp, Bike&ob);

