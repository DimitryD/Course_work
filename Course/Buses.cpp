﻿#include "Transport.h"

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
		>> bus.consumption
		>> bus.number_of_wheels
		>> bus.wheel_size
		>> bus.rent;
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
		<< bus.wheel_size << ' '
		<< bus.rent << endl;
}

void Autobus::show_header() {
	cout << setw(173) << setfill((char)196) << ' ' << endl;
	cout << setfill(' ') << '|'
		<< setw(8) << "Код" << '|'
		<< setw(20) << "Фамилию" << '|'
		<< setw(20) << "Имя" << '|'
		<< setw(20) << "Отчество" << '|'
		<< setw(10) << "Модель" << '|'
		<< setw(6) << "Год" << '|'
		<< setw(9) << "Пробег" << '|'
		<< setw(7) << "Маршрут" << '|'
		<< setw(15) << "Потребление" << '|'
		<< setw(13) << "Объём бака" << "|"
		<< setw(8) << "Кол-во колёс" << '|'
		<< setw(12) << "Размер колёс" << '|'
		<< setw(10) << "Занятость" << '|' << endl;
	cout << setw(173) << setfill((char)196) << ' ' << endl;
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
		<< setw(12) << wheel_size << '|' 
		<< setw(10) << (rent ? "Нанят" : "Свободен") << '|' << endl;
	cout << setw(173) << setfill((char)196) << ' ' << endl;
}

void Autobus::clear() {
	base_clear();
	wheel_clear();
	fuel_clear();
	rent = 0;
}

void Autobus::create() {
	base_create();
	fuel_create();
	wheel_create();
	cout << "Введите занятость:";
	enter_bool(rent);
	system("cls");
}

bool Autobus::check_rent() {
	return rent;
}

void Autobus::set_rent() {
	rent = 1;
}

bool operator==(Autobus trolleybus1, Autobus trolleybus2) { return trolleybus1.code == trolleybus2.code; }

bool operator==(Autobus trolleybus, string code) { return !code.compare(trolleybus.code); }