#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int ** createPuzzle();
int ** emptySpaces(int ** puzzle);
void printPuzzle(int ** puzzle);
bool checkBoard(int ** board);
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

// The following Function Takes in a Puzzle and Produces a List of All Empty Squares
int ** emptySpaces(int ** puzzle) {
    int eSpaces = 0;
    int i, j, c = 0;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (puzzle[i][j] == 0) {
                eSpaces++;
            }
        }
    }

    // Need to redo this portion as a malloc array
    int ** emptySpaces;
    emptySpaces = (int **)malloc(sizeof(int*)*eSpaces);

    for (i = 0; i < eSpaces; i++) {
        emptySpaces[i] = (int*)malloc(sizeof(int)*2);
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (puzzle[i][j] == 0) {
                emptySpaces[c][0] = i;
                emptySpaces[c][1] = j;
                c++;
            }
        }
    }

    return emptySpaces;
}


bool checkBoard(int **board) {

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
    int ** eSpaces;
    puzzle = createPuzzle();
    printPuzzle(puzzle);
    eSpaces = emptySpaces(puzzle);

    return 0;
}
