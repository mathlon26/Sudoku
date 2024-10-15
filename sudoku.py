import copy
from colorama import Fore, Style, init
from os import system

# Initialize colorama
init(autoreset=True)

# Function to validate the input row
def validate_row(row):
    return all(char in "123456789X" for char in row) and len(row) == 9

# Function to print the Sudoku grid
def print_sudoku(sudoku, original):
    print('\033[H') # Clear the screen
    for i in range(9):
        if i % 3 == 0 and i != 0:  # Print a separator every 3 rows
            print("- - - - - - - - - - -")
        formatted_row = ""
        for j in range(9):
            cell_color = Fore.GREEN if sudoku[i][j] != original[i][j] else Style.RESET_ALL
            formatted_row += f"{cell_color}{sudoku[i][j]}{Style.RESET_ALL} "
        print(f"[ {formatted_row.strip()} ]")

# Function to check if placing a number is valid
def is_valid(sudoku, row, col, num):
    # Check if num is in the row or column or 3x3 box
    box_row, box_col = 3 * (row // 3), 3 * (col // 3)
    for x in range(9):
        if (sudoku[row][x] == num or
            sudoku[x][col] == num or
            sudoku[box_row + x // 3][box_col + x % 3] == num):
            return False
    return True

# Recursive backtracking function to solve Sudoku
def solve_sudoku(sudoku, original):
    for row in range(9):
        for col in range(9):
            if sudoku[row][col] == 'X':  # Find an empty slot
                for num in '123456789':  # Try numbers 1-9
                    if is_valid(sudoku, row, col, num):
                        sudoku[row][col] = num  # Place the number
                        print_sudoku(sudoku, original)  # Print the current state of Sudoku

                        if solve_sudoku(sudoku, original):  # Recur
                            return True

                        # Reset and try again if placing num didn't lead to a solution
                        sudoku[row][col] = 'X'
                        print_sudoku(sudoku, original)  # Print the state after backtracking

                return False  # No valid number found, trigger backtracking
    return True  # Solved

def solve(sudoku):
    system('cls')
    if solve_sudoku(sudoku, copy.deepcopy(sudoku)):
        print(Fore.CYAN + "\nSudoku solved successfully!" + Style.RESET_ALL)
    else:
        print(Fore.RED + "\nNo solution exists." + Style.RESET_ALL)

def get_user_input():
    sudoku = []  # List to hold the sudoku rows
    for i in range(9):
        while True:
            string_in = input(f"Row {i + 1}: ").strip()  # Get user input
            row = list(string_in)  # Convert input string to a list of characters
            if validate_row(row):  # Validate the row
                sudoku.append(row)  # Append the valid row to sudoku
                break
            else:
                print(Fore.RED + "Invalid input! Row must contain 9 characters: digits 1-9 or 'X' for empty slots." + Style.RESET_ALL)
    return sudoku

def main():
    try:
        if input("Input your own sudoku? (y/n) ").lower() == "y":
            sudoku = get_user_input()
        else:
            sudoku = [
                ['5', '3', 'X', 'X', '7', 'X', 'X', 'X', 'X'],
                ['6', 'X', 'X', '1', '9', '5', 'X', 'X', 'X'],
                ['X', '9', '8', 'X', 'X', 'X', 'X', '6', 'X'],
                ['8', 'X', 'X', 'X', '6', 'X', 'X', 'X', '3'],
                ['4', 'X', 'X', '8', 'X', '3', 'X', 'X', '1'],
                ['7', 'X', 'X', 'X', '2', 'X', 'X', 'X', '6'],
                ['X', '6', 'X', 'X', 'X', 'X', '2', '8', 'X'],
                ['X', 'X', 'X', '4', '1', '9', 'X', 'X', '5'],
                ['X', 'X', 'X', 'X', '8', 'X', 'X', '7', '9']
            ]
        print_sudoku(sudoku, sudoku)  # Print initial state of the Sudoku grid
        solve(sudoku)

    except Exception as e:
        print(Fore.RED + f"[Error] {str(e)}" + Style.RESET_ALL)

if __name__ == "__main__":
    main()
