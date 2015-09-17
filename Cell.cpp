#include "cell.h"

Cell::Cell() {
	Cell::val = "";
}

Cell::Cell(const Cell & other)
{
	Cell::val = other.val;
}

Cell::~Cell()
{
}

std::string Cell::toString() {
	return "";
}

std::string NumberCell::toString() {
	return "Number Cell";
}

std::string StringCell::toString() {
	return "String Cell";
}

std::string FunctionCell::toString() {
	return "Function Cell";
}
