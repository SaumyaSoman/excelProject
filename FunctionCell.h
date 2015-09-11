#ifndef FUNCTIONCELL_H
#define FUNCTIONCELL_H

#include "cell.h"
#include "LList.cpp"

//Function Cell
class FunctionCell : public NumericCell{
	string type;
	double val;
	int col;
	int row;

	//iterator through the sheet 
	LList<Cell*>::iterator * first;
	LList<Cell*>::iterator * last;

public:
	FunctionCell();
	FunctionCell(string functionType, int columnIndex, int rowIndex);
	~FunctionCell();
	string toString();

	void updateComponent();
	int setValue(LList<Cell*>::iterator begin, LList<Cell*>::iterator end);
	void update();
	int isEmpty(LList<Cell*>::iterator val1, LList<Cell*>::iterator val2);
	double min(LList<Cell*>::iterator val1, LList<Cell*>::iterator val2);
	double max(LList<Cell*>::iterator val1, LList<Cell*>::iterator val2);
	double mean(LList<Cell*>::iterator val1, LList<Cell*>::iterator val2);

	double getValue();
	int getCol(){ return col; }
	int getRow(){ return row; }
	void setCol(int col_){ col = col_; }
	void setRow(int row_){ row = row_; }
};

#endif FUNCTIONCELL_H