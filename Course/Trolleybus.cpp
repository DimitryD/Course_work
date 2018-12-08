#include "Transport.h"

istream& operator >>(istream& in, Trolleybus &trolleybus) {
	return in >> trolleybus.code
		>> trolleybus.surname
		>> trolleybus.name
		>> trolleybus.patronymic
		>> trolleybus.model
		>> trolleybus.year
		>> trolleybus.distance
		>> trolleybus.route
		>> trolleybus.amperage
		>> trolleybus.number_of_wheels
		>> trolleybus.wheel_size;
}

ostream& operator <<(ostream& out, Trolleybus &trolleybus) {
	return out << trolleybus.code << ' '
		<< trolleybus.surname << ' '
		<< trolleybus.name << ' '
		<< trolleybus.patronymic << ' '
		<< trolleybus.model << ' '
		<< trolleybus.year << ' '
		<< trolleybus.distance << ' '
		<< trolleybus.route << ' '
		<< trolleybus.amperage << ' '
		<< trolleybus.number_of_wheels << ' '
		<< trolleybus.wheel_size << endl;
}

void Trolleybus::show_header() {
	cout << setw(143) << setfill((char)196) << ' ' << endl;
	cout << setfill(' ') << '|'
		<< setw(8) << "code" << '|'
		<< setw(20) << "Surname" << '|'
		<< setw(20) << "Name" << '|'
		<< setw(20) << "Patronymic" << '|'
		<< setw(10) << "model " << '|'
		<< setw(6) << "year" << '|'
		<< setw(9) << "distance" << '|'
		<< setw(7) << "route" << '|'
		<< setw(10) << "amperage" << '|'
		<< setw(8) << "wheels" << '|' 
		<< setw(12) << "wheel size" << '|' << endl;
	cout << setw(143) << setfill((char)196) << ' ' << endl;
}

void Trolleybus::show() {
	cout << setfill(' ') << '|'
		<< setw(8) << code << '|'
		<< setw(20) << surname << '|'
		<< setw(20) << name << '|'
		<< setw(20) << patronymic << '|'
		<< setw(10) << model << '|'
		<< setw(6) << year << '|'
		<< setw(9) << distance << '|'
		<< setw(7) << route << '|'
		<< setw(10) << amperage << '|'
		<< setw(8) << number_of_wheels<< '|' 
		<< setw(12) << wheel_size << '|' << endl;
	cout << setw(143) << setfill((char)196) << ' ' << endl;
}

void Trolleybus::clear() {
	base_clear();
	wheel_clear();
	electro_clear();
}

void Trolleybus::create() {
	base_create();
	electro_create();
	wheel_create();
	system("cls");
}

bool operator==(Trolleybus trolleybus1, Trolleybus trolleybus2) { return trolleybus1.code == trolleybus2.code; }

bool operator==(Trolleybus trolleybus, string code) { return !code.compare(trolleybus.code); }
