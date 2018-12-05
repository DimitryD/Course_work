#pragma once
#include <iostream>
#include <string>
using namespace std;

class Transport{

protected:
	static int number_of_machines;
	static string validator_version;
	string code;
	int year;
	string model;
	int distance;
	string route;
public:
	
	Transport();
	virtual ~Transport()=0;	
};


class Electro {
	int amperage;
};


class Fuel {
	int fuel_capacity;
	int consumption;
};

class Wheel {
	int number_of_wheels;
	int wheel_size;
};

class Rail {
	string wheel_type;
};

class Autobus : Transport, Fuel, Wheel {

};

class Tram : Transport, Electro, Rail {

};

class Trolleybus :Transport, Electro, Wheel {

};
