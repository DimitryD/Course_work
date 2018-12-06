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
	friend bool operator<(Driver &driver1, Driver &driver2) {
		return driver1.salary > driver2.salary ? 1 : 0;
	}
	static bool comp_name(Driver &driver1, Driver &driver2) {
		return !driver1.name.compare(driver2.name);
	}
	static bool comp_age(Driver &driver1, Driver &driver2) {
		return driver1.salary > driver2.salary ? 0 : 1;
	}
	void show();
};

