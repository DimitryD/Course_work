#include "Functions.h"

Admin authorization(string filename) {
	Admin tmp, user;
	ifstream file(filename);
	string buffer;
	if (!file) {
		cout << "Error";
		_getch();
		exit(1);
	}
	for (int i = 0; i < 3; i++) {
		user.authorization();
		while (file >> tmp) {
			if (!(tmp != user)) {
				tmp.authorized = true;
				return tmp;
			}
		}
		file.clear();
		file.seekg(0);
		cout << "Authorization error. Please, try again" << endl;
	}
	user.clear();
	user.authorized = false;
	return user;
}

string stars() {
	int i = 0;
	char c = 0;
	char str[100];
	do {
		c = _getch();
		if ((c >= 'a'&&c <= 'z')||(c>='A'&&c<='Z') || (c >= '0'&&c <= '9')) {
			str[i] = c;
			i++;
			cout << '*';
		}
		if (c == '\b'&&i > 0) {
			str[i] = '\0';
			i--;
			cout << "\b \b";
		}
	} while (c != '\r');
	str[i] = '\0';
	cout << '\n';
	return (string)str;
}

string encryption(string &str,int key) {
	for (int i = 1; i < str.length(); i++)
		str[i] += key;
	return str;
}

void show_users() {
	ifstream file("User.txt");
	if (!file) {
		cout << "Error";
		_getch();
		exit(1);
	}
	Admin tmp;
	while (file >> tmp) {
		cout << tmp;
	}
	cout << "Enter any key...";
	_getch();
	return;
}

void enter_bool(bool &var) {
	char c;
	do {
		c = _getch();
	} while (c != 48 && c != 49);
	c == 48 ? var = 0 : var = 1;
}

void rent_bus() {
	system("cls");
	list<Autobus> buses;
	read_information_from_file(buses, "Buses.txt");
	string id;
	bool flag = 1;
	cout << "Enter code:";
	cin >> id;
	find_if(buses.begin(), buses.end(), [id, &flag](Autobus &tmp) {
		if (tmp == id) {
			if (tmp.check_rent())
				return false;
			tmp.set_rent();
			flag = 0;
			cout << "Rented tommorow" << endl;
			_getch();
			return true;
		}
		return false;
	});
	if (flag) {
		cout << "Can not be rent" << endl;
		_getch();
	}
	else {
		write_information_in_file(buses, "Buses.txt");
	}

}


void rent_driver() {
	system("cls");
	list<Driver> drivers;
	read_information_from_file(drivers, "Drivers.txt");
	string id;
	bool flag = 1;
	cout << "Enter code:";
	cin >> id;
	find_if(drivers.begin(), drivers.end(), [id,&flag](Driver &tmp) {
		if (tmp == id) {
			if (tmp.check_rent())
				return false;
			tmp.set_rent();
			flag = 0;
			cout << "Rented tommorow" << endl;
			_getch();
			return true;
		}
		return false;
	});
	if (flag) {
		cout << "Can not be rent" << endl;
		_getch();
	}
	else {
		write_information_in_file(drivers, "Drivers.txt");
	}
}