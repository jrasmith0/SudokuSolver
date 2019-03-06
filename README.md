# SudokuSolver
  
###### Operating Systems Lab #3
* Due: Thursday, March 14th 2019  

###### Goal: Using C Design a Sudoku Solver using Multithreading
###### Suggested Algorithms:
* Backtracking (Brute Force)
* Genetic Algorithm (Fitness Function Based on Number of Errors on Board with Each Iteration)

###### Backtracking Steps:
1) Generate a List of Empty Spaces
2) Select a Spot from that List and Place Num 1-9 In It, Validating the Grid afterwards
3) If constraints fail, abandon the candidate and repeat step 2 with next number. Otherwise check goal.
4) If a solution is found, stop searching. Otherwise repeat 2-4.
