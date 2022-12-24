#include "Keeper.h"

void Keeper::add(Route* new_route) {
	if (count >= 8) throw runtime_error("the list of routes is full"); routes[count++] = new_route;
}

void Keeper::sort() {
	Route* temp;
	for (size_t i = 0; i < count - 1; i++) {
		for (size_t j = 0; j < count - i - 1; j++) {
			if (routes[j]->get_route_num() > routes[j + 1]->get_route_num()) {
				temp = routes[j];
				routes[j] = routes[j + 1]; routes[j + 1] = temp;
			}
		}
	}
}

void Keeper::print() {
	if (count == 0) throw runtime_error("list of routes is empty"); sort();
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". " << routes[i]->describe() << "\n";

	}
}

void Keeper::print_by_name(string name) {
	if (count == 0) throw runtime_error("list of routes is empty"); sort();
	bool _ = true;
	for (int i = 0; i < count; i++) {
		if (name == routes[i]->get_start_point() || name == routes[i]->get_end_point()) {
			cout << routes[i]->describe() << "\n";
			_ = false;
		}
	}
	if (_) cout << "routes with such name is not found\n";
}

void Keeper::remove(int num) {
	if (num > count || num <= 0) throw runtime_error("uncorrect num of route");
	int counter = 0;
	Route** temp = new Route * [8];

	for (int i = 0; i < count; i++) temp[i] = routes[i]; delete routes[num - 1];

	for (int i = 0; i < num - 1; i++) routes[counter++] = temp[i]; for (int i = num; i < count; i++) routes[counter++] = temp[i]; count--;
	delete[] temp;
}

void Keeper::free() {
	for (int i = 0; i < count; i++) {
		delete routes[i];
	}
	count = 0;
}

Keeper::Keeper() {

	cout << "constructor Keeper without parametrs\n"; count = 0;
}

Keeper::~Keeper() {
	cout << "destructor Keeper\n"; delete[] routes;
}

void Keeper::operator++(int d) {
	if (count >= 8) throw runtime_error("the list of routes is full"); Route* route = new Route();
	cin >> *route; add(route);
}

void Keeper::operator--(int d) {
	int num;
	cout << "\nEnter num of route: "; cin >> num; remove(num);
}

Route* Keeper::operator[] (const int index) {
	return routes[index];
}

