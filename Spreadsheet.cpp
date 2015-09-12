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

	LList<LList<double>> sheet;

	// Read in the entire input line
	std::string line;
	while (std::getline(std::cin, line)) {
		// Convert the string into an input stream and read in the command
		std::istringstream ss(line);
		std::string command;
		ss >> command;
		
		// Process the command

	}
	
	return 0;
}