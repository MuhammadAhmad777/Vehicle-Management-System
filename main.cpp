#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include "Truck.h"
#include"BilalMotors.h"
char*deepConcept(char*pArr);
Vehicle** regrow(Vehicle**prevArr, int& count, Vehicle*insert);
char* regrow(char*pArr, int &size);
void check();
int main()
{
	//check();
	//tested many times and It's running well Alhumdullilah.
	char option;
	BilalMotors M1;
	//ouside the loop so that no redeclaration just overwritting each time to add new vehicle
	Vehicle* v;
	while (true)
	{
		cout << "\t\t\t*** BILAL MOTORS ***\n";
		cout << "S\t\tShow vehicles list (brief)\n";
		cout << "E\t\tCreate a data file (output file)\n";
		cout << "A\t\tAdd new vehicle\n";
		cout << "F\t\tFind Vehicle by type\n";
		cout << "Q\t\tQuit Program\n";
		do
		{
			cout << "Enter Your Choice:";
			cin >> option;
			if (option != 'S'&&option != 'E'&& option != 'A'&& option != 'F'&&option != 'Q')
			{
				cout << "Invalid Input!!!Please re-enter with correct Option\n";
			}
		} while (option != 'S'&&option != 'E'&& option != 'A'&& option != 'F'&&option != 'Q');
		if (option == 'S')
		{
			ShowVehicles(M1);
			cout << "Required Operation performed\n";
			cout << "\tQ for Back(Back to Main Menu)\n";
			do
			{
				cout << "Enter Your Choice:";
				cin >> option;
				if (option != 'Q')
				{
					cout << "You selected Invalid option!!,Enter Q for Back(Back to Main Menu)\n";
				}
			} while (option != 'Q');
			if (option == 'Q')
			{
				continue;
			}
		}
		else if (option == 'E')
		{
				bool res = M1.saveData("outputFile");
				if (res == false)
				{
					cout << "Sorry,We cannot genrate output\n";
				}
				else if (res == true)
				{
					cout << "Required Operation performed,output generated in outputFile.txt\n";
					cout << "\tQ for Back(Back to Main Menu)\n";
					do
					{
						cout << "Enter Your Choice:";
						cin >> option;
						if (option != 'Q')
						{
							cout << "You selected Invalid option!!,Enter Q for Back(Back to Main Menu)\n";
						}
					} while (option != 'Q');
					if (option == 'Q')
					{
						continue;
					}
				}
		}
		else if (option == 'A')
		{
			
			cout << " \t\tB for Bike\n";
			cout << " \t\tC for Car\n";
			cout << " \t\tT for Truck\n";
			cout << "\t\tQ for Back\n";
			do
			{
				cout << "Enter Your Choice:";
				cin >> option;
				if (option != 'B'&&option != 'C'&&option != 'T'&&option!='Q')
				{
					cout << "Invalid Input!!!Please re-enter with correct Option\n";
				}
			} while (option != 'B'&&option != 'C'&&option != 'T'&&option != 'Q');
			if (option=='B')
			{
				cin.ignore();
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
					cin.get(company[i]);
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
					cin.get(col[i]);
					i++;
				} while (col[i - 1] != '\n');
				col[i - 1] = '\0';
				cout << "Enter Number of wheels: ";
				cin >> number;
				cout << "Enter PowerCC: ";
				cin >> CC;
				cout << "Enter height: ";
				cin >> h;
				int s3 = 0;
				char *opt = new char[s3];
				i = 0;
				cin.ignore();
				cout << "tell about Self start. (write true for true else write false or any word to false)\nWrite:";
				do
				{
					opt = regrow(opt, s3);
					cin.get(opt[i]);
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
					cin.get(opt[i]);
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
				v = new Bike(company, col, number, CC,h,selfst,disc);
				v->checkType();
				M1.addVehicle(v);
				if (company)
				{
					delete[]company;
					company = nullptr;
				}
				if (col)
				{
					delete[]col;
					col = nullptr;
				}
				
			}
			else if (option=='C')
			{
				cin.ignore();
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
				cout << "Enter Company Name: ";
				do
				{
					company = regrow(company, size1);
					cin.get(company[i]);
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
					cin.get(col[i]);
					i++;
				} while (col[i - 1] != '\n');
				col[i - 1] = '\0';
				cout << "Enter Number of wheels: ";
				cin >> number;
				cout << "Enter PowerCC: ";
				cin >> CC;
				cout << "Enter  no of doors: ";
				cin >> doorsNum;
				int s3 = 0;
				i = 0;
				cin.ignore();
				cout << "Enter trasmission:";
				tras = new char[s3];
				do
				{
					tras = regrow(tras, s3);
					cin.get(tras[i]);
					i++;
				} while (tras[i - 1] != '\n');

				tras[i - 1] = '\0';
				cout << "Enter number of seats:";
				cin>> seatsNum;
				v = new Car(company, col, number, CC, doorsNum, tras, seatsNum);
				v->checkType();
				M1.addVehicle(v);
				if (company)
				{
					delete[]company;
					company = nullptr;
				}
				if (col)
				{
					delete[]col;
					col = nullptr;
				}
				if (tras)
				{
					delete[]tras;
					tras = nullptr;
				}
			}
			else if (option=='T')
			{
				cin.ignore();
				
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
				cout << "Enter Company Name: ";
				do
				{
					company = regrow(company, size1);
					cin.get(company[i]);
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
					cin.get(col[i]);
					i++;
				} while (col[i - 1] != '\n');
				col[i - 1] = '\0';
				cout << "Enter Number of wheels: ";
				cin >> number;
				cout << "Enter PowerCC: ";
				cin >> CC;
				cout << "Enter container Size:";
				cin >> container;
				cin.ignore();
				cout << "Enter category:";
				int sc = 0;
				cate = new char[sc];
				i = 0;
				do
				{
					cate = regrow(cate, sc);
					cin.get(cate[i]);
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
					cin.get(opt[i]);
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
				v = new Truck(company, col, number, CC, container, cate, fourWheel);
				v->checkType();
				M1.addVehicle(v);
				if (company)
				{
					delete[]company;
					company = nullptr;
				}
				if (col)
				{
					delete[]col;
					col = nullptr;
				}
				if (cate)
				{
					delete[]cate;
					cate = nullptr;
				}
			}
			else if (option == 'Q')
			{
				continue;
			}
			cout << "\tQ for Back(Back to Main Menu)\n";
			do
			{
				cout << "Enter Your Choice:";
				cin >> option;
				if (option != 'Q')
				{
					cout << "You selected Invalid option!!,Enter Q for Back(Back to Main Menu)\n";
				}
			} while (option != 'Q');
			if (option == 'Q')
			{
				continue;
			}
		}
		else if (option == 'F')
		{
			cout << "Enter type by which you want to search:";
			char*srch = new char[6];
			cin.ignore();
			cin.getline(srch, 6);
			M1.searchVehicle(srch);
			delete[]srch;
			srch = nullptr;
			cout << "Required Operation performed\n";
			cout << "\tQ for Back(Back to Main Menu)\n";
			do
			{
				cout << "Enter Your Choice:";
				cin >> option;
				if (option != 'Q')
				{
					cout << "You selected Invalid option!!,Enter Q for Back(Back to Main Menu)\n";
				}
			} while (option != 'Q');
			if (option == 'Q')
			{
				continue;
			}
		}
		else if (option == 'Q')
		{
			system("pause");
			exit(0);
		}
	}

	return 0;
}
char*deepConcept(char*pArr)
{
	char*tem = nullptr;
	if (pArr)
	{
		int size = strlen(pArr);
		if (size > 0)
		{
			tem = new char[size + 1];
			for (int cp = 0; cp < size; cp++)
			{
				tem[cp] = pArr[cp];
			}
			tem[size] = '\0';
		}
	}
	return tem;
}
char* regrow(char*pArr, int &size)
{
	char*nArr = new char[size + 1];
	if (size > 0)
	{
		for (int cp = 0; cp < size; cp++)
		{
			nArr[cp] = pArr[cp];
		}
	}
	size++;
	delete[]pArr;
	pArr = nullptr;
	return nArr;
}
Vehicle** regrow(Vehicle**prevArr, int& count,Vehicle*insert)
{
	Vehicle**nArr = new Vehicle*[count + 1];
	if (count > 0&&prevArr)
	{
		for (int ind = 0; ind < count; ind++)
		{
			nArr[ind] = prevArr[ind];
		}
	}
		nArr[count] = insert;
		count++;
		delete[]prevArr;
		prevArr = nullptr;
	return nArr;
}
void check()//this was just for testing in depth
{
	/*Bike B("Honda", "white", 2, 150, 38.3, true, false);
	B.checkType();
	B.display();
	B.setColor("Black");
	B.setCompanyName("Hello");
	B.setNumberOfWheels(2);
	B.setHeight(80.8);
	B.setPowerCC(70);
	B.setSelfStart(true);
	B.setDiscBrake(true);
	cin >> B;
	cout << B;
	ofstream fout;
	fout.open("checkBikefout.txt");
	fout << B;
	fout.close();
	ifstream fin;
	fin.open("InputBikecheck.txt");
	if (fin)
	{
		Bike C;
		C.checkType();
		fin >> C;
		fin.close();
		cout << C;
	}
	else
	{
		cout << "file not founded\n";
	}*/
	//Car a;
	//cin >> a;
	//a.checkType();
	//a.display();
	//cout << a;
	/*ifstream fin;
	fin.open("CarCheck.txt");
	if (fin)
	{
	Car b;
	fin >> b;
	cout << b;
	fin.close();
	ofstream fout;
	fout.open("carcheckOutput.txt");
	fout << b;
	fout.close();
	}
	else
	{
	cout << "File not found\n";
	}*/
	/*Truck T;
	cin >> T;
	T.display();
	cout << T;
	
	ifstream fin;
	fin.open("truckcheck.txt");
	if (fin)
	{
	Truck T2;
	fin >> T2;
	fin.close();
	ofstream fout;
	fout.open("truckCheckOutput.txt");
	fout << T2;
	fout.close();
	}
	else
	{
	cout << "File not found\n";
	}*/
}
