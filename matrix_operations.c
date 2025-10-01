#include <stdio.h>

#define MAX 10 

void inputMatrix(int rows, int cols, int mat[MAX][MAX]) {
    printf("Enter elements of matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int mat[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX]) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Matrix Addition Result:\n");
    displayMatrix(rows, cols, result);
}

void multiplyMatrix(int r1, int c1, int A[MAX][MAX], int r2, int c2, int B[MAX][MAX]) {
    if (c1 != r2) {
        printf("Matrix multiplication not possible (columns of A != rows of B).\n");
        return;
    }
    int result[MAX][MAX] = {0};
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("Matrix Multiplication Result:\n");
    displayMatrix(r1, c2, result);
}

void transposeMatrix(int rows, int cols, int A[MAX][MAX]) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
    printf("Transpose of Matrix:\n");
    displayMatrix(cols, rows, result);
}

int main() {
    int rows, cols;
    int A[MAX][MAX], B[MAX][MAX];
    int choice;

    printf("Enter rows and columns of matrices: ");
    scanf("%d%d", &rows, &cols);

    printf("\n--- Matrix A ---\n");
    inputMatrix(rows, cols, A);
    printf("\n--- Matrix B ---\n");
    inputMatrix(rows, cols, B);

    do {
        printf("\nChoose Operation:\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Transpose of Matrix A\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrix(rows, cols, A, B);
                break;
            case 2:
                multiplyMatrix(rows, cols, A, rows, cols, B);
                break;
            case 3:
                transposeMatrix(rows, cols, A);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
