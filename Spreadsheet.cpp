/*
Course Project - Text based Implementation of Spreadsheet (C++11)

@author Saumya Soman

*/

#include <iostream>
// sstream has the std :: istringstream class
#include <sstream>
// String has std :: getline and std :: string
#include <string>
#include "list.h"
#include "cell.h"

template <typename iterator>
void print(iterator begin, iterator end) {

	
	for (iterator I= begin; I!=end; ++I) {
		LList<Cell*> row = *I;
		/*for (iterator J = row.begin(); J != row.end(); ++J) {
			Cell* cell = *J;
			std::string val = cell.toString();
			std::cout << val;
			if (J != row.end()) {
				std::cout << ",\t";
			}
		}*/
		std::cout << "\n";
	}	
}

int main(int argc, char* argv[]) {

	//Check number of arguments
	if (argc < 2) {
		std::cout << "Enter width and height!!\n";
		return 1;
	}

	//Retreive the values of width and height using stoi
	int width;
	int height;
	try {
		width = std::stoi(std::string(argv[1]));
		height = std::stoi(std::string(argv[2]));
	}
	catch (std::exception e) {
		//Handle exception due to stoi
		std::cout << "Got bad values for width and height!\n";
		return 1;
	}

	//Check if width and height are positive
	if (width <= 0 || height <= 0) {
		std::cout << "Enter positive values for width and height!\n";
		return 1;
	}

	LList<LList<Cell*>> sheet;
	int rows = height;
	int cols = width;

	for (int i = 0; i < rows; i++) {
		LList<Cell*> row;
		for (int j = 0; j < cols; j++) {
			Cell* cell;
			row.push_back(cell);
		}
		sheet.push_back(row);
	}

	// Read in the entire input line
	std::string line;
	while (std::getline(std::cin, line)) {
		// Convert the string into an input stream and read in the command
		std::istringstream ss(line);
		std::string command;
		ss >> command;
		
		// Process the command
		if (command.compare("print")==0) {
			print(sheet.begin(), sheet.end());
		}
		else if (command.compare("addrow")==0) {

		}
		else if (command.compare("removerow")==0) {

		}
		else if (command.compare("set") == 0) {

		}
		else if (command.compare("quit") == 0) {

		}
		else {
			std::cout << "Error: unknown command";
		}

	}
	
	return 0;
}

