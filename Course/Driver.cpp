#include "Driver.h"

Driver::Driver(){}

Driver::~Driver(){}

ostream& operator <<(ostream& out, Driver &driver) {
	return out << driver.name << ' '
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
	return in >> driver.name
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
	cout << setw(152) << setfill((char)196) << ' ' <<endl;
}

void Driver::show_header() {
	cout << setw(152) << setfill((char)196) << ' ' << endl;
	cout << setfill(' ') << '|'
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
	cout << setw(152) << setfill((char)196) << ' ' << endl;
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
