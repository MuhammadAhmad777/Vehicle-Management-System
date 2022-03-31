#include "Bike.h"
int Bike::numberOfBikes = 0;
Bike::Bike(char* name, char*col, int no, int power, double hei, bool self, bool brake) :Vehicle(name, col, no, power)
{
	if (hei > 0.0)
	{
		height = hei;
	}
	else
	{
		height = 0.0;
	}
	selfStart = self;
	discBrake = brake;
	
	numberOfBikes++;
}

Bike::Bike(const Bike&B) :Vehicle(B)
{
	height = B.height;
	selfStart = B.selfStart;
	discBrake = B.discBrake;
	numberOfBikes++;
}
Bike& Bike::operator=(const Bike&B)
{
	if (this != &B)
	{
		Vehicle::operator=(B);
		height = B.height;
		selfStart = B.selfStart;
		discBrake = B.discBrake;
	}
	return *this;
}
void Bike::setHeight(double h)
{
	height = h;
}
void Bike::setSelfStart(bool start)
{
	selfStart = start;
}
void Bike::setDiscBrake(bool brake)
{
	discBrake = brake;
}
double Bike::getHeight()const
{
	return height;
}
bool Bike::getSelfStart()const
{
	return selfStart;
}
bool Bike::getDiscBrake()const
{
	return discBrake;
}
void Bike::checkType()
{
	if (this->getNumberOfWheels() == 2)
	{
		this->setTypeOfVehicle("Bike");
	}
}

void Bike::display()const
{
	int s = 0;
	cout << "Company     Color       Wheels    Power    Type     Height    SelfStart   DiscBrake\n";
	if (this->getCompanyName() != nullptr)
	{
		 s = strlen(this->getCompanyName());
		cout << this->getCompanyName() ;
		if (s < 12)
		{
			for (int sp = 0; sp <12-s ; sp++)
			{
				cout << " ";
			}
		}
		else
		{
			cout << " ";
		}
	}
	else
	{
		cout << "Emtpy";
		cout << "       ";
	}
	if (this->getColor() != nullptr)
	{
		cout << this->getColor();
		s = strlen(this->getColor());
		if (s < 12)
		{
			for (int sp = 0; sp <12 - s; sp++)
			{
				cout << " ";
			}
		}
		else
		{
			cout << " ";
		}
	}
	else
	{
		cout << "Empty";
		cout << "       ";
	}
	cout << this->getNumberOfWheels();
	for (int sp = 0; sp <10; sp++)
	{
		cout << " ";
	}
	cout<< this->getPowerCC();
	for (int sp = 0; sp <6; sp++)
	{
		cout << " ";
	}
	if (getTypeOfVehicle() != nullptr)
	{
		s = strlen(getTypeOfVehicle());
		cout << getTypeOfVehicle();
		if (s < 10)
		{
			for (int sp = 0; sp <10 - s; sp++)
			{
				cout << " ";
			}
		}
		else
		{
			cout << " ";
		}
	}
	else
	{
		cout << "Empty";
		cout << "    ";
	}
	cout << height; 
	for (int sp = 0; sp <7; sp++)
	{
		cout << " ";
	}
	if (selfStart)
	{
		cout << "Yes";
		for (int sp = 0; sp <9; sp++)
		{
			cout << " ";
		}
	}
	else
	{
		cout << "No";
		for (int sp = 0; sp <10; sp++)
		{
			cout << " ";
		}
	}
	if (discBrake)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
}

int Bike::getNumberOfBikes()
{
	return numberOfBikes;
}
Bike::~Bike()
{
	--numberOfBikes;
}

istream&operator>>(istream&inn, Bike&ob)
{
	char* company = nullptr;
	char*col = nullptr;
	int number;
	int CC;
	double h;
	bool selfst;
	bool disc;
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
	cout << "Enter height: ";
	inn >> h;
	int s3 = 0;
	char *opt = new char[s3];
	i = 0;
	inn.ignore();
	cout << "tell about Self start. (write true for true else write false or any word to false)\nWrite:";
	do
	{
		opt = regrow(opt, s3);
		inn.get(opt[i]);
		i++;
	} while (opt[i - 1] != '\n');
	opt[i - 1] = '\0';
	if (strcmp(opt, "true") == 0)
	{
		selfst = true;
	}
	else
	{
		selfst = false;
	}
	delete[]opt;
	opt = nullptr;
	s3 = 0;
	i = 0;
	opt = new char[s3];
	cout << "tell about Disc Brake. (write true for true else write false or any word to false)\nWrite:";
	do
	{
		opt = regrow(opt, s3);
		inn.get(opt[i]);
		i++;
	} while (opt[i - 1] != '\n');
	opt[i - 1] = '\0';
	if (strcmp(opt, "true") == 0)
	{
		disc = true;
	}
	else
	{
		disc = false;
	}
	delete[]opt;
	opt = nullptr;
	ob.setCompanyName(company);
	ob.setColor(col);
	ob.setNumberOfWheels(number);
	ob.setPowerCC(CC);
	ob.setHeight(h);
	ob.setSelfStart(selfst);
	ob.setDiscBrake(disc);
	ob.checkType();
	delete[]company;
	company = nullptr;
	delete[]col;
	col = nullptr;
	return inn;
}

ifstream&operator>>(ifstream& inp, Bike&ob)
{
	char* company = nullptr;
	char*col = nullptr;
	int number;
	int CC;
	double h;
	bool selfst;
	bool disc;
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
	inp >> h;
	int s3 = 0;
	char *opt = new char[s3];
	i = 0;
	inp.ignore();
	do
	{
		opt = regrow(opt, s3);
		inp.get(opt[i]);
		i++;
	} while (opt[i - 1] != '\n');
	opt[i - 1] = '\0';
	if (strcmp(opt, "true") == 0)
	{
		selfst = true;
	}
	else
	{
		selfst = false;
	}
	delete[]opt;
	opt = nullptr;
	s3 = 0;
	i = 0;
	opt = new char[s3];
	do
	{
		opt = regrow(opt, s3);
		inp.get(opt[i]);
		i++;
	} while (opt[i - 1] != '\n');
	opt[i - 1] = '\0';
	if (strcmp(opt, "true") == 0)
	{
		disc = true;
	}
	else
	{
		disc = false;
	}
	delete[]opt;
	opt = nullptr;
	ob.setCompanyName(company);
	ob.setColor(col);
	ob.setNumberOfWheels(number);
	ob.setPowerCC(CC);
	ob.setHeight(h);
	ob.setSelfStart(selfst);
	ob.setDiscBrake(disc);
	ob.checkType();
	delete[]company;
	company = nullptr;
	delete[]col;
	col = nullptr;
	return inp;
}
ostream&operator<<(ostream&out, Bike&ob)
{
	out << "Company     Color       Wheels    Power    Type     Height    SelfStart   DiscBrake\n";
	char*company = nullptr;
	company = ob.getCompanyName();
	int s = 0;
	if (company)
	{
		out << company;
		s = strlen(company);
		if (s < 12)
		{
			for (int sp = 0; sp <12 - s; sp++)
			{
				out << " ";
			}
		}
		else
		{
			out << " ";
		}
	}
	else
	{
		out << "Empty";
		out << "     ";
	}
	char*col = nullptr;
	col = ob.getColor();
	if (col)
	{
		out << col;
		s = strlen(col);
		if (s < 12)
		{
			for (int sp = 0; sp <12 - s; sp++)
			{
				out << " ";
			}
		}
		else
		{
			out << " ";
		}
	}
	else
	{
		out << "Empty";
		out << "     ";
	}
	out << ob.getNumberOfWheels();
	for (int sp = 0; sp <9; sp++)
	{
		out << " ";
	}
	out << ob.getPowerCC();
	for (int sp = 0; sp <7; sp++)
	{
		out << " ";
	}
	ob.checkType();
	if (ob.getTypeOfVehicle())
	{
		out << ob.getTypeOfVehicle();
		s = strlen(ob.getTypeOfVehicle());
		if (s < 10)
		{
			for (int sp = 0; sp < 10 - s; sp++)
			{
				out << " ";
			}
		}
		else
		{
			out << " ";
		}
	}
	else
	{
		out << "Empty";
		out << "     ";
	}
	out << ob.getHeight();
	out << "       ";
	if (ob.getSelfStart() == true)
	{
		out << "Yes";
		for (int sp = 0; sp < 9; sp++)
		{
			out << " ";
		}
	}
	else
	{
		out << "No";
		for (int sp = 0; sp < 10; sp++)
		{
			out << " ";
		}
	}
	if (ob.getDiscBrake() == true)
	{
		out << "Yes";
	}
	else
	{
		out << "No";
	}
	out << "\n";
	return out;
}

ofstream&operator<<(ofstream&outp, Bike&ob)
{
	outp << "Company     Color       Wheels    Power    Type     Height    SelfStart   DiscBrake\n";
	char*company = nullptr;
	company = ob.getCompanyName();
	int s = 0;
	if (company)
	{
		outp << company;
		s = strlen(company);
		if (s < 12)
		{
			for (int sp = 0; sp <12 - s; sp++)
			{
				outp << " ";
			}
		}
		else
		{
			outp << " ";
		}
	}
	else
	{
		outp << "Empty";
		outp << "     ";
	}
	char*col = nullptr;
	col = ob.getColor();
	if (col)
	{
		outp << col;
		s = strlen(col);
		if (s < 12)
		{
			for (int sp = 0; sp <12 - s; sp++)
			{
				outp << " ";
			}
		}
		else
		{
			outp << " ";
		}
	}
	else
	{
		outp << "Empty";
		outp << "       ";
	}
	outp << ob.getNumberOfWheels();
	for (int sp = 0; sp <9; sp++)
	{
		outp << " ";
	}
	outp << ob.getPowerCC();
	for (int sp = 0; sp <7; sp++)
	{
		outp << " ";
	}
	ob.checkType();
	if (ob.getTypeOfVehicle())
	{
		outp << ob.getTypeOfVehicle();
		s = strlen(ob.getTypeOfVehicle());
		if (s < 10)
		{
			for (int sp = 0; sp < 10 - s; sp++)
			{
				outp << " ";
			}
		}
		else
		{
			outp << " ";
		}
	}
	else
	{
		outp << "Empty";
		for (int sp = 0; sp < 5; sp++)
		{
			outp << " ";
		}
	}
	outp << ob.getHeight();
	outp << "       ";
	if (ob.getSelfStart() == true)
	{
		outp << "Yes";
		for (int sp = 0; sp < 9; sp++)
		{
			outp << " ";
		}
	}
	else
	{
		outp << "No";
		for (int sp = 0; sp <10; sp++)
		{
			outp << " ";
		}
	}
	if (ob.getDiscBrake() == true)
	{
		outp << "Yes";
	}
	else
	{
		outp << "No";
	}
	outp << "\n";
	return outp;
}
