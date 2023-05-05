# 8-Queens Problem
This program solves the famous 8-Queens Problem and will print a random solution out of the total 92 solutions on an 8x8 formatted chessboard. 
The 8-Queens Problem is a classic chess problem where the main goal is to place eight queens on a standard 8x8 chessboard in a way that no queen threatenes 
another. This means that no two queens can be on the same row, column, or diagonal. 
It uses a backtracking algorithm to place the queens on the board and will check that no other queen is in the same row or diagonal. 
The code solves and stores all possible solutions to the problem by calling the 'solve_and_store()' function. It then randomly chooses one of the solutions by creating a random number and then compares itself to the total number of solution. 
The program then prints out one random solution out of the 92 solutions. 

To verify the printed board use the following website: http://www.datagenetics.com/blog/august42012/index.html

# Test cases
![Screenshot 2023-05-05 165535_1](https://user-images.githubusercontent.com/63435885/236567335-e2d9e674-1c06-44f4-9218-2c69c8a8a9bc.png)

![Screenshot 2023-05-05 165414_1](https://user-images.githubusercontent.com/63435885/236567642-a1bdc1fb-9b22-4571-8b9a-bd365af7e344.png)




# Compilation
Make sure you are running it on a working version of ubuntu. To compile it run this command on terminal:
```
gcc queens.c -o queens
```

If everything is done correctly then it will compile and you can run the program using:
```./queens```
