#ifndef NUMERICCELL_CPP
#define NUMERICCELL_CPP

#include "cell.h"

NumericCell::NumericCell(){
	//val = std::numeric_limits < double >::quiet_NaN();
};

NumericCell::NumericCell(double value){
	val = value;
}

//copy constructor
NumericCell::NumericCell(NumericCell& other){
	val = other.val;
	listFunction = other.listFunction;
}

NumericCell::~NumericCell(){}

void NumericCell::setValueDirect(double value){
	val = value;
}

double NumericCell::getValue(){
	return this->val;
}

std::string NumericCell::toString(){
	return to_string(val);
}

//insert function cell into a Linkedlist
void NumericCell::updateComponentList(pair<NumericCell*, pair<int, int>> location){

	if (!searchFunctionList(location.second))
	{
		listFunction.push_back(location);
	}
}

void NumericCell::printListFunction(){
	vector<pair<NumericCell*, pair<int, int>>>::iterator it = listFunction.begin();
	cout << "listfunction: ";
	while (it < listFunction.end()){
		cout << (*it).second.first << " "<<(*it).second.second;
		it++;
	}
	cout << endl;
}

int NumericCell::searchFunctionList(pair<int, int> location){
	vector<pair<NumericCell*, pair<int, int>>>::iterator it = listFunction.begin();
	while (it < listFunction.end()){
		if ((*it).second.first ==location.first && (*it).second.second == location.second){
			return 1;
		}
		it++;
	}
	return 0;
}

#endif NUMERICCELL_CPP