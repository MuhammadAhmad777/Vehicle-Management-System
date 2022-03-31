#pragma once
#include "Vehicle.h"
char* regrow(char*pArr, int &size);
char*deepConcept(char*pArr);
class Truck :public Vehicle
{
	double containerSize;
	char* category;
	bool fourWheelDrive;
	static int numberOfTrucks;
public:
	Truck(char* name = nullptr, char*col = nullptr, int wheelno = 0, int power = 0, double cont = 0.0, char*cat = nullptr, bool fourwheel = false);
	Truck(const Truck&ob);
	Truck&operator=(const Truck&ob);
	void setContainerSize(double size);
	void setCategory(char*categ);
	void setFourWheelDrive(bool fourWheel);
	double getContainerSize()const;
	char* getCategory()const;
	bool getFourWheelDrive()const;
	static int getNumberOfTrucks();
	void checkType();
	void display()const;
	~Truck();
};
istream&operator>>(istream&inn, Truck&ob);
ifstream&operator>>(ifstream&inp, Truck&ob);
ostream&operator<<(ostream&out, Truck&ob);
ofstream&operator<<(ofstream&outp, Truck&ob);