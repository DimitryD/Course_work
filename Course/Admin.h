#pragma once
#include <iostream>
//#include <string>
#include "Functions.h"
using namespace std;

class Admin{
private:

public:
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
	friend istream& operator >>(istream& in, Admin &user)
	{
		return in >> user.login 
			>> user.password
			>> user.role 
			>> user.name 
			>> user.surname 
			>> user.position;
	}
	friend ostream& operator <<(ostream& out, Admin &user) {
		return out << user.login 
			<< user.password 
			<< user.role
			<< user.name
			<< user.surname
			<< user.position;
	}
	friend bool operator==(const Admin &firstUser, const Admin &secondUser)
	{
		return firstUser.login == secondUser.login &&
			firstUser.password == secondUser.password;
	}
	operator bool() {
		return authorized;
	}
	//Admin &operator=(const Admin &user) {
	//	login = user.login;
	//	password = user.password;
	//	name = user.name;
	//	surname = user.surname;
	//	role = user.role;
	//	position = user.position;
	//	return *this;
	//}
};
