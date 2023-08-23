/*
 * A program that simulates the computing of successive generations
 * Dylan Rothbauer
 * 3-31-22
 */ 
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "generation.h"
#include "tests.h"

using namespace std;

 /**
  * Utility function that will clear the console screen, this will only work on Windows
  * and requires a #include <windows.h>
  * Reference: https://www.cplusplus.com/articles/4z18T05o/
  * @param none
  * @return none
  */
void ClearScreen() {
    
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(hStdOut != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        // Calculate how big the buffer
        DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;

        // Fill the entire buffer with spaces
        COORD homeCoords = { 0, 0 };
        DWORD count;
        if(FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count)) {
            // Fill the entire buffer with the current colors and attributes
            if(FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) {
                // Move the cursor home
                SetConsoleCursorPosition(hStdOut, homeCoords);
            }
        }
    }
}

int main() {
    // Note! When you first compile this it will not work until you at least
    // create your generation.h and generation.cpp and minimally satisfy the
    // interfaces in generation.h -- see the assignment
    //runUnitTests();
    // You will also note after you successfully compile it, your unit tests
    // will fail because you haven't completed the implementation.
    
    // TODO:  Now create an animation for the first 64 generations!
    // See the assignment page for detailed requirements!
    
    bool board [ROWS][COLS] = {{false}};
    
    board[0][1] = true;
    board[1][2] = true;
    board[2][0] = true;
    board[2][1] = true;
    board[2][2] = true;
    
   for (int i = 1; i < 65; i++) {
       ClearScreen();
       cout << "Generation: " << i << endl;
       cout << printBoard(board);
       Sleep(100);
       computeNextGeneration(board);
   }
    
    return 0;
}