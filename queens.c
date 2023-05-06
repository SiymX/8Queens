#include <cairo.h>
#include <cairo-pdf.h>
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


void draw_board(cairo_t *cr) {
    int square_size = 50;
    int text_margin = 20;

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i + j) % 2 == 0) {
                cairo_set_source_rgb(cr, 0.5, 0.5, 0.5);
            } else {
                cairo_set_source_rgb(cr, 1, 1, 1); 
            }
            cairo_rectangle(cr, j * square_size, i * square_size, square_size, square_size);
            cairo_fill(cr);
        }
    }

    
    cairo_set_source_rgb(cr, 1, 0, 0); 
    cairo_set_font_size(cr, square_size);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (stored_solution[i][j]) {
                cairo_rectangle(cr, j * square_size, i * square_size, square_size, square_size);
                cairo_fill(cr);
            }
        }
    }
    
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_select_font_face(cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 16);

    
    cairo_set_source_rgb(cr, 0.53, 0.81, 0.92);
    cairo_rectangle(cr, 0, N * square_size, N * square_size, text_margin * 2);
    cairo_fill(cr);

    
    cairo_set_source_rgb(cr, 0, 0, 0);
    char text[100];
    snprintf(text, sizeof(text), "8-Queens Solution #%d", chosen_solution);
    cairo_move_to(cr, 10, N * square_size + text_margin);
    cairo_show_text(cr, text);

    snprintf(text, sizeof(text), "Program created by Khandakar Sayeem");
    cairo_move_to(cr, 10, N * square_size + text_margin * 1.7);
    cairo_show_text(cr, text);
    
}


void save_solution_to_png() {
    int img_width = 50 * N;
    int img_height = 50 * N + 40; 

    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, img_width, img_height);
    cairo_t *cr = cairo_create(surface);

    draw_board(cr);

    cairo_surface_write_to_png(surface, "solution.png");

    cairo_destroy(cr);
    cairo_surface_destroy(surface);
}




int main(int argc, char **argv) {
    srand(time(NULL));
    memset(board, 0, sizeof(board));
    solve_and_store(0);
    printf("To verify the board go to www.datagenetics.com/blog/august42012/index.html\n");
    printf("There are %d solutions to the 8 Queens Problem on this %dx%d board.\n", solutions, N, N);
    printf("This is Solution #%d:\n", chosen_solution);
    print_solution();
    save_solution_to_png();
    printf("The solution has been saved as 'solution.png' to your desktop.\n");
    return 0;
}
