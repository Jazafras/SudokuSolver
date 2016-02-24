#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H
#include <string>
#include <sstream>
#include <iostream>
#include <array>
#include <bitset>
#include <string>
#include <algorithm>

class Cell {
private:
	int n;
	std::bitset<9> pencils; // value 0..8 represent pencils 1..9
	bool solved;
	bool fixed;
public:
	Cell(
		int n = 0,
		bool solved = false,
		bool fixed = false
	);
  int cell() const;
	void setCell(int n);
	bool isFixed() const;
	bool isSolved() const;
	void setSolved(bool sol);
	bool isPencilSet(int n) const;
	bool anyPencilsSet() const;
	void setPencil(int n, bool number);
	void setAllPencils(bool number);
};

class SudokuGrid {
private:
  std::array<std::array<Cell,10>,10> grid;
public:
  // implement the following
	void setup(std::string s);
 	SudokuGrid(std::string s); // constructor
	int number(int row, int col) const;
	void setNumber(int row, int col, int number);
	bool isFixed(int row, int col) const;
	bool isSolved(int row, int col) const;
	void setSolved(int row, int col);
	bool isPencilSet(int row, int col, int n) const;
	bool anyPencilsSet(int row, int col) const;
	void setPencil(int row, int col, int n);
	void setAllPencils(int row, int col);
	void clearPencil(int row, int col, int n);
	void clearAllPencils(int row, int col);
};

#endif // SUDOKUGRID_H
