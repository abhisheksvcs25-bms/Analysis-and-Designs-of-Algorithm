#include <stdio.h>
#define N 4
int board[N][N];

void printBoard() {
    int i, j;

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col) {
    int i, j;

    for(i = 0; i < col; i++) {
        if(board[row][i])
            return 0;
    }

    for(i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j])
            return 0;
    }

    for(i = row, j = col; i < N && j >= 0; i++, j--) {
        if(board[i][j])
            return 0;
    }

    return 1;
}

int solveNQ(int col) {
    int i;

    if(col >= N)
        return 1;

    for(i = 0; i < N; i++) {

        if(isSafe(i, col)) {

            board[i][col] = 1;

            if(solveNQ(col + 1))
                return 1;

            board[i][col] = 0;
        }
    }

    return 0;
}

int main() {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if(solveNQ(0)) {
        printf("Solution for %d-Queens Problem:\n\n", N);
        printBoard();
    } else {
        printf("No solution exists");
    }

    return 0;
}