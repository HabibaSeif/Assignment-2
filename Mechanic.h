#pragma once
#include "Person.h"
#include <vector>


class Mechanic:public Person {
private:
	vector<Appointment>a;
	//int count;
	;
public:
	Mechanic(string name = "", int id = 0, int age = 0);
	Mechanic(const Mechanic&);
	bool isAv(Appointment);
	virtual void printInfo();
	void add(Appointment);
	int getsize();
	void clear();
	Mechanic isAv2(Appointment x);
	//void setcount(int);
	
	
	//Mechanic operator =(const Mechanic&);
	//int getcount() const;
};

/*void Mechanic::setcount(int c)
{
	count = c;
}

int Mechanic::getcount() const
{
	return count;
}*/
void Mechanic::clear()
{
	a.resize(0);
}
void Mechanic::add(Appointment x)
{
	a.push_back(x);
}

Mechanic::Mechanic(string name, int id, int age) :Person(name, id, age)
{
	//setcount(c);
}

Mechanic::Mechanic(const Mechanic & rhs)

{
	//cout << "copy constructor \n";

	this->setName(rhs.getName());
	this->setAge(rhs.getAge());
	this->setId(rhs.getId());
	//this->setcount(rhs.getcount()); // error
	/*for (int i = 0; i < rhs.a.size(); i++)
	{
		Appointment temp = rhs.a[i];
		this->a.push_back(temp);
	}*/
	this->a = rhs.a;
}
//Mechanic Mechanic::operator =(const Mechanic& rhs)
//{
//	cout << "copy constructor \n";
//
//	this->setName(rhs.getName());
//	this->setAge(rhs.getAge());
//	this->setId(rhs.getId());
//	this->setcount(rhs.getcount()); // error
//	/*for (int i = 0; i < rhs.a.size(); i++)
//	{
//		Appointment temp = rhs.a[i];
//		this->a.push_back(temp);
//	}*/
//	this->a = rhs.a;
//	return *this;
//
//}

bool Mechanic::isAv(Appointment  x)
{
	
	//cout << " is av \n";
	for (int i = 0; i < a.size(); i++)
	{
		cout << "Reserved: " << a[i].hours << endl;
		cout << "Want: " << x.hours << endl;
		cout << "Reservedm: " << a[i].minutes << endl;
		cout << "Wantm: " << x.minutes << endl;
	}
	for (int i = 0; i < a.size(); i++)
	{
		if ((a[i].hours == x.hours) && (a[i].minutes == x.minutes))
		{
			return false;
		}
	}

	a.push_back(x);
	Mechanic temp(*this);
	//*this = temp; //does not call the copy constructor but instead calls the = therefore overloading it and making it perform as a copy constructor
	////////// don't do this
	

	this->setName(temp.getName());
	this->setAge(temp.getAge());
	this->setId(temp.getId());
	//this->setcount(temp.getcount()); // error
	/*for (int i = 0; i < rhs.a.size(); i++)
	{
		Appointment temp = rhs.a[i];
		this->a.push_back(temp);
	}*/
	this->a = temp.a;
	
	///////////.


	//cout << this << " "<< this->getName() << endl;
	//cout << "I pushed" << a.size() << endl;
	return true;
}
Mechanic Mechanic::isAv2(Appointment  x)
{

	//cout << " is av2 \n";

	a.push_back(x);
	return *this;
}



void Mechanic::printInfo()
{
	cout << "Name: " << getName() << endl;
	cout << "Id: " << getId() << endl;
	cout << "Age: " << getAge() << endl;
	//cout << "Count: " << getcount() << endl; // ahlan ahlan
	for (int i = 0; i < a.size(); i++)
	{
		cout << "Appointment " << i + 1 << endl;
		cout << "Hours: " << a[i].hours << endl;
		cout << "Minutes: " << a[i].minutes << endl;
	}
}

int Mechanic::getsize()
{
	//cout << this<< " " << this->getName() << endl;
	return a.size();
}