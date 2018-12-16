#include "Menu.h"
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
	cout << ((pointer == menu_pointer) ? color<6, 15> : color<0, 15>) << str << endl;
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
			print_in_menu(++i, "Rent a bus tomorrow");
			print_in_menu(++i, "Rent a driver tomorrow");
		case 3:
			print_in_menu(++i, "Print information");
			print_in_menu(++i, "Sort information");
			print_in_menu(++i, "Filtr information");
			print_in_menu(++i, "Edit information");
			print_in_menu(++i, "Search information");
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
				if (menu_pointer == ++k) rent_bus();
				if (menu_pointer == ++k) rent_driver();
			case 3:
				if (menu_pointer == ++k) menu_print_information(role);
				if (menu_pointer == ++k) menu_sort_information(role);
				if (menu_pointer == ++k) menu_filtr_information(role);
				if (menu_pointer == ++k) menu_edit_information(role);
				if (menu_pointer == ++k) menu_search_information(role);
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
				add_information(user, "User.txt");
				break;
			case 2:
				edit_information(user, "User.txt", "login");
				break;
			case 3:
				delete_information(user, "User.txt", "login");
				break;
			case 4:
				//show_users();
				show_information(user, "User.txt");
				break;
			case 5:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
}

void Menu::menu_add_information(int role) {
	Driver driver;
	Tram tram;
	Autobus bus;
	Trolleybus trolleybus;
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
			print_in_menu(++i, "Add tram");

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
				if (menu_pointer == ++k) add_information(driver, "Drivers.txt");
			case 2:
				if (menu_pointer == ++k) add_information(trolleybus, "Trolleybuses.txt");
				if (menu_pointer == ++k) add_information(bus, "Buses.txt");
				if (menu_pointer == ++k) add_information(tram, "Trams.txt");
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
	Driver driver;
	Trolleybus trolleybus;
	Autobus bus;
	Tram tram;
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
			print_in_menu(++i, "Delete tram");

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
				if (menu_pointer == ++k) delete_information(driver, "Drivers.txt", "id");
			case 2:
				if (menu_pointer == ++k) delete_information(trolleybus, "Trolleybuses.txt", "code");
				if (menu_pointer == ++k) delete_information(bus, "Buses.txt", "code");
				if (menu_pointer == ++k) delete_information(tram, "Trams.txt", "code");
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
			print_in_menu(++i, "Sort trams");

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
				if (menu_pointer == ++k) menu_sort_trolleybuses();
				if (menu_pointer == ++k) menu_sort_buses();
				if (menu_pointer == ++k) menu_sort_trams();
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
	Driver driver;
	Trolleybus trolleybus;
	Autobus bus;
	Tram tram;
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
			print_in_menu(++i, "Print trams");


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
				if (menu_pointer == ++k) show_information(driver, "Drivers.txt");
				if (menu_pointer == ++k) show_information(trolleybus, "Trolleybuses.txt");
				if (menu_pointer == ++k) show_information(bus, "Buses.txt");
				if (menu_pointer == ++k) show_information(tram, "Trams.txt");
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

void Menu::menu_search_information(int role) {
	Driver driver;
	char c;
	menu_pointer = 1;
	do {
		int i = 0;
		system("cls");
		switch (role) {
		case 1:
		case 2:
		case 3:
			print_in_menu(++i, "Search driver");
			print_in_menu(++i, "Search trollebus");
			print_in_menu(++i, "Search bus");
			print_in_menu(++i, "Search tram");

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
				if (menu_pointer == ++k) menu_search_drivers();
				if (menu_pointer == ++k) menu_search_trolleybuses();
				if (menu_pointer == ++k) menu_search_buses();
				if (menu_pointer == ++k) menu_search_trams();
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
	menu_pointer = 1;;
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
			print_in_menu(++i, "Filtr trams");

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
				if (menu_pointer == ++k) menu_filtr_drivers();
				if (menu_pointer == ++k) menu_filtr_trolleybuses();
				if (menu_pointer == ++k) menu_filtr_buses();
				if (menu_pointer == ++k) menu_filtr_trams();
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
	Driver driver;
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
				sort_information(driver,"Drivers.txt",(bool(*)(const void *, const void *))(Driver::comp_name));
				break;
			case 2:
				sort_information(driver, "Drivers.txt", (bool(*)(const void *, const void *))(Driver::comp_age));
				break;
			case 3:
				sort_information(driver, "Drivers.txt", (bool(*)(const void *, const void *))(Driver::comp_experience));
				break;
			case 4:
				sort_information(driver, "Drivers.txt", (bool(*)(const void *, const void *))(Driver::comp_salary));
				break;
			case 5:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
}

void Menu::menu_edit_information(int role) {
	char c;
	Driver driver;
	Trolleybus trolleybus;
	Tram tram;
	Autobus bus;
	menu_pointer = 1;
	do {
		int i = 0;
		system("cls");
		switch (role) {

		case 1:
			print_in_menu(++i, "Edit driver");
		case 2:
			print_in_menu(++i, "Edit trollebus");
			print_in_menu(++i, "Edit bus");
			print_in_menu(++i, "Edit tram");

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
				if (menu_pointer == ++k) edit_information(driver, "Drivers.txt", "id");
			case 2:
				if (menu_pointer == ++k) edit_information(trolleybus, "Trolleybuses.txt", "code");
				if (menu_pointer == ++k) edit_information(bus, "Buses.txt", "code");
				if (menu_pointer == ++k) edit_information(tram, "Trams.txt", "code");
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

void Menu::menu_filtr_drivers() {
	menu_pointer = 1;
	char c;
	Driver driver;
	do {
		system("cls");
		print_in_menu(1, "Filtr by age");
		print_in_menu(2, "Filtr by experience");
		print_in_menu(3, "Filtr by salary");
		print_in_menu(4, "Back");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 4)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				filtr_information(driver, "Drivers.txt", (void(*)(const void *, string, string))(Driver::filtr_age));
				break;
			case 2:
				filtr_information(driver, "Drivers.txt", (void(*)(const void *, string, string))(Driver::filtr_experience));
				break;
			case 3:
				filtr_information(driver, "Drivers.txt", (void(*)(const void *, string, string))(Driver::filtr_salary));
				break;
			case 4:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
	return;
}

void Menu::menu_search_drivers() {
	menu_pointer = 1;
	char c;
	Driver driver;
	do {
		system("cls");
		print_in_menu(1, "Search by surname");
		print_in_menu(2, "Search by category");
		print_in_menu(3, "Search by itinerary");
		print_in_menu(4, "Search by transport code");
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
				search_information(driver, "Drivers.txt", (void(*)(const void *, string))Driver::search_surname);
				break;
			case 2:
				search_information(driver, "Drivers.txt", (void(*)(const void *, string))Driver::search_category);
				break;
			case 3:
				search_information(driver, "Drivers.txt", (void(*)(const void *, string))Driver::search_itinerary);
				break;
			case 4:
				search_information(driver, "Drivers.txt", (void(*)(const void *, string))Driver::search_transport_code);
				break;
			case 5:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
	return;
}

void Menu::menu_filtr_trams() {
	menu_pointer = 1;
	char c;
	Tram tram;
	do {
		system("cls");
		print_in_menu(1, "Filtr by year");
		print_in_menu(2, "Filtr by distance");
		print_in_menu(3, "Filtr by amperage");
		print_in_menu(4, "Back");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 4)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				filtr_information(tram, "Trams.txt", (void(*)(const void *, string, string))(Transport::filtr_year));
				break;
			case 2:
				filtr_information(tram, "Trams.txt", (void(*)(const void *, string, string))(Transport::filtr_distance));
				break;
			case 3:
				filtr_information(tram, "Trams.txt", (void(*)(const void *, string, string))(Electro::filtr_amperage));
				break;
			case 4:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
	return;
}

void Menu::menu_sort_trams() {
	menu_pointer = 1;
	char c;
	Tram tram;
	do {
		system("cls");
		print_in_menu(1, "Sort by surname");
		print_in_menu(2, "Sort by year");
		print_in_menu(3, "Sort by distance");
		print_in_menu(4, "Sort by amperage");
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
				sort_information(tram, "Trams.txt", (bool(*)(const void *, const void *))(Transport::comp_surname));
				break;
			case 2:
				sort_information(tram, "Trams.txt", (bool(*)(const void *, const void *))(Transport::comp_year));
				break;
			case 3:
				sort_information(tram, "Trams.txt", (bool(*)(const void *, const void *))(Transport::comp_distance));
				break;
			case 4:
				sort_information(tram, "Trams.txt", (bool(*)(const void *, const void *))(Electro::comp_amperage));
				break;
			case 5:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
}

void Menu::menu_search_trams() {
	menu_pointer = 1;
	char c;
	Tram tram;
	do {
		system("cls");
		print_in_menu(1, "Search by surname");
		print_in_menu(2, "Search by model");
		print_in_menu(3, "Search by route");
		print_in_menu(4, "Back");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 4)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				search_information(tram, "Trams.txt", (void(*)(const void *, string))Transport::search_surname);
				break;
			case 2:
				search_information(tram, "Trams.txt", (void(*)(const void *, string))Transport::search_model);
				break;
			case 3:
				search_information(tram, "Trams.txt", (void(*)(const void *, string))Transport::search_route);
				break;
			case 4:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
	return;
}

void Menu::menu_filtr_trolleybuses() {
	menu_pointer = 1;
	char c;
	Trolleybus trolleybus;
	do {
		system("cls");
		print_in_menu(1, "Filtr by year");
		print_in_menu(2, "Filtr by distance");
		print_in_menu(3, "Filtr by amperage");
		print_in_menu(4, "Filtr by wheel_size");
		print_in_menu(5, "Filtr by wheel_number");
		print_in_menu(6, "Back");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 6)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				filtr_information(trolleybus, "Trolleybuses.txt", (void(*)(const void *, string, string))(Transport::filtr_year));
				break;
			case 2:
				filtr_information(trolleybus, "Trolleybuses.txt", (void(*)(const void *, string, string))(Transport::filtr_distance));
				break;
			case 3:
				filtr_information(trolleybus, "Trolleybuses.txt", (void(*)(const void *, string, string))(Electro::filtr_amperage));
				break;
			case 4:
				filtr_information(trolleybus, "Trolleybuses.txt", (void(*)(const void *, string, string))(Wheel::filtr_size));
				break;
			case 5:
				filtr_information(trolleybus, "Trolleybuses.txt", (void(*)(const void *, string, string))(Wheel::filtr_number));
				break;
			case 6:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
	return;
}

void Menu::menu_sort_trolleybuses() {
	menu_pointer = 1;
	char c;
	Trolleybus trolleybus;
	do {
		system("cls");
		print_in_menu(1, "Sort by surname");
		print_in_menu(2, "Sort by year");
		print_in_menu(3, "Sort by distance");
		print_in_menu(4, "Sort by amperage");
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
				sort_information(trolleybus, "Trolleybuses.txt", (bool(*)(const void *, const void *))(Transport::comp_surname));
				break;
			case 2:
				sort_information(trolleybus, "Trolleybuses.txt" ,(bool(*)(const void *, const void *))(Transport::comp_year));
				break;
			case 3:
				sort_information(trolleybus, "Trolleybuses.txt" ,(bool(*)(const void *, const void *))(Transport::comp_distance));
				break;
			case 4:
				sort_information(trolleybus, "Trolleybuses.txt" ,(bool(*)(const void *, const void *))(Electro::comp_amperage));
				break;
			case 5:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
}

void Menu::menu_search_trolleybuses() {
	menu_pointer = 1;
	char c;
	Trolleybus trolleybus;
	do {
		system("cls");
		print_in_menu(1, "Search by surname");
		print_in_menu(2, "Search by model");
		print_in_menu(3, "Search by route");
		print_in_menu(4, "Back");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 4)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				search_information(trolleybus, "Trolleybuses.txt", (void(*)(const void *, string))Transport::search_surname);
				break;
			case 2:
				search_information(trolleybus, "Trolleybuses.txt", (void(*)(const void *, string))Transport::search_model);
				break;
			case 3:
				search_information(trolleybus, "Trolleybuses.txt", (void(*)(const void *, string))Transport::search_route);
				break;
			case 4:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
	return;
}

void  Menu::menu_filtr_buses() {
	menu_pointer = 1;
	char c;
	Autobus bus;
	do {
		system("cls");
		print_in_menu(1, "Filtr by year");
		print_in_menu(2, "Filtr by distance");
		print_in_menu(3, "Filtr by wheel_size");
		print_in_menu(4, "Filtr by wheel_number");
		print_in_menu(5, "Filtr by capacity");
		print_in_menu(6, "Filtr by consumption");
		print_in_menu(7, "Back");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 7)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				filtr_information(bus, "Buses.txt", (void(*)(const void *, string, string))(Transport::filtr_year));
				break;
			case 2:
				filtr_information(bus, "Buses.txt", (void(*)(const void *, string, string))(Transport::filtr_distance));
				break;
			case 3:
				filtr_information(bus, "Buses.txt", (void(*)(const void *, string, string))(Wheel::filtr_size_bus));
				break;
			case 4:
				filtr_information(bus, "Buses.txt", (void(*)(const void *, string, string))(Wheel::filtr_number_bus));
				break;
			case 5:
				filtr_information(bus, "Buses.txt", (void(*)(const void *, string, string))(Fuel::filtr_capacity));
				break;
			case 6:
				filtr_information(bus, "Buses.txt", (void(*)(const void *, string, string))(Fuel::filtr_consumption));
				break;
			case 7:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
	return;
}

void  Menu::menu_sort_buses() {
	menu_pointer = 1;
	char c;
	Autobus bus;
	do {
		system("cls");
		print_in_menu(1, "Sort by surname");
		print_in_menu(2, "Sort by year");
		print_in_menu(3, "Sort by distance");
		print_in_menu(4, "Sort by capacity");
		print_in_menu(5, "Sort by consumption");
		print_in_menu(6, "Back");
		c = _getch();

		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 6)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				sort_information(bus, "Buses.txt", (bool(*)(const void *, const void *))(Transport::comp_surname));
				break;
			case 2:
				sort_information(bus, "Buses.txt", (bool(*)(const void *, const void *))(Transport::comp_year));
				break;
			case 3:
				sort_information(bus, "Buses.txt", (bool(*)(const void *, const void *))(Transport::comp_distance));
				break;
			case 4:
				sort_information(bus, "Buses.txt", (bool(*)(const void *, const void *))(Fuel::comp_capacity));
				break;
			case 5:
				sort_information(bus, "Buses.txt", (bool(*)(const void *, const void *))(Fuel::comp_consumption));
				break;
			case 6:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
}

void Menu::menu_search_buses() {
	menu_pointer = 1;
	char c;
	Autobus bus;
	do {
		system("cls");
		print_in_menu(1, "Search by surname");
		print_in_menu(2, "Search by model");
		print_in_menu(3, "Search by route");
		print_in_menu(4, "Back");
		c = _getch();
		if (c == 72 && menu_pointer > 1)
			menu_pointer--;
		if (c == 80 && menu_pointer < 4)
			menu_pointer++;
		if (c == '\r') {
			system("cls");
			switch (menu_pointer) {
			case 1:
				search_information(bus, "Buses.txt", (void(*)(const void *, string))Transport::search_surname);
				break;
			case 2:
				search_information(bus, "Buses.txt",(void(*)(const void *, string))Transport::search_model);
				break;
			case 3:
				search_information(bus, "Buses.txt", (void(*)(const void *, string))Transport::search_route);
				break;
			case 4:
				menu_pointer = 1;
				return;
			}
		}
	} while (1);
}
