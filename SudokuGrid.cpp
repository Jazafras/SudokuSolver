#include "SudokuGrid.h"

/********************************************/
//////////////Sudoku Cell////////////////////
/********************************************/

Cell::Cell(int number, bool s, bool f){
	setCell(number);
	solved = s;
	fixed = f;
}

int Cell::cell() const {
	return n;
}

void Cell::setCell(int number) { 
	n = number; //set cell to number
}

bool Cell::isFixed() const {
	return fixed; //returns whether cell is a fixed number or not
}

bool Cell::isSolved() const { 
	return solved; //returns whether cell is solved or not
}
void Cell::setSolved(bool sol) { 
	solved = sol; //set cell to solved
}

bool Cell::isPencilSet(int n) const { 
	return pencils[n-1];
}
bool Cell::anyPencilsSet() const { 
	for(int i=0; i<9; i++){
		if(pencils[i]==true){
			return true;  //a pencil exists in the cell
		}
	}
	return false; //no pencils found within the cell
}
void Cell::setPencil(int n, bool number) { 
	pencils[n]=number;
}
void Cell::setAllPencils(bool number) { //pencil numbers 1-9 in cell 
	for (int i=0; i<9; i++){
		pencils[i] = number;
	}
}

/********************************************/
//////////////Sudoku Grid////////////////////
/********************************************/

void SudokuGrid::setup(std::string s){
	int row = 1;
	int col = 1;
	for (int i = 0; i<=9; i++){
		grid[0][i]=Cell(0,false,false);
	}
	for(char& c:s){
		if (c=='\n'){
			break;
		}
		else if (col==10){ //already counted up to column 9
			col = 1; //go back to first column
			row++; //go to the next row	
		}
		else if (c=='.'){ //blank cell found from input
			Cell square = Cell(0,false,false);
			grid[row][col] = square;
		}
		else{ //number found from input
			Cell square = Cell(c-'0',true,true);//mark cell as fixed and solved
			grid[row][col]=square;
		}	
		col++;
	}	
}

SudokuGrid::SudokuGrid(std::string s) { // constructor
	 setup(s);
}

int SudokuGrid::number(int row, int col) const {
	return grid[row][col].cell(); //read number at grid location
}

void SudokuGrid::setNumber(int row, int col, int number) { 
	if(grid[row][col].isFixed() == false){	
		grid[row][col].setCell(number); //set number at grid location
  	}
  }
bool SudokuGrid::isFixed(int row, int col) const {
	return grid[row][col].isFixed(); //check if cell is a fixed value
}

bool SudokuGrid::isSolved(int row, int col) const { 
	return grid[row][col].isSolved(); //check if cell is a solved value
}
  
void SudokuGrid::setSolved(int row, int col) { 
	grid[row][col].setSolved(true);
}

bool SudokuGrid::isPencilSet(int row, int col, int n) const { 
	return grid[row][col].isPencilSet(n); //check if there are any pencil values
}

bool SudokuGrid::anyPencilsSet(int row, int col) const { 
	return grid[row][col].anyPencilsSet(); //check if there are any pencils
}

void SudokuGrid::setPencil(int row, int col, int n) { 
	grid[row][col].setPencil(n, true); //set pencil in cell, mark that cell as having that pencil number
}

void SudokuGrid::setAllPencils(int row, int col) { 
	grid[row][col].setAllPencils(true); //set pencil numbers 1-9 in cell
}
void SudokuGrid::clearPencil(int row, int col, int n) { 
	grid[row][col].setPencil(n,false); //remove pencil from cell
}

void SudokuGrid::clearAllPencils(int row, int col) { 
	grid[row][col].setAllPencils(false); 
}
