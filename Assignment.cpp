#include<iostream>
#include "Mechanic.h"
#include "Queue.h"
#include "Customer.h"
//#include <queue>
#include <fstream>
#include <sstream>
using namespace std;
Queue<Mechanic>Mechanics;
Queue<Customer>Customers;
Customer cust[4];

void ValidateId(int& iD, int i)
{
	for (int j = 0; j < i; j++)
	{
		if (cust[j].getId() == iD)
		{
			cout << "This Id number has already been taken by another customer. Please re-enter: ";
			cin >> iD;
		}
	}
}
void fillMechanic()
{
	Mechanic M;
	int id = 211, c = 100;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			M.setName("Ahmed");
		}
		else if (i == 1)
		{
			M.setName("Mai");
		}
		else
		{
			M.setName("Ayman");
			
		}

		cout << "Name of Mechanic " << i + 1  << ": " << M.getName();
		cout << endl;
		M.setAge(32 + i);
		cout << "Age: " << M.getAge();
		cout << endl;
		M.setId(id);
		cout << "ID: " << M.getId();
		id += c;
		cout << endl;
		//M.setcount(40);
		//cout << "Count: " << M.getcount() << endl;
		Mechanics.push(M);
	}

	//for (int i = 0; i < 3; i++)
	//{
	//	Mechanics.front().printInfo();
	//	Mechanics.pop(); // our error 
	//}
}

void fillCustomer()
{
	Queue<Mechanic>Mechanics2;
	string name;
	Appointment x;
	x.hours = 0, x.minutes = 0;
	int id, age, specifier = 0;
	for (int I = 0; I < 4; I++)
	{
		cout << "C.Name: ";
		cin >> name;
		cust[I].setName(name);
		cout << endl;
		cout << "C.Age: ";
		cin >> age;
		cust[I].setAge(age);
		cout << endl;
		cout << "C.Id: ";
		cin >> id;
		ValidateId(id, I);
		cust[I].setId(id);
		cout << endl;
		cout << "C.Hours: ";
		cin >> x.hours;
		cust[I].setapph(x.hours);
		cout << endl;
		cout << "C.Minutes: ";
		cin >> x.minutes;
		cust[I].setappm(x.minutes);
		cout << endl;
		cust[I].setapp(x);
		//cust[I].getapp();
		for (int i = 0; i < 3 ; i++)
		{
			//cout << "I looped" << endl;
			cout << Mechanics.front().getName() << endl;
			if (Mechanics.front().isAv(cust[I].getapp()) == true)
			{

				Mechanics.front2(Mechanics.front().isAv2(cust[I].getapp()));
				//cout << Mechanics.front().getsize() << endl;
				cust[I].setmechanicid(Mechanics.front().getId());
			break;
			}
			else
			{
				Mechanic T(Mechanics.front());
				Mechanics2.push(T);
				Mechanics.pop();
				specifier++;
			}
		}



		//if (Mechanics.empty())
		if(Mechanics.empty())
		{
			cust[I].setmechanicid(-1);
		}

		if ((specifier > 0) && (!Mechanics.empty()))
		{
			while (!Mechanics.empty())
			{
				Mechanic T(Mechanics.front());
				Mechanics2.push(T);
				Mechanics.pop();
			}
		}

		cout << "Associated mechanic id: " << cust[I].getmechanicid() << endl;

		//int c = 0;

		while (!Mechanics2.empty())
		{
			Mechanic T(Mechanics2.front());
			Mechanics.push(T);
			Mechanics2.pop();
			//c++;

		}

	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++) // j = i + 1;
		{
			if ((cust[j] < cust[i]) == true) // arr[j] < arr[i];
			{
				swap(cust[j], cust[i]);
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		cust[i].printInfo();
	}
}

void swap(Customer& x, Customer& y)
{
	Customer temp = x;
	x = y;
	y = temp;
}

int main()
{
	/*Queue<int>Number;
	for (int i = 0; i < 5; i++)
	{
		Number.push(i);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << Number.front() ;
		Number.pop();
	}
	cout << endl;
	//cout << Number.empty();*/
	fillMechanic();
	cout << endl;
	cout << "CUSTOMER INPUT" << endl;
	cout << "==============" << endl;
	fillCustomer();
	cout << endl << endl;
	cout << "BONUS" << endl;
	cout << "============" << endl;
	Mechanic x;
	Customer y;
	Appointment A;
	ifstream inStream;
	ofstream outStream;
	inStream.open("Text.txt");
	if (inStream.fail()) {
		cout << "Error made when accessing file";
		exit(1);
	}

	int count = 0;
	while (!inStream.eof())
	{
		int a, i, n, r;
		string temp;
		getline(inStream, temp);
		stringstream str(temp);
		string read;
		int numberapp;
		int count = 0;
		while (getline(str, read, ' '))
		{
			x.clear();
			x.setName(read);
			//cout << x.getName() << endl;
			str >> a;
			x.setAge(a);
			//cout << x.getAge() << endl;
			//cout << a << endl;
			str >> i;
			x.setId(i);
			//cout << x.getId() << endl;
			//cout << i << endl;
			str >> n;
			//cout << n << endl;
			for (int i = 0; i < n * 2; i++)
			{
				str >> r;
				if ((i%2) == 0)
				{
					A.hours = r;
					y.setapph(A.hours);
					//cout << y.getapph() << endl;
				}
				else
				{
					A.minutes = r;
					y.setappm(A.minutes);
					//cout << y.getappm() << endl;
					x.add(A);
				}
			}
			Mechanics.push(x);
			break;
		}
	}

	while(!Mechanics.empty())
	{
		Mechanics.front().printInfo();
		Mechanics.pop();
	}

	inStream.close();
}