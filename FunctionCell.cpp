#include "FunctionCell.h"

FunctionCell::FunctionCell(){
	//val = std::numeric_limits < double >::quiet_NaN();
}

FunctionCell::FunctionCell(string functionType, int columnIndex, int rowIndex){ 
	//val = std::numeric_limits < double >::quiet_NaN();
	type = functionType; 
	row = rowIndex;
	col = columnIndex;
}

FunctionCell::~FunctionCell(){}

string FunctionCell::toString(){
	return to_string(val);
}

void FunctionCell::updateComponent(){
	LList<Cell*>::iterator val1 = *last;
	val1++;
	
	for (LList<Cell*>::iterator iter = *first; iter != val1; iter++){
		((NumericCell*)(*iter))->updateComponentList(make_pair(this, make_pair(col, row))); ///change 
	}
}

int FunctionCell::setValue(LList<Cell*>::iterator begin, LList<Cell*>::iterator end){
	first = &begin;
	last = &end;

	if (isEmpty(begin, end))
	{
		return 0;
	}

	if (type == "min"){
		val = min(begin, end);
	}
	else if (type == "max"){
		val = max(begin, end);
	}
	else if (type == "mean"){
		val = mean(begin, end);
	}
	updateComponent();

	return 1;
}

void FunctionCell::update(){
	if (type == "min"){
		val = min(*first, *last);
	}
	else if (type == "max"){
		val = max(*first, *last);
	}
	else if (type == "mean"){
		val = mean(*first, *last);
	}
}

int FunctionCell::isEmpty(LList<Cell*>::iterator val1, LList<Cell*>::iterator val2){
	val2++;
	for (LList<Cell*>::iterator iter = val1; iter != val2; iter++){
		if ((*iter)->getValue() != std::numeric_limits < double >::quiet_NaN()){
			//cout << "Returning early\n";
			return 0;
		}
	}
	return 1;
}

double FunctionCell::min(LList<Cell*>::iterator val1, LList<Cell*>::iterator val2){
	double minValue = ((NumericCell*)(*val1))->getValue();
	val2++;
	for (LList<Cell*>::iterator iter = val1; iter != val2; iter++){
		NumericCell* checkCell = dynamic_cast<NumericCell*>(*iter);
		if (checkCell){
			if (checkCell->getValue() < minValue){
				minValue = checkCell->getValue();
			}
		}
	}
	return minValue;
}

double FunctionCell::max(LList<Cell*>::iterator val1, LList<Cell*>::iterator val2){
	double maxValue = ((NumericCell*)(*val1))->getValue();
	val2++;
	for (LList<Cell*>::iterator iter = val1; iter != val2; iter++){
		NumericCell* checkCell = dynamic_cast<NumericCell*>(*iter);
		if (checkCell){
			if (checkCell->getValue() > maxValue){
				maxValue = checkCell->getValue();
			}
		}
	}
	return maxValue;
}

double FunctionCell::mean(LList<Cell*>::iterator val1, LList<Cell*>::iterator val2){
	double meanValue = 0;
	int width = 0;
	val2++;
	for (LList<Cell*>::iterator iter = val1; iter != val2; iter++){
		NumericCell* checkCell = dynamic_cast<NumericCell*>(*iter);
		if (checkCell){
			width++;
			meanValue += checkCell->getValue();
		}
	}
	meanValue /= width;
	return meanValue;
}

double FunctionCell::getValue(){
	return val;
}