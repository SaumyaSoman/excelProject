#ifndef CELL_CPP
#define CELL_CPP

#include "cell.h"

Cell::Cell(){ 
	val = std::numeric_limits < double >::quiet_NaN();
};

//copy constructor and assignment operator
Cell::Cell(Cell& other){}
//Cell& Cell::operator=(Cell& other){}

std::string Cell::toString(){ return " "; }

Cell::~Cell(){};


#endif