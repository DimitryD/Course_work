#include "Menu.h"
//#include "Stuff.cpp"
#include <conio.h>
#include "Functions.h"

static Admin user;

Menu::Menu():menu_pointer(1){}

Menu::~Menu() {}

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
				if (menu_pointer == ++k) menu_user_manage();
			case 2:
				if (menu_pointer == ++k) menu_add_information(role);
				if (menu_pointer == ++k) menu_delete_information(role);
			case 3:
				if (menu_pointer == ++k) menu_print_information(role);
				if (menu_pointer == ++k) menu_sort_information(role);
				if (menu_pointer == ++k) menu_filtr_information(role);
			default:
				if (menu_pointer == ++k) {
					user.clear();
					menu_pointer = 1;
					return;
				}
			}
		}
	} while (1);
	return;
}

void Menu::menu_user_manage() {
	menu_pointer = 1;
	char c;
	do {
		system("cls");
		print_in_menu(1, "Add user");
		print_in_menu(2, "Edit user");
		print_in_menu(3, "Delete user");
		print_in_menu(4, "Show users");
		print_in_menu(5, "Back");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 5)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				add_user();
				break;
			case 2:
				edit_user();
				break;
			case 3:
				delete_user();
				break;
			case 4:
				show_users();
				break;
			case 5:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
}

void Menu::menu_add_information(int role) {
	char c;
	menu_pointer = 1;
	do {
		int i = 0;
		system("cls");
		switch (role) {

		case 1:
			print_in_menu(++i, "Add driver");
		case 2:
			print_in_menu(++i, "Add trollebus");
			print_in_menu(++i, "Add bus");
			print_in_menu(++i, "Add trum");

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
				if (menu_pointer == ++k);
			case 2:
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
			default:
				if (menu_pointer == ++k) {
					menu_pointer = 1;
					return;
				}
			}
		}
	} while (1);

	return;
}

void Menu::menu_delete_information(int role) {
	char c;
	menu_pointer = 1;
	do {
		int i = 0;
		system("cls");
		switch (role) {

		case 1:
			print_in_menu(++i, "Delete driver");
		case 2:
			print_in_menu(++i, "Delete trollebus");
			print_in_menu(++i, "Delete bus");
			print_in_menu(++i, "Delete trum");

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
				if (menu_pointer == ++k);
			case 2:
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
			default:
				if (menu_pointer == ++k) {
					menu_pointer = 1;
					return;
				}
			}
		}
	} while (1);

	return;
}

void Menu::menu_sort_information(int role) {
	char c;
	menu_pointer = 1;
	do {
		int i = 0;
		system("cls");
		switch (role) {
		case 1:
		case 2:
		case 3:
			print_in_menu(++i, "Sort drivers");
			print_in_menu(++i, "Sort trollebuses");
			print_in_menu(++i, "Sort buses");
			print_in_menu(++i, "Sort trums");

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
			case 2:
			case 3:
				if (menu_pointer == ++k) menu_sort_drivers();
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
			default:
				if (menu_pointer == ++k) {
					menu_pointer = 1;
					return;
				}
			}
		}
	} while (1);

	return;
}

void Menu::menu_print_information(int role){
	char c;
	menu_pointer = 1;
	do {
		int i = 0;
		system("cls");
		switch (role) {
		case 1:
		case 2:
		case 3:
			print_in_menu(++i, "Print drivers");
			print_in_menu(++i, "Print trollebuses");
			print_in_menu(++i, "Print buses");
			print_in_menu(++i, "Print trums");


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
			case 2:
			case 3:
				if (menu_pointer == ++k) show_drivers();
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
			default:
				if (menu_pointer == ++k) {
					menu_pointer = 1;
					return;
				}
			}
		}
	} while (1);

	return;
}

void Menu::menu_filtr_information(int role) {
	char c;
	menu_pointer = 1;
	do {
		int i = 0;
		system("cls");
		switch (role) {
		case 1:
		case 2:
		case 3:
			print_in_menu(++i, "Filtr drivers");
			print_in_menu(++i, "Filtr trollebuses");
			print_in_menu(++i, "Filtr buses");
			print_in_menu(++i, "Filtr trums");


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
			case 2:
			case 3:
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
				if (menu_pointer == ++k);
			default:
				if (menu_pointer == ++k) {
					menu_pointer = 1;
					return;
				}
			}
		}
	} while (1);
}

void Menu::menu_sort_drivers() {
	menu_pointer = 1;
	char c;
	do {
		system("cls");
		print_in_menu(1, "Sort by name");
		print_in_menu(2, "Sort by age");
		print_in_menu(3, "Sort by experience");
		print_in_menu(4, "Sort by salary");
		print_in_menu(5, "Back");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 5)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				sort_drivers((bool(*)(const void *, const void *))(Driver::comp_name));
				break;
			case 2:
				sort_drivers((bool(*)(const void *, const void *))(Driver::comp_age));
				break;
			case 3:
				sort_drivers((bool(*)(const void *, const void *))(Driver::comp_experience));
				break;
			case 4:
				sort_drivers((bool(*)(const void *, const void *))(Driver::comp_salary));
				break;
			case 5:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
}
