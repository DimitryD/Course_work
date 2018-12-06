#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Driver{
	string name;
	string surname;
	string patronymic;
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
	static bool comp_name(Driver &driver1, Driver &driver2);
	static bool comp_age(Driver &driver1, Driver &driver2);
	static bool comp_experience(Driver &driver1, Driver &driver2);
	static bool comp_salary(Driver &driver1, Driver &driver2);
	operator const void*();
	void show();
	void show_header();
};

