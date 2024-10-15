# Sudoku Solver

This project features implementations of a Sudoku solver in both Python and C. Utilizing a recursive backtracking algorithm, the program allows users to input their own Sudoku puzzles or use a predefined example. It validates input, visualizes the solving process, and highlights changes in the Sudoku grid, providing an engaging way to experience solving puzzles. Perfect for both beginners and enthusiasts, this project showcases algorithmic problem-solving and user interaction.

## Overview

This repository contains implementations of a Sudoku solver in both Python and C. The program uses a backtracking algorithm to solve Sudoku puzzles and provides a user-friendly interface for inputting Sudoku grids. Users can either input their own puzzles or use a predefined example.

## Features

- Input validation for Sudoku grids.
- Recursive backtracking algorithm for solving Sudoku puzzles.
- Clear visualization of the Sudoku grid, highlighting changes during the solving process.
- Option for users to input their own Sudoku puzzles or use predefined ones.

## Requirements

- For **Python**:
  - Python 3.x
  - Colorama library (can be installed via pip)

- For **C**:
  - A C compiler (e.g., GCC).
  - A terminal that supports ANSI escape codes for colored output (Linux, macOS, or Windows with appropriate settings).

## Installation

1. Clone the repository or download the files to your local machine.

   ```sh
   git clone <repository-url>
   cd <repository-directory>

### For Python

1. Install the required library using pip:

   ```sh
   pip install colorama

### For C 

1. Compile the C program using a C compiler (e.g., GCC):
   ```sh
   gcc -o sudoku_solver sudoku_solver.c

## Usage
### Python Version 
1. Run the Python program:
   ```sh
   python sudoku_solver.py
2. When prompted, choose whether to input your own Sudoku puzzle or use the default one by entering `y` or `n`.
3. If you choose to input your own puzzle:
   * Enter each row of the Sudoku grid as a string of 9 characters, using digits `1-9` for filled cells and `X` for empty cells.
   * For example: `53XX7XXXX`.
4. The program will display the Sudoku grid and highlight changes as it solves the puzzle. Upon completion, it will inform you whether the puzzle was solved successfully or if no solution exists.

### C Version
1. Run the compiled C program:
   ```sh 
   ./sudoku_solver
2. Follow the same steps as above for inputting the Sudoku grid.
