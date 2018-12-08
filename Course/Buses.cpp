#include "Transport.h"

istream& operator >>(istream& in, Autobus &bus) {
	return in >> bus.code
		>> bus.surname
		>> bus.name
		>> bus.patronymic
		>> bus.model
		>> bus.year
		>> bus.distance
		>> bus.route
		>> bus.fuel_capacity
		>>bus.consumption
		>> bus.number_of_wheels
		>> bus.wheel_size;
}

ostream& operator <<(ostream& out, Autobus &bus) {
	return out << bus.code << ' '
		<< bus.surname << ' '
		<< bus.name << ' '
		<< bus.patronymic << ' '
		<< bus.model << ' '
		<< bus.year << ' '
		<< bus.distance << ' '
		<< bus.route << ' '
		<< bus.consumption << ' '
		<< bus.number_of_wheels << ' '
		<< bus.number_of_wheels << ' '
		<< bus.wheel_size << endl;
}

void Autobus::show_header() {
	cout << setw(162) << setfill((char)196) << ' ' << endl;
	cout << setfill(' ') << '|'
		<< setw(8) << "code" << '|'
		<< setw(20) << "Surname" << '|'
		<< setw(20) << "Name" << '|'
		<< setw(20) << "Patronymic" << '|'
		<< setw(10) << "model " << '|'
		<< setw(6) << "year" << '|'
		<< setw(9) << "distance" << '|'
		<< setw(7) << "route" << '|'
		<< setw(15) << "fuel capacity" << '|'
		<< setw(13) << "consumption" << "|"
		<< setw(8) << "wheels" << '|'
		<< setw(12) << "wheel size" << '|' << endl;
	cout << setw(162) << setfill((char)196) << ' ' << endl;
}

void Autobus::show() {
	cout << setfill(' ') << '|'
		<< setw(8) << code << '|'
		<< setw(20) << surname << '|'
		<< setw(20) << name << '|'
		<< setw(20) << patronymic << '|'
		<< setw(10) << model << '|'
		<< setw(6) << year << '|'
		<< setw(9) << distance << '|'
		<< setw(7) << route << '|'
		<< setw(15) << fuel_capacity << '|'
		<< setw(13) << consumption << '|'
		<< setw(8) << number_of_wheels << '|'
		<< setw(12) << wheel_size << '|' << endl;
	cout << setw(162) << setfill((char)196) << ' ' << endl;
}

void Autobus::clear() {
	base_clear();
	wheel_clear();
	fuel_clear();
}

void Autobus::create() {
	base_create();
	fuel_create();
	wheel_create();
	system("cls");
}

bool operator==(Autobus trolleybus1, Autobus trolleybus2) { return trolleybus1.code == trolleybus2.code; }

bool operator==(Autobus trolleybus, string code) { return !code.compare(trolleybus.code); }