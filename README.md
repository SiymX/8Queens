![8queensGIT](https://github.com/SiymX/8Queens/assets/63435885/672c5d54-2760-4806-9ef8-7161a8308a58)


# 8-Queens Problem
This program solves the famous 8-Queens Problem and will print a random solution out of the total 92 solutions on an 8x8 formatted chessboard. 
The 8-Queens Problem is a classic chess problem where the main goal is to place eight queens on a standard 8x8 chessboard in a way that no queen threatenes 
another. This means that no two queens can be on the same row, column, or diagonal. 
It uses a backtracking algorithm to place the queens on the board and will check that no other queen is in the same row or diagonal. 

The code solves and stores all possible solutions to the problem by calling the ```'solve_and_store()'``` function. It then randomly chooses one of the solutions by creating a random number and then compares itself to the total number of solution. 
The program then prints out one random solution out of the 92 solutions and generates an image based on the solution using cairo graphics and save it on your desktop for 
you to view. To verify the printed board use the following website: http://www.datagenetics.com/blog/august42012/index.html

# Test cases
![Screenshot 2023-05-05 165535_1](https://user-images.githubusercontent.com/63435885/236588783-89ac5a02-eb4e-4095-9499-6cfe9124b328.png)

![solution](https://user-images.githubusercontent.com/63435885/236588847-c045606c-65ad-45b1-9525-1955b5495ec5.png)


# Installation
This program might ask you to install some librarires so if it does just run the following command:
```
sudo apt-get install libcairo2-dev libcairo-gobject2
```

To see if it is installed:
```
dpkg -l | grep -E 'libcairo2-dev|libcairo-gobject2'
```


# Compilation
Make sure you are running it on a working version of ubuntu. To compile it run this command on terminal:
```
gcc -o queens queens.c $(pkg-config --cflags --libs cairo)
```

If everything is done correctly then it will compile and you can run the program using:
```./queens```
