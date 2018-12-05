#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Driver{
	string name;
	string surname;
	int age;
	int experience;
	string category;
	string itinerary;//route
	int salary;
	string telephone_number;
	string transport_code;
public:
	Driver();
	~Driver();
	friend istream& operator >>(istream& in, Driver &driver);
	friend ostream& operator <<(ostream& out, Driver &driver);
	void show();
};

