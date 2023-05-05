#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 8

int board[N][N];
int stored_solution[N][N];
int solutions = 0;
int chosen_solution = 0;

int isSafe(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
}

void solve(int col) {
    if (col >= N) {
        solutions++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            solve(col + 1);
            board[i][col] = 0;
        }
    }
}

void store_solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            stored_solution[i][j] = board[i][j];
        }
    }
}

void solve_and_store(int col) {
    if (col >= N) {
        if (rand() % (solutions + 1) == 0) {
            store_solution();
            chosen_solution = solutions + 1;
        }
        solutions++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            solve_and_store(col + 1);
            board[i][col] = 0;
        }
    }
}

void print_solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (stored_solution[i][j])
                printf("♛ ");
            else
                printf("_ ");
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    memset(board, 0, sizeof(board));
    solve_and_store(0);
    printf("To verify the board go to www.datagenetics.com/blog/august42012/index.html\n");
    printf("There are %d solutions to the 8 Queens Problem on this %dx%d board.\n", solutions, N, N);
    printf("This is Solution #%d:\n", chosen_solution);
    print_solution();
    return 0;
}

