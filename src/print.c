#include <stdio.h>
#include <math.h>
#include "print.h"

// Helper function to display the board.
void printBoard(int board[9][9])
{

    for (int r = 0; r < 9; r++) {
        for (int d = 0; d < 9; d++) {
            printf("%d ", board[r][d]);
			if (d % 3 == 2) {
				printf(" ");
			}
        }
        printf("\n");
        if ((r + 1) % (int)sqrt(9) == 0) {
            printf("\n");
        }
    }

}
