#include "Admin.h"

Admin::Admin(){}

Admin::~Admin(){}

void Admin::authorization() {
	cout << "Введите логин:";
	cin >> login;
	cout << "Введите пароль:";
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
	cout << "Введите логин:";
	cin >> login;
	do {
		cout << "Введите пароль:";
		password = stars();
		cout << "Введите пароль ещё раз:";
		buff = stars();
	} while (password.compare(buff));
	encryption(password,1);
	cout << "Введите имя:";
	cin >> name;
	cout << "Введите фамилия:";
	cin >> surname;
	cout << "Введите должность:";
	cin >> position;
	cout << "Введите уровень доступа:";
	enter_number(role,1);
	system("cls");
}

void Admin::show() {
	cout << setfill(' ') << '|' << setw(20) << login
		<< '|' << setw(30) << name 
		<< '|' << setw(30) << surname 
		<< '|' << setw(10) << position << '|' << endl;
	cout << setw(96) << setfill((char)196) << ' ' << endl;
}

void Admin::show_header() {
	cout << setw(96) << setfill((char)196) << ' ' << endl;
	cout << setfill(' ') << '|'
		<< setw(20) << "Логин"
		<< '|' << setw(30) << "Имя"
		<< '|' << setw(30) << "Фамилия"
		<< '|' << setw(10) << "Должность" << '|' << endl;
	cout << setw(96) << setfill((char)196) << ' ' << endl;
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

bool operator!=(const Admin &firstUser, const Admin &secondUser) {
	return firstUser.login != secondUser.login ||
		firstUser.password != secondUser.password;
}

bool operator==(const Admin &firstUser, const Admin &secondUser) {
	return firstUser.login == secondUser.login;
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
