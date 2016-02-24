# SudokuSolver
Description:
  Sudoku puzzle solver that uses backtracking.
  
  Building
  The source is in written in C++11 and requires
  a C++ compiler of recent vintage (g++ 4.7 or later,
  clang++). The provided Makefile will automate
  the build via "make" (use -O3 in CXXFLAGS for best performace).

         make         # builds 'solvesudoku' app
         make clean   # deletes build riffraff

Running:
  The program reads a 81 character string from stdin
  that describes the input puzzle in row-major order.
  Each character in the string is either a dot '.' or
  a digit for an empty space or initial number respectively.
  Included are two files: 'simple.txt' and 'hard.txt',
  which contain a variety of sample puzzles.
  For example, to run the program using the 13th puzzle
  from "hard.txt", do the following:

        sed -n "13p" hard.txt | ./solvesudoku 
        
 To solve all the problems in 'hard.txt' you can use
  the provided Perl script:

       ./solve.pl hard.txt
