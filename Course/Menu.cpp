#include "Menu.h"
#include "Stuff.cpp"
#include <conio.h>
#include "Functions.h"

Menu::Menu():menu_pointer(1){}

Menu::~Menu() {}


static Admin user;

void Menu::menu_authorization() {

	char c;
	do {
		system("cls");
		print_in_menu(1, "User authorization");
		print_in_menu(2, "Admin authorization");
		print_in_menu(3, "Exit");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 3)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				if ((user=authorization("User.txt"))) {
					menu_user();
				}
				break;
			case 2:
				if (user=authorization("Admin.txt")) {
					cout << "Surprize";
					_getch();
				}
				break;
			case 3:
				return;
			}
		}
	} while (1);
}

void Menu::print_in_menu(int pointer, const char *str) {
	cout << ((pointer == menu_pointer) ? color<10, 0> : color<15, 0>) << str << endl;
}

void Menu::menu_user() {
	
}

void Menu::menu_admin() {

}
