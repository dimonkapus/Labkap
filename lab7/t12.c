#include <stdio.h>

#define MAX_SIZE 100

void swapColumns(int matrix[MAX_SIZE][MAX_SIZE], int n, int col1, int col2) {
    for (int i = 0; i < n; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

void findMinMaxColumn(int matrix[MAX_SIZE][MAX_SIZE], int n, int m, int *minCol, int *maxCol) {
    int minVal = matrix[0][0];
    int maxVal = matrix[0][0];

    *minCol = 0;
    *maxCol = 0;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                *minCol = j;
            }
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                *maxCol = j;
            }
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;

    printf("Enter the number of rows (n): ");
    scanf("%d", &n);

    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0 || n > MAX_SIZE || m > MAX_SIZE) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int minCol, maxCol;

    findMinMaxColumn(matrix, n, m, &minCol, &maxCol);

    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, n, m);

    swapColumns(matrix, n, minCol, maxCol);

    printf("\nMatrix after swapping columns with min and max elements:\n");
    printMatrix(matrix, n, m);

    return 0;
}

