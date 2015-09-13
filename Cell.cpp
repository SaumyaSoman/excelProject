#include "cell.h"

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
