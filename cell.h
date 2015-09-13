/*
* Header file for cell
* @author Saumya Soman
*/
#include <string>

//Abstract class for Cell
class Cell {
public:
	virtual std::string toString();
};

//Class for Number Cell
class NumberCell :public Cell {
public:
	double val;
	std::string toString();
};

//Class for String Cell
class StringCell :public Cell {
public:
	std::string val;
	std::string toString();
};

//Class for Function Cell
class FunctionCell :public NumberCell {
public:
	std::string functionName;
	std::string toString();
};