#include "Transport.h"

istream& operator >>(istream& in, Tram &tram) {
	return in >> tram.code
		>> tram.surname
		>>tram.name
		>>tram.patronymic
		>> tram.model
		>> tram.year
		>> tram.distance
		>> tram.route
		>> tram.amperage
		>> tram.wheel_type;
}

ostream& operator <<(ostream& out, Tram &tram) {
	return out << tram.code << ' '
		<< tram.surname << ' '
		<< tram.name << ' '
		<< tram.patronymic<< ' '
		<< tram.model << ' '
		<< tram.year << ' '
		<< tram.distance << ' '
		<< tram.route << ' '
		<< tram.amperage << ' '
		<< tram.wheel_type << endl;
}

void Tram::show_header() {
	cout << setw(133) << setfill((char)196) << ' ' << endl;
	cout << setfill(' ') << '|'
		<< setw(8) << "code" << '|'
		<< setw(20) << "Surname" << '|'
		<< setw(20) << "Name" << '|'
		<< setw(20) << "Patronymic" << '|'
		<< setw(10) << "model "<< '|'
		<< setw(6) << "year" << '|'
		<< setw(9) << "distance" << '|'
		<< setw(7) << "route"<< '|'
		<< setw(10) << "amperage" << '|'
		<< setw(11) << "wheel_type" << '|' << endl;
	cout << setw(133) << setfill((char)196) << ' ' << endl;
}

void Tram::show() {
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
		<< setw(11) << (wheel_type?"Rubber":"Not rubber")<< '|' << endl;
	cout << setw(133) << setfill((char)196) << ' ' << endl;
}

void Tram::clear() {
	base_clear();
	amperage = 0;
	wheel_type = 0;
}

void Tram::create() {
	base_create();
	electro_create();
	cout << "Rubber wheels?[1/0]:";
	enter_bool(wheel_type);
	system("cls");
}

bool operator==(Tram tram1, Tram tram2) { return tram1.code == tram2.code; }

bool operator==(Tram tram, string code) { return !code.compare(tram.code); }

