#pragma once
#include <iostream>
using namespace std;

class Person {
private:
	string Name;
	int Age, ID;
public:
	Person(string name = "", int id = 0, int age = 0);
	void setId(int);
	void setAge(int);
	void setName(string);
	string getName() const;
	int getAge() const;
	int getId() const;
	virtual void printInfo() = 0;
};

void Person::printInfo() {
	cout << "The name is: " << getName() << endl;
	cout << "The age is: " << getAge() << endl;
	cout << "The id is: " << getId() << endl;
}

Person::Person(string name, int id, int age)
{
	setName(name);
	setId(id);
	setAge(age);
}

void Person::setName(string name)
{
	Name = name;
}

void Person::setId(int id)
{
	ID = id;
}

void Person::setAge(int age)
{
	Age = age;
}

string Person::getName() const
{
	return Name;
}

int Person::getAge() const
{
	return Age;
}

int Person::getId() const
{
	return ID;
}

struct Appointment {
	int hours, minutes;
};