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

void edit_user() {
	Admin user;
	string login;
	bool flag = 0;
	cout << "Enter login:";
	cin >> login;
	list <Admin> users;
	read_information_from_file(users, "User.txt");
	for (auto tmp : users)
		if (tmp == login)
			flag = 1;
	if(flag){
		users.remove_if([login](Admin obj) { return obj == login; });
		user.create();
		users.push_back(user);
		write_information_in_file(users, "User.txt");
	}
	else {
		cout << "User with this name doesn't create";
	}
	_getch();
	system("cls");
	return;
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

void show_transport() {

	list <Tram> trams;
	Tram tmp;
	ifstream file("Trams.txt");
	string buffer;
	if (!file) {
		cout << "Error";
		_getch();
		exit(1);
	}
	//while(file>>tmp);
}

void show_drivers() {
	system("cls");
	list <Driver> drivers;
	read_information_from_file(drivers, "Drivers.txt");
	show_information(drivers);
}

void sort_drivers(bool(*comparator)(const void *, const void *)) {
	system("cls");
	list <Driver> drivers;
	read_information_from_file(drivers, "Drivers.txt");
	drivers.sort(comparator);
	show_information(drivers);
	write_information_in_file(drivers, "Drivers.txt");
}
