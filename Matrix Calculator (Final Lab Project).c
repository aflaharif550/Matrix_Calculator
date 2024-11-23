#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void inputMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void AdditionOfMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void SubtractionOfMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

int determinant(int matrix[MAX_ROWS][MAX_COLS], int size) {
    if (size == 1) {
        return matrix[0][0];
    }

    if (size == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    int det = 0;
    int submatrix[MAX_ROWS][MAX_COLS];
    for (int col = 0; col < size; col++) {
        int subi = 0;
        for (int i = 1; i < size; i++) {
            int subj = 0; 
            for (int j = 0; j < size; j++) {
                if (j != col) {
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
            }
            subi++;
        }
        
        if (col % 2 == 0) {
            det += matrix[0][col] * determinant(submatrix, size - 1);
        } else {
            det -= matrix[0][col] * determinant(submatrix, size - 1);
        }
    }

    return det;
}

void coFactor(int mat[MAX_ROWS][MAX_COLS], int cof[MAX_ROWS][MAX_COLS], int n) {
    int temp[MAX_ROWS][MAX_COLS]; 
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            int subi = 0;
            for (int x = 0; x < n; x++) {
                if (x == a) {
                    continue;
                }
                int subj = 0; 
                for (int y = 0; y < n; y++) {
                    if (y == b) {
                        continue; 
                    }
                    temp[subi][subj] = mat[x][y];
                    subj++;
                }
                subi++;
            }
            cof[a][b] = ((a + b) % 2 == 0 ? 1 : -1) * determinant(temp, n - 1);
        }
    }
}


void transpose(int mat[MAX_ROWS][MAX_COLS], int tra[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tra[j][i] = mat[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 == rows2) {
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < cols1; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    } else {
        printf("Inappropriate Order\n");
    }
}

void scalarProduct(int matrix[MAX_ROWS][MAX_COLS], float multiplier, float result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * multiplier;
        }
    }
}

int main() {
	printf("\t\t\t\t\t Welcome to the Matrix Calculator\n");
    int i = 0;
    do {
        int opr;
        printf("What do You want to Perform \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Adjoint \n 5. Determinant \n 6. Inverse\n");
        scanf("%d", &opr);

        int rows, cols, n;
        int row1, col1, row2, col2;
        switch (opr) {
            case 1:
            case 2:
                printf("Enter number of Rows: ");
                scanf("%d", &rows);
                printf("Enter number of Columns: ");
                scanf("%d", &cols);

                int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
                inputMatrix(rows, cols, mat1);
                printMatrix(rows, cols, mat1); 
                inputMatrix(rows, cols, mat2);
                printMatrix(rows, cols, mat2); 

                if (opr == 1) {
                    AdditionOfMatrices(mat1, mat2, result, rows, cols);
                    printf("Result of Addition:\n");
                    printMatrix(rows, cols, result);
                } else {
                    SubtractionOfMatrices(mat1, mat2, result, rows, cols);
                    printf("Result of Subtraction:\n");
                    printMatrix(rows, cols, result);
                }
                break;

            case 3:
                printf("Enter number of Rows for Matrix 1: ");
                scanf("%d", &row1);
                printf("Enter number of Columns for Matrix 1: ");
                scanf("%d", &col1);
                int matA[MAX_ROWS][MAX_COLS];
                inputMatrix(row1, col1, matA);
                printMatrix(row1, col1, matA);

                printf("Enter number of Rows for Matrix 2: ");
                scanf("%d", &row2);
                printf("Enter number of Columns for Matrix 2: ");
                scanf("%d", &col2);
                int matB[MAX_ROWS][MAX_COLS];
                inputMatrix(row2, col2, matB);
                printMatrix(row2, col2, matB);

                int resultMul[MAX_ROWS][MAX_COLS];
                multiplyMatrices(matA, matB, resultMul, row1, col1, row2, col2);
                if (col1 == row2) {
                    printf("Result of Multiplication:\n");
                    printMatrix(row1, col2, resultMul);
                }
                break;

            case 4:
                printf("Enter size of Square Matrix: ");
                scanf("%d", &n);
                int mat[MAX_ROWS][MAX_COLS], cof[MAX_ROWS][MAX_COLS], tra[MAX_ROWS][MAX_COLS];
                inputMatrix(n, n, mat);
                printMatrix(n, n, mat); 
                coFactor(mat, cof, n);
                transpose(cof, tra, n, n);
                printf("Adjoint Matrix:\n");
                printMatrix(n, n, tra);
                break;

            case 5:
                printf("Enter size of Square Matrix: ");
                scanf("%d", &n);
                int matDet[MAX_ROWS][MAX_COLS];
                inputMatrix(n, n, matDet);
                printMatrix(n, n, matDet); 
                int det = determinant(matDet, n);
                printf("The determinant of the matrix is: %d\n", det);
                break;

            case 6:
                printf("Enter size of Square Matrix: ");
                scanf("%d", &n);
                int matInv[MAX_ROWS][MAX_COLS], cofInv[MAX_ROWS][MAX_COLS], adj[MAX_ROWS][MAX_COLS];
                float inv[MAX_ROWS][MAX_COLS];
                inputMatrix(n, n, matInv);
                printMatrix(n, n, matInv); 
                int detInv = determinant(matInv, n); 
                printf("Determinant: %d\n", detInv);

                if (detInv != 0) {
                    coFactor(matInv, cofInv, n);
                    transpose(cofInv, adj, n, n);
                    scalarProduct(adj, (1.0 / detInv), inv, n, n);
                    printf("Inverse Matrix:\n");
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            printf("%f ", inv[i][j]);
                        }
                        printf("\n");
                    }
                } else {
                    printf("Matrix is singular, inverse cannot be calculated.\n");
                }
                break;

            default:
                printf("Invalid operation selected.\n");
                break;
        }
        char ans;
        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &ans);
        if (ans == 'y' || ans == 'Y') {
            i = 0;
        } else {
        	printf("Thnak You For Your Services!");
            i = 10;
        }
    } while (i == 0);

    return 0;
}
