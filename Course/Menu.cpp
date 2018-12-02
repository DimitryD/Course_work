#include "Menu.h"
#include "Stuff.cpp"
#include <conio.h>
#include "Functions.h"

Menu::Menu():menu_pointer(1){}

Menu::~Menu() {}


static Admin user;

void Menu::menu_authorization() {
	menu_pointer = 1;
	char c;
	do {
		system("cls");
		print_in_menu(1, "Authorization");
		print_in_menu(2, "Exit");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 2)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				if ((user=authorization("User.txt"))) {
					menu_user(user);
				}
				break;
			case 2:
				return;
			}
		}
	} while (1);
}

void Menu::print_in_menu(int pointer, const char *str) {
	cout << ((pointer == menu_pointer) ? color<10, 0> : color<15, 0>) << str << endl;
}

void Menu::menu_user(int role) {

	char c;
	menu_pointer = 1;
	do {
		int i = 0;
		system("cls");
		switch (role) {
		
		case 1:
			print_in_menu(++i, "Manage user");
		case 2:
			print_in_menu(++i, "Add information");
			print_in_menu(++i, "Delete information");
		case 3:
			print_in_menu(++i, "Print infirmation");
			print_in_menu(++i, "Sort information");
			print_in_menu(++i, "Filtr information");
			
		default:
			print_in_menu(++i, "Back");
		}
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < i)
			menu_pointer++;
		if (c == '\r') {
			int  k = 0;
			switch (role) {
			case 1:
				if (menu_pointer == ++k) add_user();
			case 2:
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
			case 3:
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
			default:
				if (menu_pointer == ++k) {
					user.clear();
					menu_pointer = 1;
					return;
				}
			}
		}
	} while (1);
}

