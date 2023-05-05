# 8-Queens Problem
This program solves the famous 8-Queens Problem and will print a random solution out of the total 92 solutions on an 8x8 formatted chessboard. 
The 8-Queens Problem is a classic chess problem where the main goal is to place eight queens on a standard 8x8 chessboard in a way that no queen threatenes 
another. This means that no two queens can be on the same row, column, or diagonal. 
It uses a backtracking algorithm to place the queens on the board and will check that no other queen is in the same row or diagonal. 
Then the progam prints solution with the Queen symbol.


# Compilation
Make sure you are running it on a working version of ubuntu. To compile it run this command on terminal:
```
gcc queens.c -o queens
```

If everything is done correctly then it will compile and you can run the program using:
```./queens```
