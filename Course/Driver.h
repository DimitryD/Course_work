#pragma once
#include <string>
using namespace std;

class Driver{
	string name;
	string surname;
	int age;
	int experience;
	int category;
	int itinerary;
	int salary;
	string telephone_number;
public:
	Driver();
	virtual ~Driver()=0;
};

