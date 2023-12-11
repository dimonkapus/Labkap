#include <stdio.h>
#include <stdlib.h>

void fillRandomMatrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;  // заповнення випадковими числами
        }
    }
}

void printMatrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void deleteRows(double ***matrix, int *rows, int cols, int k1, int k2) {
    if (k1 < 0 || k1 >= *rows || k2 < k1 || k2 >= *rows) {
        printf("Invalid row indices.\n");
        return;
    }

    int newRows = *rows - (k2 - k1 + 1);

    double **newMatrix = (double **)malloc(newRows * sizeof(double *));
    for (int i = 0, newRow = 0; i < *rows; i++) {
        if (i < k1 || i > k2) {
            newMatrix[newRow] = (double *)malloc(cols * sizeof(double));
            for (int j = 0; j < cols; j++) {
                newMatrix[newRow][j] = (*matrix)[i][j];
            }
            newRow++;
        }
    }


    for (int i = 0; i < *rows; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);
     
    *matrix = newMatrix;
    *rows = newRows;
}

int main() {
    int N, M, k1, k2;

    printf("rows (N): ");
    scanf("%d", &N);
    printf("columns (M): ");
    scanf("%d", &M);

    double **matrix = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (double *)malloc(M * sizeof(double));
    }

    fillRandomMatrix(matrix, N, M);

    printf("Original matrix:\n");
    printMatrix(matrix, N, M);

    printf("\nEnter the range of rows to delete (k1 and k2): ");
    scanf("%d %d", &k1, &k2);

    deleteRows(&matrix, &N, M, k1, k2);

    printf("\nMatrix after deleting rows %d to %d:\n", k1, k2);
    printMatrix(matrix, N, M);

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
