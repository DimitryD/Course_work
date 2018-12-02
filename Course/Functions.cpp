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
		while (file >> tmp)
			if (tmp == user) {
				tmp.authorized = true;
				return tmp;
			}
		cout << "Authorization error. Please, try again" << endl;
	}
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
	return (string)str;
}

string encryption(string &str,int key) {
	for (int i = 1; i < str.length(); i++)
		str[i] += key;
	return str;
}

void add_user() {
	ifstream file("User.txt");
	if (!file) {
		cout << "Error";
		_getch();
		exit(1);
	}

	return;
}