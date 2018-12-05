#pragma once
class Menu{

	int menu_pointer;

public:
	Menu();
	~Menu();
	void menu_authorization();
	void menu_user(int role);
	void menu_user_manage();
	void menu_add_information(int role);
	void menu_delete_information(int role);
	//void menu_work_with_information(int role);
	void menu_sort_information(int role);
	void menu_print_information(int role);
	void menu_filtr_information(int role);
	void print_in_menu(int pointer, const char *str);
};

