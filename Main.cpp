/*
Final Project - Implementation of a text based spreadsheet

@author Saumya Soman
*/

#include <iostream>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Enter width and height";
	}

	int width;
	int height;

	try {
		width = std::stoi(std::string(argv[1]));
	}
	catch (const char* e) {

	}
}