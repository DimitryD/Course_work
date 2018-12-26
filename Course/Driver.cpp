#include "Driver.h"

Driver::Driver(){}

Driver::~Driver(){}

ostream& operator <<(ostream& out, Driver &driver) {
	return out << driver.id << ' '
		<< driver.name << ' '
		<< driver.surname << ' '
		<< driver.patronymic << ' '
		<< driver.age << ' '
		<< driver.experience << ' '
		<< driver.category << ' '
		<< driver.itinerary << ' '
		<< driver.salary << ' '
		<< driver.telephone_number << ' '
		<< driver.transport_code<<' '
		<< driver.rent << endl;
}

istream& operator >>(istream& in, Driver &driver) {
	return in >> driver.id
		>> driver.name
		>> driver.surname
		>> driver.patronymic
		>> driver.age
		>> driver.experience
		>> driver.category
		>> driver.itinerary
		>> driver.salary
		>> driver.telephone_number
		>> driver.transport_code
		>> driver.rent;
}

void Driver::show() {
	cout << setfill(' ') << '|'
		<< setw(8) << id << '|'
		<< setw(20) << surname << '|'
		<< setw(20) << name << '|'
		<< setw(20) << patronymic << '|'
		<< setw(5) << age << '|'
		<< setw(12) << experience << '|'
		<< setw(10) << category << '|'
		<< setw(11) << itinerary << '|'
		<< setw(8) << salary << '|'
		<< setw(18) << telephone_number << '|'
		<< setw(16) << transport_code << '|' 
		<<setw(10)<< (rent ? "Нанят" : "Свободен" )<<'|' << endl;
	cout << setw(172) << setfill((char)196) << ' ' <<endl;
}

void Driver::show_header() {
	cout << setw(172) << setfill((char)196) << ' ' << endl;
	cout << setfill(' ') << '|'
		<< setw(8) << "Код" << '|'
		<< setw(20) << "Фамилия" << '|'
		<< setw(20) << "Имя" << '|'
		<< setw(20) << "Отчество" << '|'
		<< setw(5) << "Врзраст" << '|'
		<< setw(12) << "Стаж" << '|'
		<< setw(10) << "Категория" << '|'
		<< setw(11) << "Маршрут" << '|'
		<< setw(8) << "Зарплата" << '|'
		<< setw(18) << "Номер телефона" << '|'
		<< setw(16) << "Код транспорта" << '|'
		<< setw(10) << "Занятость" << '|' << endl;
	cout << setw(172) << setfill((char)196) << ' ' << endl;
}

void Driver::create() {

	cout << "Введите код:";
	enter_number(id, 7);
	cout << "Введите фамилию:";
	cin >> surname;
	cout << "Введите имя:";
	cin >> name;
	cout << "Введите отчество:";
	cin >> patronymic;
	cout << "Введите возраст:";
	enter_number(age, 2);
	cout << "Введите стаж:";
	enter_number(experience, 2);
	cout << "Введите категорию:";
	cin >> category;
	cout << "Введите маршрут:";
	cin >> itinerary;
	cout << "Введите зарплату:";
	enter_number(salary, 5);
	cout << "Введите номер телефона:";
	cin >> telephone_number;
	cout << "Введите код транспорта:";
	cin >> transport_code;
	cout << "Занятость:";
	enter_bool(rent);
	system("cls");
	return;
}

void Driver::clear() {
	name.clear();
	surname.clear();
	patronymic.clear();
	age = 0;
	experience = 0;
	category.clear();
	itinerary.clear();//route
	salary = 0;
	telephone_number.clear();
	transport_code.clear();
	id = -1;
	rent = 0;

}

bool Driver::comp_name(Driver &driver1, Driver &driver2) {
	return driver1.surname.compare(driver2.surname) > 0 ? 0 : 1;
}

bool Driver::comp_age(Driver &driver1, Driver &driver2) {
	return driver1.age > driver2.age ? 1 : 0;
}

bool Driver::comp_experience(Driver &driver1, Driver &driver2) {
	return driver1.experience > driver2.experience ? 1 : 0;
}

bool Driver::comp_salary(Driver &driver1, Driver &driver2) {
	return driver1.salary > driver2.salary ? 1 : 0;
}

void Driver::filtr_age(Driver &driver, string first, string second) {
	try {
		if (driver.age >= stoi(first) && driver.age <= stoi(second))
			driver.show();
	}
	catch (...) {
		//cout << "Bad parametr" << endl;
	}

}

void Driver::filtr_experience(Driver &driver, string first, string second) {
	try {
		if (driver.experience >= stoi(first) && driver.experience <= stoi(second))
			driver.show();
	}
	catch (...) {
		
	}
}

void Driver::filtr_salary(Driver &driver, string first, string second) {
	try {
		if (driver.salary >= stoi(first) && driver.salary <= stoi(second))
			driver.show();
	}
	catch (...) {
		
	}
}

void Driver::search_surname(Driver &driver, string word) {
	if (!driver.surname.compare(word))
		driver.show();
}

void Driver::search_category(Driver &driver, string word) {
	if (driver.category.find(word, 0))
		driver.show();
}

void Driver::search_itinerary(Driver &driver, string word) {
	if (!driver.itinerary.compare(word))
		driver.show();
}

void Driver::search_transport_code(Driver &driver, string word) {
	if (!driver.transport_code.compare(word))
		driver.show();
}

Driver::operator const void*() { 
	return reinterpret_cast<const void*>(this); 
}

bool operator==(Driver driver1, Driver driver2) {
	return driver1.id == driver2.id;
}

bool operator==(Driver driver, string id) {
	return !id.compare(to_string(driver.id));
}

string Driver::get_name() { return name; }

string Driver::get_surname() { return surname; }

string Driver::get_patronymic() { return patronymic; }

string Driver::get_route() { return itinerary; }

bool Driver::check_rent() {
	return rent;
}

void Driver::set_rent() {
	rent = 1;
}
