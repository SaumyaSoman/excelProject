#include "cell.h"

StringCell::StringCell(){
	//val = std::numeric_limits < double >::quiet_NaN();
};

StringCell::StringCell(string value){
	val = value;
}

StringCell::~StringCell(){};

std::string StringCell::toString(){
	return val;
}