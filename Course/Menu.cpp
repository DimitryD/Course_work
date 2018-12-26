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
		print_in_menu(1, "Авторизация");
		print_in_menu(2, "Выход");
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
			print_in_menu(++i, "Управление пользователями");
		case 2:
			print_in_menu(++i, "Добавить данные");
			print_in_menu(++i, "Удалить данные");
			print_in_menu(++i, "Нанять автобус на завтра");
			print_in_menu(++i, "Нанять водителя на завтра");
		case 3:
			print_in_menu(++i, "Вывести данные");
			print_in_menu(++i, "Отсортироватьданные");
			print_in_menu(++i, "Отфильтровать данные");
			print_in_menu(++i, "Редактировать данные");
			print_in_menu(++i, "Найти данные");
		default:
			print_in_menu(++i, "Назад");
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
		print_in_menu(1, "Добавить пользователя");
		print_in_menu(2, "Редактировать пользователя");
		print_in_menu(3, "Удалить пользователя");
		print_in_menu(4, "Вывести пользователей");
		print_in_menu(5, "Назад");
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
				show_users();
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
			print_in_menu(++i, "Добавить водителя");
		case 2:
			print_in_menu(++i, "Добавить троллейбус");
			print_in_menu(++i, "Добавить автобус");
			print_in_menu(++i, "Добавить трамвай");

		default:
			print_in_menu(++i, "Назад");
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
			print_in_menu(++i, "Удалить водителя");
		case 2:
			print_in_menu(++i, "Удалить троллейбус");
			print_in_menu(++i, "Удалить автобус");
			print_in_menu(++i, "Удалить трамвай");

		default:
			print_in_menu(++i, "Назад");
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
			print_in_menu(++i, "Отсортировать водителей");
			print_in_menu(++i, "Отсортировать троллейбусы");
			print_in_menu(++i, "Отсортировать автобусы");
			print_in_menu(++i, "Отсортировать трамваи");

		default:
			print_in_menu(++i, "Назад");
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
			print_in_menu(++i, "Вывести водителей");
			print_in_menu(++i, "Вывести троллейбусы");
			print_in_menu(++i, "Вывести автобусы");
			print_in_menu(++i, "Вывести трамваи");


		default:
			print_in_menu(++i, "Назад");
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
			print_in_menu(++i, "Найти водителя");
			print_in_menu(++i, "Найти троллейбус");
			print_in_menu(++i, "Найти автобус");
			print_in_menu(++i, "Найти трамвай");

		default:
			print_in_menu(++i, "Назад");
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
			print_in_menu(++i, "Отфильтровать водителей");
			print_in_menu(++i, "Отфильтровать троллейбусы");
			print_in_menu(++i, "Отфильтровать автобусы");
			print_in_menu(++i, "Отфильтровать трамваи");

		default:
			print_in_menu(++i, "Назад");
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
		print_in_menu(1, "Отсортировать по имени");
		print_in_menu(2, "Отсортировать по возрасту");
		print_in_menu(3, "Отсортировать по стажу");
		print_in_menu(4, "Отсортировать по зарплате");
		print_in_menu(5, "Назад");
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
			print_in_menu(++i, "Редактировать водителя");
		case 2:
			print_in_menu(++i, "Редактировать троллейбус");
			print_in_menu(++i, "Редактировать автобус");
			print_in_menu(++i, "Редактировать трамвай");

		default:
			print_in_menu(++i, "Назад");
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
		print_in_menu(1, "Отфильтровать по возрасту");
		print_in_menu(2, "Отфильтровать по стажу");
		print_in_menu(3, "Отфильтровать по зарплате");
		print_in_menu(4, "Назад");
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
		print_in_menu(1, "Найти по фамилии");
		print_in_menu(2, "Найти по категории");
		print_in_menu(3, "Найти по маршруту");
		print_in_menu(4, "Найти по коду транспорта");
		print_in_menu(5, "Назад");
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
		print_in_menu(1, "Отфильтровать по году");
		print_in_menu(2, "Отфильтровать по пробегу");
		print_in_menu(3, "Отфильтровать по напряжению");
		print_in_menu(4, "Назад");
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
		print_in_menu(1, "Отсортировать по фамилии");
		print_in_menu(2, "Отсортировать по году");
		print_in_menu(3, "Отсортировать по пробегу");
		print_in_menu(4, "Отсортировать по напряжению");
		print_in_menu(5, "Назад");
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
		print_in_menu(1, "Найти по фамилии");
		print_in_menu(2, "Найти по модели");
		print_in_menu(3, "Найти по маршруту");
		print_in_menu(4, "Назад");
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
		print_in_menu(1, "Отфильтровать по году");
		print_in_menu(2, "Отфильтровать по пробегу");
		print_in_menu(3, "Отфильтровать по напряжению");
		print_in_menu(4, "Отфильтровать по размеру колёс");
		print_in_menu(5, "Отфильтровать по количеству колёс");
		print_in_menu(6, "Назад");
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
		print_in_menu(1, "Отсортировать по фамилии");
		print_in_menu(2, "Отсортировать по году");
		print_in_menu(3, "Отсортировать по пробегу");
		print_in_menu(4, "Отсортировать по напряжению");
		print_in_menu(5, "Назад");
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
		print_in_menu(1, "Найти по отчеству");
		print_in_menu(2, "Найти по модели");
		print_in_menu(3, "Найти по маршруту");
		print_in_menu(4, "Назад");
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
		print_in_menu(1, "Отфильтровать по году");
		print_in_menu(2, "Отфильтровать по пробегу");
		print_in_menu(3, "Отфильтровать по размеру колёс");
		print_in_menu(4, "Отфильтровать по количеству колёс");
		print_in_menu(5, "Отфильтровать по запасу топлива");
		print_in_menu(6, "Отфильтровать по потреблению топлива");
		print_in_menu(7, "Назад");
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
		print_in_menu(1, "Отсортировать по фамилии");
		print_in_menu(2, "Отсортировать по году");
		print_in_menu(3, "Отсортировать по пробегу");
		print_in_menu(4, "Отсортировать по запасу топлива");
		print_in_menu(5, "Отсортировать по потреблению топлива");
		print_in_menu(6, "Назад");
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
		print_in_menu(1, "Найти по отчеству");
		print_in_menu(2, "Найти по модели");
		print_in_menu(3, "Найти по маршруту");
		print_in_menu(4, "Назад");
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
