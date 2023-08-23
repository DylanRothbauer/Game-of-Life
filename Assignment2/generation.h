#include <string>
#include <iostream>
using namespace std;

#define ROWS 20 
#define COLS 20

/**
  * Count the number of occupied neighbors of any cell at  index r, c
  * @param board
  * @param r, ROW coordinate
  * @param c, COLS coordinate
  * @return the number of occupied cells
  */
int countCellNeighbors(bool board[ROWS][COLS], int r, int c);

/**
  * Iterate over the input parameter array
  * @param board
  * @return a string of the printed board
  */
string printBoard(bool board[ROWS][COLS]);

/**
  * Toggle array that changes board on based rule sets 
  * @param board
  * @return none (formulates the rules)
  */
void computeNextGeneration(bool board[ROWS][COLS]);