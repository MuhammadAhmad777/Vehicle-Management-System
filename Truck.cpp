#include "Truck.h"

int Truck::numberOfTrucks = 0;
Truck::Truck(char* name, char*col, int wheelno, int power, double cont, char*cat, bool fourwheel) :Vehicle(name, col, wheelno, power)
{
	if (cont > 0.0)
	{
		containerSize = cont;
	}
	else
	{
		containerSize = 0.0;
	}
	category = deepConcept(cat);
	fourWheelDrive = fourwheel;
	numberOfTrucks++;
}
Truck::Truck(const Truck&ob) :Vehicle(ob)
{
	containerSize = ob.containerSize;
	category = deepConcept(ob.category);
	fourWheelDrive = ob.fourWheelDrive;
}
Truck&Truck::operator=(const Truck&ob)
{
	if (this != &ob)
	{
		Vehicle::operator=(ob);
		containerSize = ob.containerSize;
		if (category)
		{
			delete[]category;
			category = nullptr;
		}
		category = deepConcept(ob.category);
		fourWheelDrive = ob.fourWheelDrive;
	}
	return *this;
}

void Truck::setContainerSize(double size)
{
	if (size> 0.0)
	{
		containerSize = size;
	}
	else
	{
		containerSize = 0.0;
	}
}
void Truck::setCategory(char*categ)
{
	if (category)
	{
		delete[]category;
		category = nullptr;
	}
	category = deepConcept(categ);
}
void Truck::setFourWheelDrive(bool fourWheel)
{
	fourWheelDrive = fourWheel;
}

double Truck::getContainerSize()const
{
	return containerSize;
}
char* Truck::getCategory()const
{
	char*tempCategory = deepConcept(category);
	return tempCategory;
}
bool Truck::getFourWheelDrive()const
{
	return fourWheelDrive;
}
int Truck::getNumberOfTrucks()
{
	return numberOfTrucks;
}
void Truck::checkType()
{
	if (this->getNumberOfWheels() == 6)
	{
		this->setTypeOfVehicle("Truck");
	}
}
void Truck::display()const
{
	int s = 0;
	cout << "Company      Color       Wheels   Power    Type      containerSize     Category       FourWheelDrive\n";
	if (this->getCompanyName() != nullptr)
	{
		cout << this->getCompanyName();
		s = strlen(this->getCompanyName());
		if (s < 13)
		{
			for (int sp = 0; sp < 13 - s; sp++)
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
			cout << " ";
		}
	}
	else
	{
		cout << "Empty       ";
	}
	cout <<  this->getNumberOfWheels() << "        " <<this->getPowerCC() << "      ";
	if (getTypeOfVehicle() != nullptr)
	{
		cout << getTypeOfVehicle();
		s = strlen(getTypeOfVehicle());
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
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
		cout << "Empty       ";
	}
	cout << containerSize << "             ";
	if (category)
	{
		cout << category;
		s = strlen(category);
		if (s < 16)
		{
			for (int sp = 0; sp < 16 - s; sp++)
			{
				cout<<" ";
			}
		}
	}
	else
	{
		cout << "Empty";
		for (int sp = 0; sp < 11; sp++)
		{
			cout << " ";
		}
	}
	if (fourWheelDrive == true)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
}
Truck::~Truck()
{
	--numberOfTrucks;
	if (category)
	{
		delete[]category;
		category = nullptr;
	}
}

istream&operator>>(istream&inn, Truck&ob)
{
	char* company = nullptr;
	char*col = nullptr;
	int number;
	int CC;
	double container;
	char* cate=nullptr;
	bool fourWheel;
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
	cout << "Enter container Size:";
	inn >> container;
	inn.ignore();
	cout << "Enter category:";
	int sc = 0;
	cate = new char[sc];
	i = 0;
	do
	{
		cate = regrow(cate, sc);
		inn.get(cate[i]);
		i++;
	} while (cate[i - 1] != '\n');
	cate[i - 1] = '\0';
	int s3 = 0;
	i = 0;
	char *opt = new char[s3];
	i = 0;
	cout << "tell about Four wheel drive. (write true for true else write false or any word to false)\nWrite:";
	do
	{
		opt = regrow(opt, s3);
		inn.get(opt[i]);
		i++;
	} while (opt[i - 1] != '\n');
	opt[i - 1] = '\0';
	if (strcmp(opt, "true") == 0)
	{
		 fourWheel= true;
	}
	else
	{
		fourWheel = false;
	}
	delete[]opt;
	opt = nullptr;
	ob.setCompanyName(company);
	ob.setColor(col);
	ob.setNumberOfWheels(number);
	ob.setPowerCC(CC);
	ob.setContainerSize(container);
	ob.setCategory(cate);
	ob.setFourWheelDrive(fourWheel);
	ob.checkType();
	delete[]company;
	company = nullptr;
	delete[]col;
	col = nullptr;
	return inn;
}


ifstream&operator>>(ifstream&inp, Truck&ob)
{
	char* company = nullptr;
	char*col = nullptr;
	int number;
	int CC;
	double container;
	char* cate = nullptr;
	bool fourWheel;
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
	inp >> container;
	inp.ignore();
	int sc = 0;
	cate = new char[sc];
	i = 0;
	do
	{
		cate = regrow(cate, sc);
		inp.get(cate[i]);
		i++;
	} while (cate[i - 1] != '\n');
	cate[i - 1] = '\0';
	int s3 = 0;
	i = 0;
	char *opt = new char[s3];
	i = 0;
	do
	{
		opt = regrow(opt, s3);
		inp.get(opt[i]);
		i++;
	} while (opt[i - 1] != '\n');
	opt[i - 1] = '\0';
	if (strcmp(opt, "true") == 0)
	{
		fourWheel = true;
	}
	else
	{
		fourWheel = false;
	}
	delete[]opt;
	opt = nullptr;
	ob.setCompanyName(company);
	ob.setColor(col);
	ob.setNumberOfWheels(number);
	ob.setPowerCC(CC);
	ob.setContainerSize(container);
	ob.setCategory(cate);
	ob.setFourWheelDrive(fourWheel);
	ob.checkType();
	delete[]company;
	company = nullptr;
	delete[]col;
	col = nullptr;
	return inp;
}


ostream&operator<<(ostream&out, Truck&ob)
{
	char*company = nullptr;
	company = ob.getCompanyName();
	out << "Company      Color       Wheels   Power    Type      containerSize     Category       FourWheelDrive\n";
	int s = 0;
	if (company)
	{
		out << company;
		s = strlen(company);
		if (s < 13)
		{
			for (int sp = 0; sp < 13 - s; sp++)
			{
				out << " ";
			}
		}
		else
		{
			out << "  ";
		}
		delete[]company;
		company = nullptr;
	}
	else
	{
		out << "Empty        ";
	}
	char*col = nullptr;
	col = ob.getColor();

	if (col)
	{
		out << col;
		s = strlen(col);
		if (s < 12)
		{
			for (int sp = 0; sp < 12 - s; sp++)
			{
				out << " ";
			}
		}
		delete[]col;
		col = nullptr;
	}
	else
	{
		out << "Empty       ";
	}
	out << ob.getNumberOfWheels() << "        ";
	out << ob.getPowerCC() << "      ";
	ob.checkType();
	char*t1 = ob.getTypeOfVehicle();
	if (t1)
	{
		out << t1;
		s = strlen(t1);
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
	delete[]t1;
	t1 = nullptr;
	out << ob.getContainerSize()<< "           ";
	char*cat = ob.getCategory();
	if (cat)
	{
		out << cat; 
		s = strlen(cat);
		if (s < 16)
		{
			for (int sp = 0; sp < 16 - s; sp++)
			{
				cout << " ";
			}
		}
		delete[]cat;
		cat = nullptr;
	}
	else
	{
		out << "Empty        ";
	}
	if (ob.getFourWheelDrive()==true)
	{
		out << "Yes\n";
	}
	else
	{
		out << "No\n";
	}
	return out;
}

ofstream&operator<<(ofstream&outp, Truck&ob)
{
	char*company = nullptr;
	company = ob.getCompanyName();
	outp << "Company      Color       Wheels   Power    Type      containerSize     Category       FourWheelDrive\n";
	int s = 0;
	if (company)
	{
		outp << company;
		s = strlen(company);
		if (s < 13)
		{
			for (int sp = 0; sp < 13 - s; sp++)
			{
				outp << " ";
			}
		}
		else
		{
			outp << "  ";
		}
		delete[]company;
		company = nullptr;
	}
	else
	{
		outp << "Empty        ";
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
		}
		delete[]col;
		col = nullptr;
	}
	else
	{
		outp << "Empty       ";
	}
	outp << ob.getNumberOfWheels() << "        ";
	outp << ob.getPowerCC() << "    ";
	ob.checkType();
	char*t1 = ob.getTypeOfVehicle();
	if (t1)
	{
		outp << t1;
		s = strlen(t1);
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
	delete[]t1;
	t1 = nullptr;
	outp << ob.getContainerSize() << "           ";
	char*cat = ob.getCategory();
	if (cat)
	{
		outp << cat << "    ";
		delete[]cat;
		cat = nullptr;
	}
	else
	{
		outp << "Empty        ";
	}
	if (ob.getFourWheelDrive() == true)
	{
		outp << "Yes\n";
	}
	else
	{
		outp << "No\n";
	}
	return outp;
}