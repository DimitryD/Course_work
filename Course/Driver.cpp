#include "Driver.h"



Driver::Driver(){
}


Driver::~Driver(){
}

ostream& operator <<(ostream& out, Driver &driver) {
	return out << driver.name << ' '
		<< driver.surname << ' '
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
		<< setw(20) << name << '|'
		<< setw(20) << surname << '|'
		<< setw(3) << age << '|'
		<< setw(3) << experience << '|'
		<< setw(5) << category << '|'
		<< setw(5) << itinerary << '|'
		<< setw(5) << salary << '|'
		<< setw(15) << telephone_number << '|'
		<< setw(5) << transport_code << '|' << endl;
	cout << setw(92) << setfill((char)196) << ' ' <<endl;
}