/*
* Header file for Cell
*
* @author Saumya Soman
*/

#ifndef CELL_H
#define CELL_H

#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
#include "LList.cpp"
#include <limits>

using namespace std;
//Abstract class for Cell
class Cell {
	double val;
public:
	Cell();
	Cell(Cell& other);
	//Cell& operator=(Cell& other);
	~Cell();
	// String representation of data in this cell
	virtual std::string toString();
	//virtual void setValueDirect();
	virtual double getValue() { return val; }
};

//Numeric Cell
class NumericCell : public Cell{
	double val;
	//LList<NumericCell*> listFunction;
	vector< pair <NumericCell*, pair<int, int> > >  listFunction;

public:

	NumericCell();
	NumericCell(double value);
	NumericCell(NumericCell& other);

	void setValueDirect(double value);
	virtual double getValue();

	int searchFunctionList(pair<int,int>);
	void updateComponentList(pair <NumericCell*, pair<int, int> >);
	std::string toString();
	void NumericCell::printListFunction();
	~NumericCell();
};

//String Cell
class StringCell :public Cell {
	string val;

public:
	StringCell();
	StringCell(string value);
	std::string toString();
	~StringCell();
};

#endif