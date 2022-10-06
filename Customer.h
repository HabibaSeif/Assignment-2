#pragma once
#include "Person.h"

class Customer :public Person {
private:
	int Mechanicid;
	Appointment appointment;
public:
	Customer(string name = "", int id = 0, int age = 0, int mechanicid = 0, int appm = 0, int apph = 0);
	void setappm(int&);
	void setapph(int&);
	void setapp(Appointment);
	void setmechanicid(int);
	int getappm();
	int getapph();
	Appointment getapp();
	int getmechanicid();
	virtual void printInfo();
	bool operator <(const Customer&);
	bool operator >(const Customer&);
	bool operator ==(const Customer&);

};

Customer::Customer(string name, int id, int age, int mechanicid, int appm, int apph) :Person(name, id, age)
{
	setappm(appm);
	setmechanicid(mechanicid);
	setapph(apph);
}

void Customer::setappm(int& appm)
{
	while ((appm < 0) || (appm > 59))
	{
		cout << "Please enter a valid minute number: ";
		cin >> appm;
	}
	appointment.minutes = appm;
}

void Customer::setapph(int& apph)
{
	while ((apph < 0) || (apph > 23))
	{
		cout << "Please enter a valid hour number: ";
		cin >> apph;
	}
	appointment.hours = apph;
}

void Customer::setapp(Appointment x)
{
	x.hours = getapph();
	cout << "Hours want to book: " << x.hours << endl;
	x.minutes = getappm();
	cout << "Minutes want to book: " << x.minutes << endl;
}

void Customer::setmechanicid(int mechanicid)
{
	Mechanicid = mechanicid;
}

int Customer::getappm()
{
	return appointment.minutes;
}

int Customer::getapph()
{
	return appointment.hours;
}

Appointment Customer::getapp()
{
	cout << "get hours: " << appointment.hours << endl;
	cout << "get minutes: " << appointment.minutes << endl;
	return appointment;
}

int Customer::getmechanicid()
{
	return Mechanicid;
}

void Customer::printInfo()
{
	cout << "Name: " << getName() << endl;
	cout << "Id: " << getId() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Hour of Appointment: " << getapph() << endl;
	cout << "Minute of Appointment: " << getappm() << endl;
	if (getmechanicid() == -1)
	{
		cout << "No reservation given due to unsuitable time" << endl;
	}
	else
	{
		cout << "Mechanic id asscociated with appointment: " << getmechanicid() << endl;
	}
}

bool Customer:: operator <(const Customer& rhs)
{
	if ((this->appointment.hours) < (rhs.appointment.hours))
	{
		return true;
	}

	else if (((this->appointment.minutes) < (rhs.appointment.minutes)) && ((this->appointment.hours) == (rhs.appointment.hours)))
	{
		return true;
	}

	else
	{
		false;
	}
}

bool Customer:: operator >(const Customer& rhs)
{
	if ((this->appointment.hours) > (rhs.appointment.hours))
	{
		return true;
	}

	else if (((this->appointment.minutes) > (rhs.appointment.minutes)) && ((this->appointment.hours) == (rhs.appointment.hours)))
	{
		return true;
	}

	else
	{
		false;
	}
}

bool Customer::operator==(const Customer& rhs)
{
	return (((this->appointment.hours) == (rhs.appointment.hours)) && ((this->appointment.minutes) == (rhs.appointment.hours)));
}