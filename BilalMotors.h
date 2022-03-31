#pragma once
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include "Truck.h"
Vehicle** regrow(Vehicle**prevArr, int& count, Vehicle*insert);
class BilalMotors
{
	Vehicle**list;
	int count;
public:
	BilalMotors();
	BilalMotors(const BilalMotors&);
	void addVehicle(Vehicle *);
	void searchVehicle(char*);
	bool saveData(const char* fileName) const;
	int getCount()const;
	Vehicle* operator[](int in);
	const Vehicle* operator[](int in)const;
	~BilalMotors();
};
void ShowVehicles(const BilalMotors &ob);