#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Functions.h"
using namespace std;


class Tram;
class Trolleybus;
class Autobus;
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
	void electro_create();
	void electro_clear();
	static void filtr_amperage(Tram &tram, string first, string second);
	static bool comp_amperage(Tram &tram1, Tram &tram2);
	operator const void*();
	virtual ~Electro() = 0;
};


class Fuel {
protected:
	int fuel_capacity;
	int consumption;
public:
	void fuel_create();
	void fuel_clear();
	static void filtr_capacity(Autobus &bus, string first, string second);
	static void filtr_consumption(Autobus &bus, string first, string second);
	static bool comp_capacity(Autobus &bus1, Autobus &bus2);
	static bool comp_consumption(Autobus &bus1, Autobus &bus2);
};

class Wheel {
protected:
	int number_of_wheels;
	int wheel_size;
public:
	void wheel_create();
	void wheel_clear();
	static void filtr_size(Trolleybus &trolleybus, string first, string second);
	static void filtr_number(Trolleybus &trolleybus, string first, string second);
	static void filtr_size_bus(Autobus &bus, string first, string second);
	static void filtr_number_bus(Autobus &bus, string first, string second);
	operator const void*();
};

class Rail {
protected:
	bool wheel_type;
public:
	
};

class Autobus : Transport, public Fuel,public  Wheel {
public:
	friend istream& operator >>(istream& in, Autobus &bus);
	friend ostream& operator <<(ostream& out, Autobus &bus);
	friend bool operator==(Autobus bus1, Autobus bus2);
	friend bool operator==(Autobus bus, string code);
	static void show_header();
	operator const void*();
	void show();
	void clear();
	void create();
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


class Trolleybus :Transport, Electro,public Wheel {
public:
	friend istream& operator >>(istream& in, Trolleybus &trolleybus);
	friend ostream& operator <<(ostream& out, Trolleybus &trolleybus);
	friend bool operator==(Trolleybus trolleybus1, Trolleybus trolleybus2);
	friend bool operator==(Trolleybus trolleybus, string code);
	static void show_header();
	operator const void*();
	void show();
	void clear();
	void create();
};
