#pragma once
class Menu{

	int menu_pointer;

public:
	Menu();
	~Menu();
	void menu_authorization();
	void menu_user(int role);
	void print_in_menu(int pointer, const char *str);
};
