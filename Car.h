#pragma once
#include "Vehicle.h"
char* regrow(char*pArr, int &size);
char*deepConcept(char*pArr);

class Car:public Vehicle
{
	int noOfDoors;
	char*trasmission;
	int noOfSeats;
	static int numberOfCars;
public:
	Car(char* name = nullptr, char*col = nullptr, int wheelno = 0, int power = 0, int doors = 0, char*trans = nullptr, int seats = 0);
	Car(const Car&ob);
	Car&operator=(const Car&ob);
	void setNoOfDoors(int doors);
	void setTrasmission(char*t);
	void setNoOfSeats(int n);
	int getNoOfDoors()const;
	char* getTramission()const;
	int getNoOfSeats()const;
	static int getNumberOfCars();
	void checkType();
	void display()const;
	~Car();
};
istream&operator>>(istream&inn, Car&ob);
ifstream&operator>>(ifstream&inp, Car&ob);
ostream&operator<<(ostream&out, Car&ob);
ofstream&operator<<(ofstream&outp, Car&ob);