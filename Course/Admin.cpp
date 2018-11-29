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
	system("cls");
}