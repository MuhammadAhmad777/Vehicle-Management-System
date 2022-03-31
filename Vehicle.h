#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

char*deepConcept(char*pArr);
class Vehicle
{
	char* companyName;
	char*color;
	int numberOfWheels;
	int powerCC;
	char*typeOfVehicle;
public:
	//constructor
	Vehicle(char* name = nullptr, char*col = nullptr, int no = 0, int power = 0, char*type = nullptr);
	//copy constructor
	Vehicle(const Vehicle&ob);
	//assignment Operator
	Vehicle&operator=(const Vehicle&ob);
	//setters
	void setCompanyName(char*name);
	void setColor(char*col);
	void setNumberOfWheels(int no);
	void setPowerCC(int power);
	void setTypeOfVehicle(char*type);
	//getters
	char* getCompanyName()const;
	char* getColor()const;
	int getNumberOfWheels()const;
	int getPowerCC()const;
	char* getTypeOfVehicle()const;
	//This function should be responsible to determine the type of vehicle, but you are not
	//allowed to define it in this Class
	virtual void checkType() = 0;
	//This function display() will only print the attributes. 
	virtual void display()const;
	virtual ~Vehicle();
};