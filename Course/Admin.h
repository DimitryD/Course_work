#pragma once
#include <iostream>
#include "Functions.h"
using namespace std;


//enum Role {
//	Worker = 3,
//	Manager = 2,
//	Admin = 1
//};

class Admin{

private:
	string login;
	string password;
	string name;
	string surname;
	string position;
	int role;

public:
	bool authorized;
	Admin();
	~Admin();
	void authorization();
	friend istream& operator >>(istream& in, Admin &user);
	friend ostream& operator <<(ostream& out, Admin &user);
	friend bool operator==(const Admin &firstUser, const Admin &secondUser);
	friend bool operator!=(const Admin &firstUser, const Admin &secondUser);
	friend bool operator==(const Admin &user,string login);
	operator bool();
	operator int();
	void clear();
	void create();
	void show();
	void show_header();
	bool compare(Admin comp);
};
