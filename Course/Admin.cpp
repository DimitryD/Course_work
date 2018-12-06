#include "Admin.h"

Admin::Admin(){}

Admin::~Admin(){}

void Admin::authorization() {
	cout << "Enter login:";
	cin >> login;
	cout << "Enter password:";
	password = stars();
	encryption(password,1);
	system("cls");
}

void Admin::clear() {
	login.clear();
	password.clear();
	name.clear();
	surname.clear();
	position.clear();
	role = 0;
}

void Admin::create() {
	//system("cls");
	string buff;
	cout << "Enter login:";
	cin >> login;
	do {
		cout << "Enter password:";
		password = stars();
		cout << "Enter password again:";
		buff = stars();
	} while (password.compare(buff));
	encryption(password,1);
	cout << "Enter name:";
	cin >> name;
	cout << "Enter surname:";
	cin >> surname;
	cout << "Enter position:";
	cin >> position;
	cout << "Enter access level:";
	enter_number(role,1);
}

bool Admin::compare(Admin comp) {
	return login.compare(comp.login);
}

istream& operator >>(istream& in, Admin &user) {
	return in >> user.login
		>> user.password
		>> user.role
		>> user.name
		>> user.surname
		>> user.position;
}

ostream& operator <<(ostream& out, Admin &user) {
	return out << user.login << ' '
		<< user.password << ' '
		<< user.role << ' '
		<< user.name << ' '
		<< user.surname << ' '
		<< user.position << endl;
}

bool operator==(const Admin &firstUser, const Admin &secondUser) {
	return firstUser.login == secondUser.login &&
		firstUser.password == secondUser.password;
}

bool operator==(const Admin &user, string log) {
	return !(user.login.compare(log));
}

Admin::operator bool() {
	return authorized;
}

Admin::operator int() {
	return role;
}
