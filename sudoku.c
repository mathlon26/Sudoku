#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function declarations
bool validate_row(char row[]);
void print_sudoku(char sudoku[9][9], char original[9][9]);
bool is_valid(char sudoku[9][9], int row, int col, char num);
bool solve_sudoku(char sudoku[9][9], char original[9][9]);
void solve(char sudoku[9][9]);
void get_user_input(char sudoku[9][9]);
void clear_screen();

int main() {
    char sudoku[9][9];
    char default_sudoku[9][9] = {
        {'5', '3', 'X', 'X', '7', 'X', 'X', 'X', 'X'},
        {'6', 'X', 'X', '1', '9', '5', 'X', 'X', 'X'},
        {'X', '9', '8', 'X', 'X', 'X', 'X', '6', 'X'},
        {'8', 'X', 'X', 'X', '6', 'X', 'X', 'X', '3'},
        {'4', 'X', 'X', '8', 'X', '3', 'X', 'X', '1'},
        {'7', 'X', 'X', 'X', '2', 'X', 'X', 'X', '6'},
        {'X', '6', 'X', 'X', 'X', 'X', '2', '8', 'X'},
        {'X', 'X', 'X', '4', '1', '9', 'X', 'X', '5'},
        {'X', 'X', 'X', 'X', '8', 'X', 'X', '7', '9'}
    };

    char choice;
    printf("Input your own sudoku? (y/n): ");
    scanf(" %c", &choice);
    if (tolower(choice) == 'y') {
        get_user_input(sudoku);
    } else {
        memcpy(sudoku, default_sudoku, sizeof(default_sudoku));
    }

    print_sudoku(sudoku, sudoku);
    solve(sudoku);

    return 0;
}

// Function to validate the input row
bool validate_row(char row[]) {
    if (strlen(row) != 9) return false;
    for (int i = 0; i < 9; i++) {
        if (row[i] != 'X' && (row[i] < '1' || row[i] > '9')) {
            return false;
        }
    }
    return true;
}

// Function to print the Sudoku grid
void print_sudoku(char sudoku[9][9], char original[9][9]) {
    printf("\033[H");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("- - - - - - - - - - -\n");
        }
        printf("[ ");
        for (int j = 0; j < 9; j++) {
            char cell = sudoku[i][j];
            if (cell != original[i][j]) {
                printf("\033[32m%c \033[0m", cell);  // Green for changed cells
            } else {
                printf("%c ", cell);
            }
        }
        printf("]\n");
    }
}


// Function to check if placing a number is valid
bool is_valid(char sudoku[9][9], int row, int col, char num) {
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;

    for (int x = 0; x < 9; x++) {
        if (sudoku[row][x] == num || sudoku[x][col] == num || 
            sudoku[box_row + (x / 3)][box_col + (x % 3)] == num) {
            return false;
        }
    }
    return true;
}

// Recursive backtracking function to solve Sudoku
bool solve_sudoku(char sudoku[9][9], char original[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (sudoku[row][col] == 'X') {  // Find an empty slot
                for (char num = '1'; num <= '9'; num++) {  // Try numbers 1-9
                    if (is_valid(sudoku, row, col, num)) {
                        sudoku[row][col] = num;  // Place the number
                        print_sudoku(sudoku, original);  // Print the current state of Sudoku

                        if (solve_sudoku(sudoku, original)) {  // Recur
                            return true;
                        }

                        // Reset and try again if placing num didn't lead to a solution
                        sudoku[row][col] = 'X';
                        print_sudoku(sudoku, original);  // Print the state after backtracking
                    }
                }
                return false;  // No valid number found, trigger backtracking
            }
        }
    }
    return true;  // Solved
}

// Solve the Sudoku puzzle
void solve(char sudoku[9][9]) {
    system("cls");
    char copied[9][9];
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            copied[i][j] = sudoku[i][j];
        }
        
    }
    
    if (solve_sudoku(sudoku, copied)) {
        printf("\n\033[36mSudoku solved successfully!\033[0m\n");
    } else {
        printf("\n\033[31mNo solution exists.\033[0m\n");
    }
}

// Function to get user input for the Sudoku
void get_user_input(char sudoku[9][9]) {
    char row_input[10];  // 9 characters + null terminator
    for (int i = 0; i < 9; i++) {
        while (true) {
            printf("Row %d: ", i + 1);
            scanf("%s", row_input);
            if (validate_row(row_input)) {
                for (int j = 0; j < 9; j++) {
                    sudoku[i][j] = row_input[j];
                }
                break;
            } else {
                printf("\033[31mInvalid input! Row must contain 9 characters: digits 1-9 or 'X' for empty slots.\033[0m\n");
            }
        }
    }
}
