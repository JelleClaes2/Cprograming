#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** addMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices kunnen niet worden opgeteld: onjuiste dimensies.\n");
        return NULL;
    }

    int** result = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; ++i) {
        result[i] = (int*)malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

int** subtractMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices kunnen niet worden afgetrokken: onjuiste dimensies.\n");
        return NULL;
    }

    int** result = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; ++i) {
        result[i] = (int*)malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

int** scalarMultiplyMatrix(int** matrix, int rows, int cols, int scalar) {
    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        result[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }

    return result;
}

int** multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrices kunnen niet worden vermenigvuldigd: onjuiste dimensies.\n");
        return NULL;
    }

    int** result = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; ++i) {
        result[i] = (int*)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int** parseMatrix(char* str, int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    char* token = strtok(str, " [;]");
    int i = 0, j = 0;

    while (token != NULL) {
        if (strcmp(token, "]") == 0) {
            break;
        }
        if (strcmp(token, ";") == 0) {
            ++i;
            j = 0;
        } else {
            matrix[i][j++] = atoi(token);
        }
        token = strtok(NULL, " [;]");
    }

    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int argc, char* argv[]) {
   /* if (argc < 12) {
        printf("Ongeldige argumenten. Gebruik: ./main -m <rij1> <kolom1> \"[matrix1]\" <rij2> <kolom2> \"[matrix2]\" -b <bewerking>\n");
        return 1;
    }*/

    int rows1 = atoi(argv[2]);
    int cols1 = atoi(argv[3]);
    int rows2 = atoi(argv[5]);
    int cols2 = atoi(argv[6]);

    if (rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0) {
        printf("Ongeldige rij- of kolomwaarden.\n");
        return 1;
    }

    /*if (argc != 8 + rows1 * cols1 + rows2 * cols2) {
        printf("Ongeldige argumenten.\n");
        return 1;
    }*/

    char* matrix1Str = argv[4];
    char* matrix2Str = argv[7 + rows1 * cols1];
    char* operation = argv[8 + rows1 * cols1];

    /*if (strcmp(operation, "add") != 0 && strcmp(operation, "sub") != 0 &&
        strcmp(operation, "scale") != 0 && strcmp(operation, "multiply") != 0) {
        printf("Ongeldige bewerking.\n");
        return 1;
    }*/

    int** matrix1 = parseMatrix(matrix1Str, rows1, cols1);
    int** matrix2 = parseMatrix(matrix2Str, rows2, cols2);

    int** result = NULL;

    if (strcmp(operation, "add") == 0) {
        result = addMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    } else if (strcmp(operation, "sub") == 0) {
        result = subtractMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    } else if (strcmp(operation, "scale") == 0) {
        int scalar = atoi(argv[8 + rows1 * cols1 + 1]);
        result = scalarMultiplyMatrix(matrix1, rows1, cols1, scalar);
    } else if (strcmp(operation, "multiply") == 0) {
        result = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    }

    if (result != NULL) {
        printf("Matrixresultaat:\n");
        printMatrix(result, rows1, cols2);
        freeMatrix(result, rows1);
    }

    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);

    return 0;
}
