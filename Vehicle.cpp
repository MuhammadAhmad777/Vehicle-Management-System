#include "Vehicle.h"


Vehicle::Vehicle(char* name, char*col, int no, int power, char*type)
{
	companyName = deepConcept(name);
	color = deepConcept(col);
	if (no > 0)
	{
		numberOfWheels = no;
	}
	else
	{
		numberOfWheels = 0;
	}
	if (power > 0)
	{
		powerCC = power;
	}
	else
	{
		powerCC = 0;
	}
	typeOfVehicle = deepConcept(type);
}

Vehicle::Vehicle(const Vehicle&ob)
{
	this->companyName = deepConcept(ob.companyName);
	this->color = deepConcept(ob.color);
	this->numberOfWheels = ob.numberOfWheels;
	this->powerCC = ob.powerCC;
	this->typeOfVehicle = deepConcept(ob.typeOfVehicle);
}

Vehicle&Vehicle::operator=(const Vehicle&ob)
{
	if (this != &ob)
	{
		if (companyName)
		{
			delete[]companyName;
			companyName = nullptr;
		}
		companyName = deepConcept(ob.companyName);

		if (color)
		{
			delete[]color;
			color = nullptr;
		}
		color = deepConcept(ob.color);
		numberOfWheels = ob.numberOfWheels;
		powerCC = ob.powerCC;

		if (typeOfVehicle)
		{
			delete[]typeOfVehicle;
			typeOfVehicle = nullptr;
		}
		typeOfVehicle = deepConcept(ob.typeOfVehicle);
	}
	return *this;
}

void Vehicle::setCompanyName(char*name)
{
	if (companyName)
	{
		delete[]companyName;
		companyName = nullptr;
	}
	companyName = deepConcept(name);
}

void Vehicle::setColor(char*col)
{
	if (color)
	{
		delete[]color;
		color = nullptr;
	}
	color = deepConcept(col);
}
void Vehicle::setNumberOfWheels(int no)
{
	if (no >= 0)
	{
		numberOfWheels = no;
	}
	else
	{
		numberOfWheels = 0;
	}
}
void Vehicle::setPowerCC(int power)
{
	if (power >= 0)
	{
		powerCC = power;
	}
	else
	{
		powerCC = 0;
	}
}
void Vehicle::setTypeOfVehicle(char*type)
{
	if (typeOfVehicle)
	{
		delete[]typeOfVehicle;
		typeOfVehicle = nullptr;
	}
	typeOfVehicle = deepConcept(type);
}
char* Vehicle::getCompanyName()const
{
	char*tempr = deepConcept(companyName);
	return tempr;
}
char* Vehicle::getColor()const
{
	char*tempr = deepConcept(color);
	return tempr;
}
int Vehicle::getNumberOfWheels()const
{
	return numberOfWheels;
}
int Vehicle::getPowerCC()const
{
	return powerCC;
}
char* Vehicle::getTypeOfVehicle()const
{
	char*tempr = deepConcept(typeOfVehicle);
	return tempr;
}
void Vehicle::display()const
{
	cout << "Company\tColor\tWheels\tPower\tType\n";
	if (companyName)
	{
		cout << companyName<<"\t";
	}
	else
	{
		cout << "Emtpy"<<"\t";
	}
	if (color)
	{
		cout << color<<"\t";
	}
	else
	{
		cout << "Empty"<<"\t";
	}
	cout << numberOfWheels << "\t" << powerCC << "\t";
	if (typeOfVehicle)
	{
		cout << typeOfVehicle << endl;
	}
	else
	{
		cout << "Empty\n";
	}
}
Vehicle::~Vehicle()
{
	if (companyName)
	{
		delete[]companyName;
		companyName = nullptr;
	}
	if (color)
	{
		delete[]color;
		color = nullptr;
	}
	if (typeOfVehicle)
	{
		delete[]typeOfVehicle;
		typeOfVehicle = nullptr;
	}
}
