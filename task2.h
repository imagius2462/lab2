#pragma once #include <iostream> #include <fstream>

void print_lines() {
	std::fstream in;
	std::string path = "input.txt"; std::string line;

	std::cout << "Enter path to the file: "; std::cin >> path; in.open(path, std::ios::in);
	while (!in.is_open()) {
		std::cout << "failed to open the file" << "\n";
		std::cout << "Enter path to the file: "; std::cin >> path; in.open(path, std::ios::in);

	}

	bool is_num = false; int count_digit = 0;
	while (std::getline(in, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (line[i] >= '0' && line[i] <= '9') count_digit++; else {
				if (count_digit == 2) break;
			}
		}
		if (count_digit != 2) std::cout << line << "\n"; count_digit = 0;
	}
	in.close();
}
