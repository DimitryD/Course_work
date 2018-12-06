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
		<< driver.transport_code << endl;
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
		>> driver.transport_code;
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
		<< setw(16) << transport_code << '|' << endl;
	cout << setw(161) << setfill((char)196) << ' ' <<endl;
}

void Driver::show_header() {
	cout << setw(161) << setfill((char)196) << ' ' << endl;
	cout << setfill(' ') << '|'
		<< setw(8) << "Id" << '|'
		<< setw(20) << "Surname" << '|'
		<< setw(20) << "Name" << '|'
		<< setw(20) << "Patronymic" << '|'
		<< setw(5) << "Age" << '|'
		<< setw(12) << "Experience" << '|'
		<< setw(10) << "Category" << '|'
		<< setw(11) << "Itinerary" << '|'
		<< setw(8) << "Salary" << '|'
		<< setw(18) << "Telephone number" << '|'
		<< setw(16) << "Transport code" << '|' << endl;
	cout << setw(161) << setfill((char)196) << ' ' << endl;
}

void Driver::create() {

	cout << "Enter id:";
	enter_number(id, 7);
	cout << "Enter surname:";
	cin >> surname;
	cout << "Enter name:";
	cin >> name;
	cout << "Enter patronymic:";
	cin >> patronymic;
	cout << "Enter age:";
	enter_number(age, 2);
	cout << "Enter experience:";
	enter_number(experience, 2);
	cout << "Enter category:";
	cin >> category;
	cout << "Enter itinerary:";
	cin >> itinerary;
	cout << "Enter salary";
	enter_number(salary, 5);
	cout << "Enter telephone number:";
	cin >> telephone_number;
	cout << "Enter transport code:";
	cin >> transport_code;
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

Driver::operator const void*() { 
	return reinterpret_cast<const void*>(this); 
}

bool operator==(Driver driver1, Driver driver2) {
	return driver1.id == driver2.id;
}