#include "Admin.h"


Admin::Admin(){
}


Admin::~Admin(){
}

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