#include "Route.h" Route::Route() {
cout << "constructor Route without parametrs\n";
}

Route::~Route() {
	cout << "destructor Route\n";
}

string Route::get_start_point() {
	return start_point;
}

string Route::get_end_point() {
	return end_point;
}

int Route::get_route_num() {
	return route_num;
}

void Route::set_start_point(string start_point) {
	this->start_point = start_point;
}

void Route::set_end_point(string end_point) {
	this->end_point = end_point;
}

void Route::set_route_num(int route_num) {
	this->route_num = route_num;
}

Route::Route(string start_point, string end_point, int route_num) {
	this->start_point = start_point;
	this->end_point = end_point; this->route_num = route_num;
	cout << "constructor Route with parametrs\n";
}

string Route::describe() {
	std::stringstream ss;
	ss << start_point << " - " << end_point << " " << route_num; return ss.str();
}

std::istream& operator>> (std::istream& in, Route& route) {
	cout << "start_point: "; in >> route.start_point;
	cout << "end_point: "; in >> route.end_point; cout << "route_num: "; in >> route.route_num; return in;
}
