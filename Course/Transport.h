#pragma once
#include <string>
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

	Transport();
	virtual ~Transport()=0;	
};

class autobus :protected Transport {

public:


};

