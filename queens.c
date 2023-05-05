#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 8

int board[N][N];
int solutions = 0;

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

void print_board() {
    printf("There are %d solutions to the 8 Queens Problem on this %dx%d board.\n", solutions, N, N);
    printf("This is Solution #%d:\n", rand() % solutions + 1);
    int queen_pos[N];
    for (int i = 0; i < N; i++) {
        int pos;
        do {
            pos = rand() % N;
        } while (!isSafe(i, pos));
        queen_pos[i] = pos;
    }
    memset(board, 0, sizeof(board));
    for (int i = 0; i < N; i++) {
        board[i][queen_pos[i]] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf("♛ ");
            else
                printf("_ ");
        }
        printf("\n");
    }
}



int main(int argc, char **argv) {
    srand(time(NULL));
    solve(0);
    print_board();
    return 0;
}

