#include <iostream> #include "Keeper.h" #include <limits> #include "task2.h"

void show_menu();
template <typename T> T input(string);
enum commands { ADD = 1, PRINT, PRINT_BY_NAME, EDIT, DELETE, DELETE_ALL, GET_BY_NUM, EXIT };

int main(int argc, char const* argv[]) {
	Keeper* keeper = new Keeper();
	Route* route1 = new Route("Spb", "Moscowasd", 178); Route* route2 = new Route("Spb2", "Moscow", 728); Route* route3 = new Route("Spb1", "Moscow32", 78); Route* route4 = new Route("Spb4", "Spb", 7);
	keeper->add(route1); keeper->add(route2); keeper->add(route3); keeper->add(route4);
	bool is_quit = false; string str;
	int act, num, num2, val;
	int task_num = input<int>("Select the task (1 or 2): ");
	while (task_num != 1 && task_num != 2) task_num = input<int>("Select the task (1 or 2): ");
	system("clear");
	if (task_num == 1) {
		show_menu();
		while (!is_quit) {

			act = input<int>("\nEnter action: "); system("clear");
			show_menu();

			if (act == commands::ADD) {
				try {
					(*keeper)++;
				}
				catch (const std::exception& e) {
					std::cerr << e.what() << '\n';
				}
			}
			else if (act == commands::PRINT) {
				try {
					keeper->print();
				}
				catch (const std::exception& e) {
					std::cerr << e.what() << '\n';
				}
			}
			else if (act == commands::PRINT_BY_NAME) {
				try {
					cout << "Enter the name of point: "; cin >> str; keeper->print_by_name(str);
				}
				catch (const std::exception& e) {
					std::cerr << e.what() << '\n';
				}
			}
			else if (act == commands::EDIT) {
				num2 = input<int>("\nEnter num of route: ");
				num = input<int>("Enter num of edit property (1 - start_point, 2 - end_point, 3 - num_route): ");
				cout << "Enter new value of property: "; if (num == 3) cin >> val;
				else cin >> str;
				if (num == 1) (*keeper)[num2 - 1]->set_start_point(str); else if (num == 2) (*keeper)[num2 - 1]->set_end_point(str); else if (num == 3) (*keeper)[num2 - 1]->set_route_num(val);
			}
			else if (act == commands::DELETE) {
				try {

					(*keeper)--;
				}
				catch (const std::exception& e) {
					std::cerr << e.what() << '\n';
				}
			}
			else if (act == commands::DELETE_ALL) {
				try {
					keeper->free();
				}
				catch (const std::exception& e) {
					std::cerr << e.what() << '\n';
				}
			}
			else if (act == commands::GET_BY_NUM) {
				num = input<int>("\nEnter num of route: "); cout << (*keeper)[num - 1]->describe() << "\n";
			}
			else if (act == commands::EXIT) {
				try {
					is_quit = true; keeper->free(); delete keeper;
				}
				catch (const std::exception& e) {}
			}
		}
	}
	else if (task_num == 2) {
		print_lines();
	}
	return 0;
}

void show_menu() {
	cout << "1 - add a new route\n2 - print a list of routes\n3 - print a list of routes by name\n" <<
		"4 - edit the route\n5 - delete the route\n" << "6 - delete all route\n7
		- get the route by num\n8 - exit\n\n";
}

template <typename T> T input(string prompt) {
	T value;
	cout << prompt; std::cin >> value;

	while (true) {
		if (std::cin.fail()) {
			std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cout << "You have entered wrong input" << std::endl;
			std::cin >> value;
		}
		if (!std::cin.fail()) break;
	}
	return value;
}
