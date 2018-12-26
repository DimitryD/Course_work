#include "Transport.h"


Transport::Transport(){}
Electro::Electro(){}
Transport::~Transport(){}
Electro::~Electro(){}

void Transport::base_clear() {
	code.clear();
	surname.clear();
	name.clear();
	patronymic.clear();
	model.clear();
	year = 0;
	distance = 0;
	route.clear();
}

void Transport::get_driver() {
	string id;
	list<Driver> drivers;
	do {
		cout << "Введите код водителя:";
		cin >> id;
		read_information_from_file(drivers, "Drivers.txt");
		find_if(drivers.begin(), drivers.end(), [id, this](Driver tmp) {
			if (tmp == id) {
				this->name = tmp.get_name();
				this->surname = tmp.get_surname();
				this->patronymic = tmp.get_patronymic();
				this->route = tmp.get_route();
				return true;
			}
			return false;
		});
		if (name.empty()) {
			system("cls");
			cout << "Такой записи не существует" << endl;
		}
	} while (name.empty());
}

void Transport::base_create() {
	cout << "Введите код:";
	cin >> code;
	get_driver();
	cout << "Введите модель:";
	cin >> model;
	do {
		cout << "Введите год:";
		enter_number(year, 4);
	} while (1970 > year || year > 2018);
	cout << "Ввелите пробег:";
	enter_number(distance, 7);
}

void Transport::filtr_year(Transport *transport, string first, string second) {
	try {
		if (transport->year >= stoi(first) && transport->year <= stoi(second))
			transport->show();
	}
	catch (...) {

	}
}

void Transport::filtr_distance(Transport *transport, string first, string second) {
	try {
		if (transport->distance >= stoi(first) && transport->distance <= stoi(second))
			transport->show();
	}
	catch (...) {

	}
}

bool Transport::comp_surname(Transport *transport1, Transport *transport2){ 
	return transport1->surname.compare(transport2->surname) > 0 ? 0 : 1; 
}

bool Transport::comp_year(Transport *transport1, Transport *transport2) {
	return transport1->year> transport2->year ? 1 : 0;
}

bool Transport::comp_distance(Transport *transport1, Transport *transport2) {
	return transport1->distance > transport2->distance ? 1 : 0;
}

void  Transport::search_surname(Transport *transport, string word) {
	if (!transport->surname.compare(word))
		transport->show();
}

void  Transport::search_model(Transport *transport, string word) {
	if (!transport->model.compare(word))
		transport->show();
}

void  Transport::search_route(Transport *transport, string word) {
	if (!transport->route.compare(word))
		transport->show();
}


Transport::operator const void*() { return reinterpret_cast<const void*>(this); }

Tram::operator const void*() { return reinterpret_cast<const void*>(this); }

Electro::operator const void*() { return reinterpret_cast<const void*>(this); }

Trolleybus::operator const void*() { return reinterpret_cast<const void*>(this); }

Autobus::operator const void*() { return reinterpret_cast<const void*>(this); }

Wheel::operator const void*() { return reinterpret_cast<const void*>(this); }

void Electro::electro_create() {
	cout << "Введите напряжение:";
	enter_number(amperage, 3);
}

void Electro::electro_clear() {
	amperage = 0;
}

void Fuel::fuel_create() {
	cout << "Введите запас топлива:";
	enter_number(fuel_capacity, 3);
	cout << "Введите потребление топлива:";
	enter_number(consumption, 2);
}

void Wheel::wheel_create() {
	cout << "Введите количество колёс";
	enter_number(number_of_wheels, 2);
	cout << "Введите размер колёс:";
	enter_number(wheel_size, 2);
}

void Wheel::wheel_clear() {
	number_of_wheels = 0;
	wheel_size = 0;
}

void Fuel::fuel_clear() {
	fuel_capacity = 0;
	consumption = 0;
}

void Electro::filtr_amperage(Tram &tram, string first, string second) {
	try {
		//cout << electro;
		if (tram.amperage >= stoi(first) && tram.amperage <= stoi(second))
			tram.show();
	}
	catch (...) {

	}
}

bool Electro::comp_amperage(Tram &tram1, Tram &tram2) {
	return tram1.amperage > tram2.amperage ? 1 : 0;
 }

void Wheel::filtr_size(Trolleybus &trolleybus, string first, string second) {
	try {
		//cout << electro;
		if (trolleybus.wheel_size >= stoi(first) && trolleybus.wheel_size <= stoi(second))
			trolleybus.show();
	}
	catch (...) {

	}
}

void Wheel::filtr_number(Trolleybus &trolleybus, string first, string second) {
	try {
		//cout << electro;
		if (trolleybus.number_of_wheels >= stoi(first) && trolleybus.number_of_wheels <= stoi(second))
			trolleybus.show();
	}
	catch (...) {

	}
}

void Fuel::filtr_capacity(Autobus &bus, string first, string second) {
	try {
		//cout << electro;
		if (bus.fuel_capacity >= stoi(first) && bus.fuel_capacity <= stoi(second))
			bus.show();
	}
	catch (...) {

	}
}

void Fuel::filtr_consumption(Autobus &bus, string first, string second) {
	try {
		//cout << electro;
		if (bus.consumption >= stoi(first) && bus.consumption <= stoi(second))
			bus.show();
	}
	catch (...) {

	}
}

bool Fuel::comp_capacity(Autobus &bus1, Autobus &bus2) {
	return bus1.fuel_capacity > bus2.fuel_capacity ? 1 : 0;
}

bool Fuel::comp_consumption(Autobus &bus1, Autobus &bus2) {
	return bus1.consumption > bus2.consumption ? 1 : 0;

}

void Wheel::filtr_size_bus(Autobus &bus, string first, string second) {
	try {
		//cout << electro;
		if (bus.wheel_size >= stoi(first) && bus.wheel_size <= stoi(second))
			bus.show();
	}
	catch (...) {

	}
}

void Wheel::filtr_number_bus(Autobus &bus, string first, string second) {
	try {
		//cout << electro;
		if (bus.number_of_wheels >= stoi(first) && bus.number_of_wheels <= stoi(second))
			bus.show();
	}
	catch (...) {

	}
}