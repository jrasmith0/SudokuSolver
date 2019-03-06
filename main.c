#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void printPuzzle(int ** puzzle);
int ** createPuzzle();
bool findEmptySpace(int ** puzzle, int * row, int * column);

bool safeMove(int ** grid, int row, int column, int num);
bool solvePuzzle(int ** puzzle);
void solveRow(int * row);
void solveColumn(int * column);
void solveGrid(int ** grid);


void printPuzzle(int ** puzzle) {
    for(int i = 0; i < 9; i++) {
        if(i % 3 == 0) {
            printf("-------------------------------\n");
        }
        for (int j = 0; j < 9; j++) {
            if(j % 3 == 0) {
                printf("|");
            }
            printf(" %d ", puzzle[i][j]);

        }
        printf("|\n");
    }
    printf("-------------------------------\n");
}

int ** createPuzzle() {
    int ** puzzle;
    int i, j;
    // ArrPuz will of course be taken from a file and put into this grid accordingly.
    int arrPuz[9][9] = {0, 1, 9,    0, 0, 2,    0, 0, 0,
                        4, 7, 0,    6, 9, 0,    0, 0, 0,
                        0, 0, 0,    4, 0, 0,    0, 9, 0,

                        8, 9, 4,    5, 0, 7,    0, 0, 0,
                        0, 0, 0,    0, 0, 0,    0, 0, 0,
                        0, 0, 0,    2, 0, 1,    9, 5, 8,

                        0, 5, 0,    0, 0, 6,    0, 0, 0,
                        6, 0, 0,    0, 2, 8,    0, 7, 9,
                        0, 0, 0,    1, 0, 0,    8, 6, 0};
    // Need to read from file into the 3x3 grid setup (for the 9x9 board)
    // Now this is a temporary placeholder setup to ensure that the board prints properly


    puzzle = (int**)malloc(sizeof(int*)*9);

    for(i = 0; i < 9; i++){

        puzzle[i] = (int*)malloc(sizeof(int*)*9);

        for(j = 0; j < 9; j++){
            puzzle[i][j] = arrPuz[i][j];
        }
    }

    return puzzle;

}


// Finds an empty space within the puzzle, if one exists returns true; else returns false
bool findEmptySpace(int ** puzzle, int * row, int * column) {
    for (*row = 0; *row < 9; *row += 1) {
        for (*column = 0; *column < 9; *column += 1) {
            if (puzzle[*row][*column] == 0) {
                return true;
            }
        }
    }
    return false;
}


// Takes in a number and checks against the position's corresponding grid, row and column
// Mutates the variable row and column to represent the respective location of the empty position
bool safeMove(int ** puzzle, int row, int column, int num) {
    int i, j;

    // Checks the grid for the num; returns false if it exists
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++ ) {
            if (puzzle[i + (row - (row % 3))][j - (column - (column % 3))] == num) {
               return false;
            }
        }
    }

    // Checks the row for the num; returns false if it exists
    for (j = 0; j < 9; j++) {
        if(puzzle[row][j] ==  num) {
            return false;
        }
    }

    // Checks the column for the num; returns false if it exists
    for (i = 0; i < 9; i++) {
        if (puzzle[i][column] == num) {
            return false;
        }
    }
    return true;
}


// Solves the puzzle returning a value as to whether or not there is a valid solution
bool solvePuzzle(int ** puzzle) {
    int row = 0, column = 0;
    int num;

    if (!findEmptySpace(puzzle,  &row, &column)) {
        return true;
    }

    for (num = 1; num <= 9; num++) {
        if (safeMove(puzzle, row, column, num)) {
            puzzle[row][column] = num;

            if (solvePuzzle(puzzle)) {
                return true;
            }

            puzzle[row][column] = 0;
        }
    }

    return false;
}


// The following function solves a row if there is only one space unsolved in that row
void solveRow(int * row) {
    int sum = 45;
    int runningSum = 0;
    int x;

    for(int i = 0; i < 9; i++) {
        if (row[i] == 0) {
            x = i;
        }
        runningSum += row[i];
    }

    row[x] = (sum - runningSum);
}

// The following function solves a column if there is only one space unsolved in that column
void solveColumn(int * column) {
    int sum = 45;
    int runningSum = 0;
    int y;

    for(int j = 0; j < 9; j++) {
        if (column[j] == 0) {
            y = j;
        }
        runningSum += column[j];
    }

    column[y] = (sum - runningSum);
}

// The following function solves a grid if there is only one space unsolved in that grid
void solveGrid(int ** grid) {
    int sum = 45;
    int runningSum = 0;
    int x,y;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == 0) {
                x =  i;
                y = j;
            }
            runningSum += grid[i][j];
        }
    }

    grid[x][y] = (sum - runningSum);
}

int main() {
    int ** puzzle;
    puzzle = createPuzzle();
    printf("Before:\n");
    printPuzzle(puzzle);

    solvePuzzle(puzzle);
    printf("\n\n After:\n");
    printPuzzle(puzzle);

    return 0;
}
