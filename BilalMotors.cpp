#include"BilalMotors.h"

BilalMotors::BilalMotors()
{
	count = 0;
	//list = new Vehicle*[count];
	list = nullptr;
}
BilalMotors::BilalMotors(const BilalMotors&obj)
{
	this->count = obj.count;
	this->list = obj.list;
}
void BilalMotors::addVehicle(Vehicle *arr)
{
	list = regrow(list, count,arr);//it regrows previous array and insert /add vehicle then increase count
}
void BilalMotors::searchVehicle(char*ty)
{
	if (list&&count>0)
	{
		for (int i = 0; i < count; i++)
		{
			list[i]->checkType();
			if (strcmp(list[i]->getTypeOfVehicle(), ty) == 0)
			{
				list[i]->display();
			}
		}
	}
}

bool BilalMotors::saveData(const char* fileName) const
{
	int s = strlen(fileName);
	char*n = new char[s+5];
	for (int cp = 0; cp < s; cp++)
	{
		n[cp] = fileName[cp];
	}
	n[s] = '\0';
	strcat(n,".txt");//extension
	ofstream fout;
	fout.open(n);
	if (fout)
	{
		fout << "Vehicle Information\n";
		fout << "---------------------\n";
		fout << "Number of Bikes : "<<Bike::getNumberOfBikes()<<endl;
		fout << "Number of Cars : " << Car::getNumberOfCars() << endl;
		fout << "Number of Trucks : "<<Truck::getNumberOfTrucks()<<endl;
		fout << "CompanyName\t\t\t\tType\t\t\tColor\tPower\n";
		fout << "----------------------------------------------------------------------\n";
		if (list&&count>0)
		{
			int tempSize=0;
			int space = 0;
			for (int ind = 0; ind < count; ind++)
			{
				list[ind]->checkType();
				fout << list[ind]->getCompanyName();
				tempSize =strlen( list[ind]->getCompanyName());
				if (tempSize < 24)
				{
					space=24-tempSize;//actually by file ,in this case we can write maximum 24 characters before writting Color to follow pattern.
					//so 24-No of printed characters=required space
				}
				else
				{
					space = 1;
				}
				for (int noOfSpaces = 0; noOfSpaces< space; noOfSpaces++)
				{
					fout << " ";
				}
				fout << list[ind]->getTypeOfVehicle();
				tempSize = strlen(list[ind]->getTypeOfVehicle());
				if (tempSize < 16)
				{
					//from start printing TypeOfVehicle to print Color ,there were 16 total characters space/places
					//so adjusted number space with the same logic I have adjusted above
					space = 16 - tempSize;
				}
				else
				{
					space = 1;
				}
				for (int noOfSpaces = 0; noOfSpaces< space; noOfSpaces++)
				{
					fout << " ";
				}
				fout << list[ind]->getColor();
				
				tempSize = strlen(list[ind]->getColor());
				if (tempSize < 8)
				{
					//in this case we can write maximum 8 characters before writting PowerCC to follow pattern.
					space = 8 - tempSize;
				}
				else
				{
					space = 1;
				}
				for (int noOfSpaces = 0; noOfSpaces< space; noOfSpaces++)
				{
					fout << " ";
				}
				fout<< list[ind]->getPowerCC() << "\n";
			}
		}
		fout.close();
		return true;
	}
	else
	{
		return false;
	}
}
int BilalMotors::getCount()const
{
	return count;
}
Vehicle* BilalMotors::operator[](int in)
{
	if (in > 0&&in<count)
	{
		return list[in];
	}
	else
	{
		return list[0];
	}
}
const Vehicle* BilalMotors::operator[](int in)const
{
	if (in > 0 && in<count)
	{
		return list[in];
	}
	else
	{
		return list[0];
	}
}
BilalMotors::~BilalMotors()
{
	if (list)
	{
		delete[]list;
		list = nullptr;
	}
}
void ShowVehicles(const BilalMotors &ob)
{
	cout << "                  Number of Total Vehicles: ";
	cout << ob.getCount() << endl;
	int s1 = ob.getCount();
	cout << "--------------------------------------------------------------------\n";
	for (int in = 0; in < s1; in++)
	{
		ob[in]->display();
		cout << "--------------------------------------------------------------------\n";
	}
}

