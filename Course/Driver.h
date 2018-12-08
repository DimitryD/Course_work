#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Functions.h"
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
	int id;
public:
	Driver();
	~Driver();
	friend istream& operator >>(istream& in, Driver &driver);
	friend ostream& operator <<(ostream& out, Driver &driver);
	friend bool operator==(Driver driver1, Driver driver2);
	friend bool operator==(Driver driver, string id);
	static bool comp_name(Driver &driver1, Driver &driver2);
	static bool comp_age(Driver &driver1, Driver &driver2);
	static bool comp_experience(Driver &driver1, Driver &driver2);
	static bool comp_salary(Driver &driver1, Driver &driver2);
	static void filtr_age(Driver &driver, string first, string second);
	static void filtr_experience(Driver &driver, string first, string second);
	static void filtr_salary(Driver &driver, string first, string second);
	static void search_surname(Driver &driver, string word);
	static void search_category(Driver &driver, string word);
	static void search_itinerary(Driver &driver, string word);
	static void search_transport_code(Driver &driver, string word);
	operator const void*();
	void show();
	static void show_header();
	void create();
	void clear();
	string get_name();
	string get_surname();
	string get_patronymic();
	string get_route();
};

