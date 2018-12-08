#pragma once
class Menu{

	int menu_pointer;

public:
	Menu();
	~Menu();

	//Utilities
	void menu_authorization();
	void print_in_menu(int pointer, const char *str);


	//Manages
	void menu_user(int role);
	void menu_user_manage();
	void menu_sort_information(int role);
	void menu_filtr_information(int role);
	void menu_edit_information(int role);
	void menu_delete_information(int role);
	void menu_add_information(int role);
	void menu_search_information(int role);
	void menu_print_information(int role);
	//Drivers
	void menu_filtr_drivers();
	void menu_sort_drivers();
	void menu_search_drivers();

	void menu_filtr_trams();
	void menu_sort_trams();
	void menu_search_trams();
};

