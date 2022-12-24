#pragma once #include <iostream> #include <string.h> #include <sstream>

using std::cout;

using std::cin; using std::string;
using std::runtime_error;

class Route {
private:
	string start_point; string end_point; int route_num;
public:
	Route();
	~Route();
	Route(string, string, int); string get_start_point();
	string get_end_point(); int get_route_num();
	void set_start_point(string); void set_end_point(string); void set_route_num(int); string describe();
	friend std::istream& operator>> (std::istream& in, Route& route);
};
