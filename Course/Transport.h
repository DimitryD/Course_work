#pragma once
#include <iostream>
using namespace std;

class Transport{

protected:
	static int number_of_machines;

public:
	char *type;
	char *code;
	int year;
	char *model;
	int capacity;
	int consumption;
	int distance;
	static string validator_version;
	Transport();
	virtual ~Transport()=0;	
};

class autobus :protected Transport {

public:


};

