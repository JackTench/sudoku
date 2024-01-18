#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "print.h"

bool isSafe(int board[9][9], int row, int col, int num)
{

    // Row unique
    for (int d = 0; d < 9; d++) {
        if (board[row][d] == num) {
            return false;
        }
    }

    // Col unique
    for (int r = 0; r < 9; r++) {
        if (board[r][col] == num) {
            return false;
        }
    }

    // Square unique
    int sqrtN = (int)sqrt(9);
    int boxRowStart = row - row % sqrtN;
    int boxColStart = col - col % sqrtN;
    for (int r = boxRowStart; r < boxRowStart + sqrtN; r++) {
        for (int d = boxColStart; d < boxColStart + sqrtN; d++) {
            if (board[r][d] == num) {
                return false;
            }
        }
    }

    // Is safe.
    return true;

}

// Recusive function to solve the board.
bool solveSudoku(int board[9][9])
{

    int row = -1;
    int col = -1;
    bool isEmpty = true;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            } else {
                board[row][col] = 0;
            }
        }
    }

    return false;

}

int main()
{

    // Print header.
    printf("Sudoku Solver\n");
    printf("-------------\n");

    // Init board.
    int board[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    printBoard(board);
    printf("Solving board.\n");

    // Solve.
    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        printf("No solution to given puzzle.");
    }

    return 0;

}