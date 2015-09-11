/*
* Final Project- Implementation of a text based spreadsheet
*
* @author Saumya Soman
*
*
*/


# include <iostream>
// sstream has the std :: istringstream class
# include <sstream>
// String has std :: getline and std :: string
# include <string>
# include "LList.cpp"
//# include "Cell.cpp"
# include "cell.h"
# include "FunctionCell.h"
//# include "NumericCell.cpp"

using namespace std;

// Always consume all input on a line
string line;
static int numRows = 0;
static int numCols = 0;

/*
*	Method to print spreadsheet
*/

void print(LList<LList<Cell*>>& sheet){
	for (LList<LList<Cell*>>::iterator I = sheet.begin(); I != sheet.end(); ++I) {
		int i = 0;
		for (LList<Cell*>::iterator J = (*I).begin(); J != (*I).end(); ++J) {
			cout << " ";
			cout << (*J)->toString();
			if (i++ < numCols - 1)
				cout << ",";
		}
		cout << endl;
	}
}

/*
*	Method to create spreadsheet
*/
LList<LList<Cell*>> createSpreadSheet(int width, int height){
	LList<LList<Cell*>> sheet;
	for (int i = 0; i < height; i++){
		LList<Cell*>  row;
		for (int j = 0; j < width; j++){
			Cell* cell = new Cell(); // pointer to type cell.
			row.push_back(cell);
		}
		sheet.push_back(row);
	}
	return sheet;
}

/*
*	Method to add row at user specified row index
*/
void addRow(LList<LList<Cell*>>& sheet, istringstream& ss){

	//Get user input
	int rowIndex;
	ss >> rowIndex;
	while (ss >> rowIndex){
		//Print error if there are more arguments than rowIndex
		throw("Error: unknown command");
	}

	//If user specified row index is negative or out of range , throw error
	if (rowIndex <= sheet.size() && rowIndex >= 0){

		//Create a new row
		LList<Cell*>  row;
		for (int j = 0; j < numCols; j++){
			Cell* cell = new Cell();
			row.push_back(cell);
		}

		//Get the head row pointer of sheet
		Node<LList<Cell*>> * ptr = sheet.getHead();
		//Create the pointer of the new row
		Node <LList < Cell* >>* rowPtr = new Node<LList<Cell*>>(row);

		//If index=0, set the new pointer as head pointer of sheet
		if (rowIndex == 0){
			rowPtr->next = ptr;
			sheet.setHead(rowPtr);
		}
		else{
			//Iterate till the index to which the new pointer has to be added
			for (int i = 0; i < rowIndex - 1; i++)
			{
				ptr = ptr->next;
			}

			//Adjust the pointers to insert new row in the list.
			Node<LList<Cell*>> * temp;
			temp = ptr->next;
			ptr->next = rowPtr;
			rowPtr->next = temp;

		}
		//Increment rows
		numRows++;
	}
	else{
		throw("Error: row out of range");
	}
}

/*
*	Method to remove row from user specified row index
*/
void removeRow(LList<LList<Cell*>>& sheet, istringstream& ss){

	//Get user input
	int rowIndex;
	ss >> rowIndex;
	while (ss >> rowIndex){
		//Print error if there are more arguments than rowIndex
		throw("Error: unknown command");
	}

	//If user specified row index is negative or out of range , throw error
	if (rowIndex <= sheet.size() && rowIndex >= 0){
		//Get the head row pointer of sheet
		Node<LList<Cell*>> * ptr = sheet.getHead();

		//If index=0, set the next pointer as head  of sheet and delete the current head pointer
		if (rowIndex == 0){
			sheet.setHead(ptr->next);
			delete(ptr);
		}
		else{
			//Iterate till the index
			for (int i = 0; i < rowIndex - 1; i++)
			{
				ptr = ptr->next;
			}
			//row to be deleted is at ptr->next
			Node<LList<Cell*>> * temp = ptr->next;
			ptr->next = temp->next;
			//Delete the temporary pointer
			delete(temp);
		}
		//Decrement rows
		numRows--;
	}
	else{
		throw("Error: row out of range");
	}
}

/*
*	Method to set cell value
*/
void setCell(LList<LList<Cell*>>& sheet, istringstream& ss){

	//Get user input in columIndex and rowIndex
	int columnIndex, rowIndex;
	ss >> columnIndex;
	ss >> rowIndex;


	//Retrieve command type
	string type;
	ss >> type;

	// If command is number
	if (type == "number"){
		//Handle columnIndex and rowIndex not within limits of the sheet size
		if (columnIndex < 0 || rowIndex < 0 || columnIndex >= numCols || rowIndex >= numRows){
			throw("Error: row out of range");
		}
		//Get the value from user
		double value;
		ss >> value;
		ss >> std::ws;  // eat whitespace after number

		if (!ss.fail() && ss.eof()) {
			//Iterate till the required cell
			LList<LList<Cell*>>::iterator I_cell = sheet.begin() + rowIndex;
			LList < Cell* > ::iterator J_cell = (*I_cell).begin() + columnIndex;
			*J_cell = new NumericCell(value);
		}
		else {
			throw("Error: Bad input for set number"); // not-a-number
		}
	}
	//If command is string
	else if (type == "string"){
		//Handle columnIndex and rowIndex not within limits of the sheet size
		if (columnIndex < 0 || rowIndex < 0 || columnIndex >= numCols || rowIndex >= numRows){
			throw("Error: row out of range");
		}
		//Get the string value from user

		string value = "";
		string tempString;
		ss >> tempString;

		while (ss){
			if (!ss) {
				break;
			}
			cout << tempString << endl;
			value += " " + tempString;
			ss >> tempString;

			//ss >> value;
		}

		//Iterate till the required cell
		LList<LList<Cell*>>::iterator I_cell = sheet.begin() + rowIndex;
		LList < Cell* > ::iterator J_cell = (*I_cell).begin() + columnIndex;

		//Replace the object
		*J_cell = new StringCell(value);
	}

	else if (type == "mean" || type == "min" || type == "max"){

		//Handle columnIndex and rowIndex not within limits of the sheet size
		if (columnIndex < 0 || rowIndex < 0 || columnIndex >= numCols || rowIndex >= numRows){
			throw("Error: cell out of range");
		}
		int rowFunction, val1, val2;
		ss >> rowFunction;
		ss >> val1;
		ss >> val2;

		//Handle cell boundaries
		if (rowFunction < 0 || val1 < 0 || val2 < 0 || val1 >= numCols || val2 >= numCols || rowFunction >= numRows){
			throw("Error: function incorrect");
		}
		int y = 0;
		int x = val1;

		LList<LList<Cell*>>::iterator I_cell = sheet.begin() + rowIndex;
		LList < Cell* > ::iterator J_cell = (*I_cell).begin() + columnIndex;

		LList<LList<Cell*>>::iterator I_range = sheet.begin() + rowFunction;
		LList<Cell*>::iterator J1 = (*I_range).begin() + val1;
		LList<Cell*>::iterator J2 = (*I_range).begin() + val2;

		FunctionCell* fCell = new FunctionCell(type, columnIndex, rowIndex);
		if (fCell->setValue(J1, J2))
			*(J_cell) = fCell;
	}

	else{
		throw("Error: unknown command");
	}
}


int main(int argc, char** argv) {

	//First check user arguments. We require ints for width and a height
	if (argc != 3){
		cout << "Please enter width and height" << '\n';
		return 0;
	}

	try{
		//Get the width and height
		numCols = stoi(string(argv[1]));
		numRows = stoi(string(argv[2]));
	}
	catch (std::invalid_argument&){
		cout << "Error occured. Enter numeric values for width and height" << '\n';
		return 1;
	}

	if (numRows <= 0 || numCols <= 0){
		cout << "Error occured. Enter positive values for width and height" << '\n';
		return 1;
	}

	else{
		//Create speadsheet using width and height
		LList<LList<Cell*>> sheet = createSpreadSheet(numCols, numRows);

		// Read in the entire input line
		string line;

		while (std::getline(std::cin, line, '\n')) {
			try{
				// Convert the string into an input stream and read in the command
				istringstream ss(line);
				string command;
				ss >> command;

				// Process the command
				if (command == "addrow"){
					addRow(sheet, ss);
				}
				else if (command == "removerow"){
					removeRow(sheet, ss);
				}
				else if (command == "set"){
					setCell(sheet, ss);
				}
				else if (command == "print"){
					while (ss >> command){
						throw("Error: unknown command");
					}
					print(sheet);
				}
				else if (command == "quit"){
					while (ss >> command){
						throw("Error: unknown command");
					}
					return 0;
				}
				else{
					throw("Error: unknown command");
				}
			}
			catch (const char* e){
				cout << e << '\n';
				//if bad commands to be ignored 
				continue;
			}
		}
	}
}



