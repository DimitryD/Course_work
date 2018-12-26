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
		<< setw(8) << "Код" << '|'
		<< setw(20) << "Фамилия" << '|'
		<< setw(20) << "Имя" << '|'
		<< setw(20) << "Отчество" << '|'
		<< setw(10) << "Модель "<< '|'
		<< setw(6) << "Год" << '|'
		<< setw(9) << "Пробег" << '|'
		<< setw(7) << "Маршрут"<< '|'
		<< setw(10) << "Напряжение" << '|'
		<< setw(11) << "Тип колёс" << '|' << endl;
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
		<< setw(11) << (wheel_type?"Прорезиненные":"Непрорезиненные")<< '|' << endl;
	cout << setw(133) << setfill((char)196) << ' ' << endl;
}

void Tram::clear() {
	base_clear();
	electro_clear();
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

