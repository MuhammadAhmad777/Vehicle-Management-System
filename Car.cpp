#include "Car.h"

int Car::numberOfCars = 0;
Car::Car(char* name, char*col, int wheelno, int power, int doors, char*trans, int seats) :Vehicle(name, col, wheelno, power)
{
	if (doors > 0)
	{
		noOfDoors = doors;
	}
	else
	{
		noOfDoors = 0;
	}
	trasmission = deepConcept(trans);
	if (seats > 0)
	{
		noOfSeats = seats;
	}
	else
	{
		noOfSeats = 0;
	}
	++numberOfCars;
}
Car::Car(const Car&ob) :Vehicle(ob)
{
	noOfDoors = ob.noOfDoors;
	trasmission = deepConcept(ob.trasmission);
	noOfSeats = ob.noOfSeats;
	++numberOfCars;
}
Car& Car::operator=(const Car&ob)
{
	if (this != &ob)
	{
		Vehicle::operator=(ob);
		noOfDoors = ob.noOfDoors;
		if (trasmission)
		{
			delete[]trasmission;
			trasmission = nullptr;
		}
		trasmission = deepConcept(ob.trasmission);
		noOfSeats = ob.noOfSeats;
	}
	return *this;
}

void Car::setNoOfDoors(int doors)
{
	if (doors > 0)
	{
		noOfDoors = doors;
	}
	else
	{
		noOfDoors = 0;
	}
}
void Car::setTrasmission(char*t)
{
	if (trasmission)
	{
		delete[]trasmission;
		trasmission = nullptr;
	}
	trasmission = deepConcept(t);
}
void Car::setNoOfSeats(int n)
{
	if (n > 0)
	{
		noOfSeats = n;
	}
	else
	{
		noOfSeats = 0;
	}
}

int Car::getNoOfDoors()const
{
	return noOfDoors;
}

char* Car::getTramission()const
{
	char*t = deepConcept(trasmission);
	return t;
}
int Car::getNoOfSeats()const
{
	return noOfSeats;
}
int Car::getNumberOfCars()
{
	return numberOfCars;
}
void Car::checkType()
{
	if (this->getNumberOfWheels() == 4)
	{
		this->setTypeOfVehicle("Car");
	}
}
void Car::display()const
{
	cout << "Company     Color       Wheels   Power    Type       Doors     Trasmission    Seats\n";
	int s = 0;
	if (this->getCompanyName() != nullptr)
	{
		cout << this->getCompanyName() ;
		s = strlen(this->getCompanyName());
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				cout << " ";
			}
		}
	}
	else
	{
		cout << "Emtpy       ";
	}
	if (this->getColor() != nullptr)
	{
		cout << this->getColor();
		s = strlen(this->getColor());
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				cout << " ";
			}
		}
		else
		{
			cout << "  ";
		}
	}
	else
	{
		cout << "Empty       ";
	}
	cout << this->getNumberOfWheels() << "        " << this->getPowerCC()<<"      ";
	char*t = getTypeOfVehicle();
	if (t)
	{
		cout << t;
		s = strlen(t);
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				cout << " ";
			}
		}
		else
		{
			cout << "  ";
		}
	}
	else
	{
		cout << "Empty       ";
	}
	delete[]t;
	t = nullptr;
	cout << noOfDoors<<"         ";
	if (trasmission)
	{
		cout << trasmission;
		s = strlen(trasmission);
		if (s < 15)
		{
			for (int sp = 0; sp < 15 - s; sp++)
			{
				cout << " ";
			}
		}
	}
	else
	{
		cout << "Empty          ";
	}
	cout <<noOfSeats << endl;
}
Car::~Car()
{
	if (trasmission)
	{
		delete[]trasmission;
		trasmission = nullptr;
	}
	--numberOfCars;
}

istream&operator>>(istream&inn, Car&ob)
{
	char* company = nullptr;
	char*col = nullptr;
	int number;
	int CC;
	int doorsNum;
	char*tras=nullptr;
	int seatsNum;
	int size1 = 0;
	company = new char[size1];
	int i = 0;
	cout << "Enter Company Name: ";
	do
	{
		company = regrow(company, size1);
		inn.get(company[i]);
		i++;
	} while (company[i - 1] != '\n');
	company[i - 1] = '\0';
	cout << "Enter Color: ";
	int size2 = 0;
	col = new char[size2];
	i = 0;
	do
	{
		col = regrow(col, size2);
		inn.get(col[i]);
		i++;
	} while (col[i - 1] != '\n');
	col[i - 1] = '\0';
	cout << "Enter Number of wheels: ";
	inn >> number;
	cout << "Enter PowerCC: ";
	inn >> CC;
	cout << "Enter  no of doors: ";
	inn >>doorsNum;
	int s3 = 0;
	i = 0;
	inn.ignore();
	cout << "Enter trasmission:";
	tras = new char[s3];
	do
	{
		tras = regrow(tras, s3);
		inn.get(tras[i]);
		i++;
	} while (tras[i - 1] != '\n');
	
	tras[i - 1] = '\0';
	cout << "Enter number of seats:";
	inn >> seatsNum;
	ob.setCompanyName(company);
	ob.setColor(col);
	ob.setNumberOfWheels(number);
	ob.setPowerCC(CC);
	ob.setNoOfDoors(doorsNum);
	ob.setTrasmission(tras);
	ob.setNoOfSeats(seatsNum);
	ob.checkType();
	delete[]company;
	company = nullptr;
	delete[]col;
	col = nullptr;
	if (tras)
	{
		delete[]tras;
		tras = nullptr;
	}
	inn.ignore();
	return inn;
}

ifstream&operator>>(ifstream&inp, Car&ob)
{
	char* company = nullptr;
	char*col = nullptr;
	int number;
	int CC;
	int doorsNum;
	char*tras = nullptr;
	int seatsNum;
	int size1 = 0;
	company = new char[size1];
	int i = 0;
	do
	{
		company = regrow(company, size1);
		inp.get(company[i]);
		i++;
	} while (company[i - 1] != '\n');
	company[i - 1] = '\0';
	int size2 = 0;
	col = new char[size2];
	i = 0;
	do
	{
		col = regrow(col, size2);
		inp.get(col[i]);
		i++;
	} while (col[i - 1] != '\n');
	col[i - 1] = '\0';
	inp >> number;
	inp >> CC;
	inp >> doorsNum;
	int s3 = 0;
	i = 0;
	inp.ignore();
	tras = new char[s3];
	do
	{
		tras = regrow(tras, s3);
		inp.get(tras[i]);
		i++;
	} while (tras[i - 1] != '\n');

	tras[i - 1] = '\0';
	inp >> seatsNum;
	ob.setCompanyName(company);
	ob.setColor(col);
	ob.setNumberOfWheels(number);
	ob.setPowerCC(CC);
	ob.setNoOfDoors(doorsNum);
	ob.setTrasmission(tras);
	ob.setNoOfSeats(seatsNum);
	ob.checkType();
	delete[]company;
	company = nullptr;
	delete[]col;
	col = nullptr;
	if (tras)
	{
		delete[]tras;
		tras = nullptr;
	}
	inp.ignore();
	return inp;
}
ostream&operator<<(ostream&out, Car&ob)
{
	char*company = nullptr;
	company = ob.getCompanyName();
	out << "Company     Color       Wheels   Power    Type       Doors     Trasmission    Seats\n";
	int s = 0;
	if (company)
	{
		out << company;
		s = strlen(company);
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				out << " ";
			}
		}
		delete[]company;
		company = nullptr;
	}
	else
	{
		out << "Empty       ";
	}
	char*col = nullptr;
	col = ob.getColor();
	if (col)
	{
		out << col ;
		s = strlen(col);
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				out << " ";
			}
		}
		else
		{
			out << "  ";
		}
		delete[]col;
		col = nullptr;
	}
	else
	{
		out << "Empty       ";
	}
	out << ob.getNumberOfWheels() << "        ";
	out << ob.getPowerCC() << "        ";
	ob.checkType();
	char*tt = ob.getTypeOfVehicle();
	if (tt)
	{
		out << tt;
		s = strlen(tt);
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				out << " ";
			}
		}
		else
		{
			out << "  ";
		}
	}
	else
	{
		out << "Empty       ";
	}
	delete[]tt;
	tt = nullptr;
	out << ob.getNoOfDoors()<<"      ";
	char*tras = ob.getTramission();
	if (tras)
	{
		out << tras;
		s = strlen(tras);
		if (s < 15)
		{
			for (int sp = 0; sp < 15 - s; sp++)
			{
				out << " ";
			}
			
		}
		else
		{
			out << "  ";
		}
		delete[]tras;
		tras = nullptr;
	}
	else
	{
		out << "Empty          ";
	}
	out << ob.getNoOfSeats() << "\n";
	return out;
}
ofstream&operator<<(ofstream&outp, Car&ob)
{
	char*company = nullptr;
	company = ob.getCompanyName();
	outp << "Company     Color       Wheels   Power    Type       Doors     Trasmission    Seats\n";
	int s = 0;
	if (company)
	{
		outp << company;
		s = strlen(company);
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				outp << " ";
			}
		}
		delete[]company;
		company = nullptr;
	}
	else
	{
		outp << "Empty       ";
	}
	char*col = nullptr;
	col = ob.getColor();
	if (col)
	{
		outp << col;
		s = strlen(col);
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				outp << " ";
			}
			delete[]col;
			col = nullptr;
		}
		else
		{
			outp << "  ";
		}
	}
	else
	{
		outp << "Empty       ";
	}
	outp << ob.getNumberOfWheels() << "        ";
	outp << ob.getPowerCC() << "        ";
	ob.checkType();
	char*tt = ob.getTypeOfVehicle();
	if (tt)
	{
		outp << tt;
		s = strlen(tt);
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				outp << " ";
			}
		}
		else
		{
			outp << "  ";
		}
	}
	else
	{
		outp << "Empty       ";
	}
	delete[]tt;
	tt = nullptr;
	outp << ob.getNoOfDoors() << "      ";
	char*tras = ob.getTramission();
	if (tras)
	{
		outp << tras;
		s = strlen(tras);
		if (s < 15)
		{
			for (int sp = 0; sp < 15 - s; sp++)
			{
				outp << " ";
			}
		}
		else
		{
			outp << "  ";
		}
		delete[]tras;
		tras = nullptr;
	}
	else
	{
		outp << "Empty          ";
	}
	outp << ob.getNoOfSeats() << "\n";
	return outp;
}