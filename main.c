#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int ** createPuzzle();
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
    printf("Hello, World!\n");

    char ** puzzle;
    printPuzzle(createPuzzle());

    int row[9] = {1, 2, 3,      4, 0, 7,    8, 6, 5};
    int column[9] = {1, 2, 3,   4, 0, 7,    8, 6, 5};
    int grid[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    int * rowPuz;
    int * colPuz;
    int ** gridPuz;


    // Initializing Malloc and Pointer Array for Row Testing
    rowPuz = (int*)malloc(sizeof(int*)*9);
    for (int j = 0; j < 9; j++) {
        rowPuz[j] = row[j];
    }

    // Initializing Malloc and Pointer Array for Column Testing
    colPuz = (int*)malloc(sizeof(int*)*9);
    for (int j = 0; j < 9; j++) {
        colPuz[j] = column[j];
    }

    // Initializing Malloc Resources and Pointer Array for 3x3 Grid Testing
    gridPuz = (int**)malloc(sizeof(int**)*3);
    for(int i = 0; i < 3; i++) {
        gridPuz[i] = (int*)malloc(sizeof(int*)*3);
    }
    for(int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            gridPuz[x][y] = grid[x][y];
        }
    }


    // Testing to Ensure SolveRow Functionality
    solveRow(rowPuz);

    for (int i = 0; i < 9; i++) {
        printf("%d", rowPuz[i]);
    }

    printf("\n\n");


    // Testing to Ensure SolveColumn Functionality
    solveColumn(colPuz);

    for (int i = 0; i < 9; i++) {
        printf("%d", colPuz[i]);
    }

    printf("\n\n");



    // Testing to Ensure SolveGrid Functionality
    solveGrid(gridPuz);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d ", gridPuz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
