#include "Stuff.h"

template<int txt, int bg>
ostream& color(ostream &text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}

template <typename T>
void enter_number(T & variable, int length) {
	if (strcmp(typeid(variable).name(), "int") == 0) {
		char c, mas[10];
		int i = 0;
		while (1) {
			do {
				c = _getch();
			} while (!(c >= 48 && c <= 57) && c != '\r' && c != '\b');
			if (c != '\r' && c != '\b'&& i != length) {
				mas[i] = c;
				i++;
				cout << c;
			}
			else if (c == '\b' && i != 0) {
				cout << "\b \b";
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		mas[i] = '\0';
		variable = atoi(mas);
		cout << '\n';
		return;
	}
	else if (strcmp(typeid(variable).name(), "float") == 0) {
		char c, mas[10];
		int i = 0, j = 0, number = 4;
		while (1) {
			do {
				c = _getch();
			} while (!(c >= 48 && c <= 57) && c != ',' && c != '\r' && c != '\b');
			if (c != '\r' && c != '\b' &&c != ',' && j < 4) {
				mas[i] = c;
				i++;
				j++;
				printf("%c", c);
			}
			else {
				if (c == '\b' && i != 0 && c != ',') {
					printf("\b \b");
					i--;
					j--;
				}
				else if (c == '\r' && i != 0 && c != ',') {
					break;
				}
				else if (c == ',' && (j > 0 && j < 5)) {
					mas[i] = c;
					i++;
					j = 2;
					printf("%c", c);
				}
			}
		}
		mas[i] = '\0';
		variable = atof(mas);
		puts("\r");
		cout << "\n" << variable << endl;
		system("pause");
		return;
	}
}

template <class T>
void read_information_from_file(list<T> &list, string filename) {
	T tmp;
	ifstream file(filename);
	if (!file) {
		cout << "Ошибка";
		_getch();
		exit(1);
	}
	while (file >> tmp) {
		list.push_back(tmp);
	}
	return;
}

template <class T>
void write_information_in_file(list<T> &list, string filename) {
	ofstream file(filename);
	if (!file) {
		cout << "Ошибка";
		_getch();
		exit(1);
	}
	for (auto tmp : list)
		file << tmp;
	return;
}

template <class T>
void show_information(T variable, string filename) {
	system("cls");
	list <T> list;
	read_information_from_file(list, filename);
	list.back().show_header();
	for (auto tmp : list)
		tmp.show();
	cout << "Нажмите любую клавишу...";
	_getch();
}

template <class T>
void delete_information(T variable, string filename, string what) {
	system("cls");
	string what_delete;
	cout << "Введите " << what << ':';
	cin >> what_delete;
	list<T> list;
	read_information_from_file(list, filename);
	list.remove_if([what_delete](T obj) { return obj == what_delete; });
	write_information_in_file(list, filename);
	system("cls");
	return;
}

template <class T>
void add_information(T variable, string filename) {
	system("cls");
	T tmp;
	do {
		tmp.clear();
		tmp.create();
	} while (check_information(tmp, filename));
	ofstream file(filename, ofstream::app);
	if (!file) {
		cout << "Ошибка";
		_getch();
		exit(1);
	}
	file << tmp;
	return;
}

template <class T>
bool check_information(T check, string filename) {
	list<T> list;
	read_information_from_file(list, filename);
	for (T tmp : list) {
		if (check == tmp) {
			cout << "Такая запись уже существует. Попробуйте ещё раз" << endl;
			return true;
		}
	}
	return false;
}

template <class T>
void edit_information(T variable, string filename, string what) {
	system("cls");
	T new_inf;
	string what_to_edit;
	bool flag = 0;
	cout << "Введите " << what << ':';
	cin >> what_to_edit;
	list <T> list;
	read_information_from_file(list, filename);
	for (auto tmp : list)
		if (tmp == what_to_edit)
			flag = 1;
	system("cls");
	if (flag) {
		list.remove_if([what_to_edit](T obj) { return obj == what_to_edit; });
		new_inf.create();
		list.push_back(new_inf);
		write_information_in_file(list, filename);
	}
	else {
		cout << "Такой записи не существует";
		_getch();
	}
	system("cls");
	return;
}

template <class T>
void sort_information(T variable, string filename, bool(*comparator)(const void *, const void *)) {
	system("cls");
	list <T> list;
	read_information_from_file(list, filename);
	list.sort(comparator);
	write_information_in_file(list, filename);
	show_information(list.back(), filename);
}

template <class T>
void filtr_information(T variable,string filename, void(*filtrator)(const void *,string,string)) {
	system("cls");
	list<T> list;
	string first, second;
	read_information_from_file(list, filename);
	cout << "Enter first:";
	cin >> first;
	cout << "Enter second:";
	cin >> second;
	system("cls");
	T::show_header();
	for_each(list.begin(), list.end(), [first, second, filtrator](T tmp) {filtrator(tmp, first, second); });
	cout << "Нажмите любую клавишу...";
	_getch();
	return;
}

template <class T>
void search_information(T variable, string filename, void(*searcher)(const void*, string)) {
	system("cls");
	list<T> list;
	string word;
	read_information_from_file(list, filename);
	cout << "Введите искомое значение:";
	cin >> word;
	system("cls");
	T::show_header();
	for_each(list.begin(), list.end(), [word, searcher](T tmp) {searcher(tmp, word); });
	cout << "Нажмите любую клавишу...";
	_getch();
	return;
}
