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
	friend istream& operator >>(istream& in, Admin &user){
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
	friend bool operator==(const Admin &firstUser, const Admin &secondUser){
		return firstUser.login == secondUser.login &&
			firstUser.password == secondUser.password;
	}
	operator bool() {
		return authorized;
	}
	operator int() {
		return role;
	}
	void clear();
};
