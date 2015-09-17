/*
* Header file for cell
* @author Saumya Soman
*/
#include <string>

//Abstract class for Cell
class Cell {
private:
	std::string val = "";
public:	
	Cell();
	Cell(const Cell& other);
	~Cell();
	std::string toString();
};

//Class for Number Cell
class NumberCell :public Cell {
public:
	double val=0.0;
	std::string toString();
};

//Class for String Cell
class StringCell :public Cell {
public:
	std::string toString();
};

//Class for Function Cell
class FunctionCell :public NumberCell {
public:
	std::string functionName;
	std::string toString();
};