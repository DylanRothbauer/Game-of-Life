#include "generation.h"

int countCellNeighbors(bool board[ROWS][COLS], int r, int c) {
    
    int rowsStart = max(r - 1, 0);
    int rowsEnd = min(r + 1, ROWS - 1);
    int colsStart = max(c - 1, 0);
    int colsEnd = min (c + 1, COLS - 1);
    int neighbors = 0;
    
    for (int i = rowsStart; i <= rowsEnd; i++) {
        for (int k = colsStart; k <= colsEnd; k++) {
            if ((i == r) && (k == c)) {
                continue; 
            }
            if (board[i][k]) {
                neighbors++;
            }
        }
    }
    
    return neighbors;
}

string printBoard(bool board[ROWS][COLS]) {
    string nBoard;
    for (int i = 0; i < ROWS; i++) {
        for (int k = 0; k < COLS; k++) {
            if (board[i][k]) {
               nBoard += (char)178;
            }
            else {
                nBoard += " ";
            }
        }
        nBoard += "\n";
    }
    
    return nBoard;
}

void computeNextGeneration(bool board[ROWS][COLS]) {
    
    bool toggle[ROWS][COLS] = {{false}};
    
    for (int i = 0; i < ROWS; i++) {
        for (int k = 0; k < COLS; k++) {
            
           int neighbors = countCellNeighbors(board, i, k);
           
            if (board[i][k] == true && neighbors < 2) {
                toggle[i][k] = true;
            }
            if (board[i][k] == true && neighbors > 3) {
                    toggle[i][k] = true;
            }
            if (board[i][k] == false && neighbors == 3) {
                    toggle[i][k] = true;
            }
        }
    }
        
        for (int i = 0; i < ROWS; i++) {
            for (int k = 0; k < COLS; k++) {
                if (toggle[i][k] == true) {
                    board[i][k] = !board[i][k];
                }
            }
        }
        
}