#pragma once #include "Route.h"

struct RouteNode {
	Route* route; RouteNode* next;
};

class Keeper {
private:
	int count;
	Route** routes = new Route * [8];

void sort(); public:
	Keeper();
	~Keeper();

	void add(Route* new_route); void print();
	void print_by_name(string name); void remove(int num);
	void free();
	Route* get(int num); void operator++(int d);
	void operator--(int d);
	Route* operator[] (const int index);
};
