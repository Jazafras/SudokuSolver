#include "SudokuGrid.h"

using namespace std;

//Print Sudoku grid
void Print(SudokuGrid& grid) {
	for(int row=1; row <= 9; row++){
		for (int col=1; col<=9; col++){
			int num = grid.number(row,col);
			if(num==0){ //empty cell
				cout<<".";
			}
			else {
				cout<<num;
			}
			if (col%3 == 0 && col != 9){
				cout << "|";
			}
		}
		cout << "\n";
		if (row%3 == 0 && row != 9){
				cout << "---+---+---\n";
		}
	}
}


bool findUnassignedLocation(SudokuGrid& grid, int& row, int& col){
	for(int r=1; r <= 9; r++){
		for(int c=1; c<=9; c++){
			if(grid.number(r,c) ==0){
				row = r;
				col = c;
				return true; //unassigned location found
			}
		}
	}
	return false; //all cells filled, puzzle is solved
}

bool conflictingNumber(SudokuGrid& grid, int row, int col, int n){
	//check the rows and columns
	for(int i=1; i<=9; i++){
		if(grid.number(row,i) == n || grid.number(i,col) == n){
			return true;
		}
	}
	//check block
	int r=0;
	int c=0;
	int rBlock;
	int cBlock;
	int rLook;
	int cLook;
	if (row%3 != 0){
		r=1;
	}
	if (col%3 != 0){
		c=1;
	}
	rBlock = (row/3) + r;
	cBlock = (col/3) + c;
	for (int ro = 1; ro<=3; ro++) {
		for(int co = 1; co<=3; co++){
			rLook = ((rBlock -1)*3)+ro;
			cLook = ((cBlock -1)*3)+co;
			if(grid.number(rLook, cLook) == n){
				return true;
			}
		} 
	}
	return false; //no duplicate number n
}


bool solveSudoku(SudokuGrid& grid) {
 	int row, col;
 	if (!findUnassignedLocation(grid, row, col))
 		return true; // puzzle filled, solution found!
 	for (int num = 1; num <= 9; num++)
 		if (!conflictingNumber(grid, row, col, num)) {
 			grid.setNumber(row, col, num); // try next number
 		if (solveSudoku(grid))
 			return true; // solved!
 		grid.setNumber(row, col, 0); // not solved, clear number
 	}
 	return false; // not solved, back track
}

int main(int argc, char *argv[]) {
  string puzzle;
  cin >> puzzle;
  if (puzzle.length() != 9*9 ||
      !all_of(puzzle.begin(), puzzle.end(),
	      [](char ch) {
		return ch == '.' || ('1' <= ch && ch <= '9');
	      })) {
    cerr << "bogus puzzle!" << endl;
    exit(1);
  }

  SudokuGrid grid = SudokuGrid(puzzle);
  Print(grid); //print starting grid
  cout << "\n";
  solveSudoku(grid);
  Print(grid); //print solved grid
  cout << "\n";
  return 0;
}
