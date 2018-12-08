#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Functions.h"
using namespace std;


class Tram;
class Transport{
protected:
	//static string validator_version;
	string code;
	string surname;
	string name;
	string patronymic;
	string model;
	int year;
	int distance;
	string route;

public:
	//bool readiness;
	virtual void show() = 0;
	void base_clear();
	void get_driver();
	void base_create();
	static void filtr_year(Transport *transport, string first, string second);
	static void filtr_distance(Transport *transport, string first, string second);
	static bool comp_surname(Transport *transport1, Transport *transport2);
	static bool comp_year(Transport *transport1, Transport *transport2);
	static bool comp_distance(Transport *transport1, Transport *transport2);
	static void search_surname(Transport *transport, string word);
	static void search_model(Transport *transport, string word);
	static void search_route(Transport *transport, string word);
	Transport();
	operator const void*();
	virtual ~Transport()=0;	
};


class Electro {
protected:
	int amperage;
public:
	Electro();
	virtual void show() = 0;
	void electro_create();
	static void filtr_amperage(Tram &tram, string first, string second);
	static bool comp_amperage(Tram &tram1, Tram &tram2);
	operator const void*();
	virtual ~Electro() = 0;
};


class Fuel {
protected:
	int fuel_capacity;
	int consumption;
};

class Wheel {
protected:
	int number_of_wheels;
	int wheel_size;
};

class Rail {
protected:
	bool wheel_type;
public:
	
};

class Autobus : Transport, Fuel, Wheel {
public:
	static void show_header(){}
	void show(){}
	friend istream& operator >>(istream& in, Autobus &bus);
	friend ostream& operator <<(ostream& out, Autobus &bus);
};

class Tram :Transport, public Electro, Rail {
public:
	friend istream& operator >>(istream& in, Tram &tram);
	friend ostream& operator <<(ostream& out, Tram &tram);
	friend bool operator==(Tram tram1, Tram tram2);
	friend bool operator==(Tram tram, string code);
	static void show_header();
	operator const void*();
	void show();
	void clear();
	void create();
};


class Trolleybus :Transport, Electro, Wheel {
public:
	static void show_header() {}
	void show() {}
	friend istream& operator >>(istream& in, Trolleybus &trolleybus);
	friend ostream& operator <<(ostream& out, Trolleybus &trolleybus);
};
