#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functie om een matrix af te drukken
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Functie om matrices op te tellen
int** addMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Kan matrices niet optellen. Matrices moeten dezelfde afmetingen hebben.\n");
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

// Functie om matrices van elkaar af te trekken
int** subtractMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Kan matrices niet aftrekken. Matrices moeten dezelfde afmetingen hebben.\n");
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

// Functie om een matrix met een scalaire waarde te vermenigvuldigen
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

// Functie om matrices met elkaar te vermenigvuldigen
int** multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Kan matrices niet vermenigvuldigen. Het aantal kolommen van matrix 1 moet gelijk zijn aan het aantal rijen van matrix 2.\n");
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

int main(int argc, char* argv[]) {
    if (argc != 12) {
        printf("Ongeldige argumenten. Gebruik: ./main -m <rij1> <kolom1> \"[matrix1]\" <rij2> <kolom2> \"[matrix2]\" -b <bewerking>\n");
        return 1;
    }

    int rows1 = atoi(argv[2]);
    int cols1 = atoi(argv[3]);

    // Matrix 1
    int** matrix1 = (int**)malloc(rows1 * sizeof(int*));
    char* token = strtok(argv[4], "[];, ");
    int count1 = 0;
    while (token != NULL) {
        if (count1 % cols1 == 0) {
            matrix1[count1 / cols1] = (int*)malloc(cols1 * sizeof(int));
        }
        matrix1[count1 / cols1][count1 % cols1] = atoi(token);
        token = strtok(NULL, "[];, ");
        count1++;
    }

    int rows2 = atoi(argv[6]);
    int cols2 = atoi(argv[7]);

    // Matrix 2
    int** matrix2 = (int**)malloc(rows2 * sizeof(int*));
    token = strtok(argv[8], "[];, ");
    int count2 = 0;
    while (token != NULL) {
        if (count2 % cols2 == 0) {
            matrix2[count2 / cols2] = (int*)malloc(cols2 * sizeof(int));
        }
        matrix2[count2 / cols2][count2 % cols2] = atoi(token);
        token = strtok(NULL, "[];, ");
        count2++;
    }

    char* operation = argv[10];

    int** result = NULL;

    if (strcmp(operation, "add") == 0) {
        result = addMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    } else if (strcmp(operation, "sub") == 0) {
        result = subtractMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    } else if (strcmp(operation, "scale") == 0) {
        int scalar = atoi(argv[11]);
        result = scalarMultiplyMatrix(matrix1, rows1, cols1, scalar);
    } else if (strcmp(operation, "multiply") == 0) {
        result = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    } else {
        printf("Ongeldige bewerking.\n");
    }

    if (result != NULL) {
        printMatrix(result, rows1, cols2);

        // Geheugen vrijgeven
        for (int i = 0; i < rows1; ++i) {
            free(matrix1[i]);
        }
        free(matrix1);

        for (int i = 0; i < rows2; ++i) {
            free(matrix2[i]);
        }
        free(matrix2);

        for (int i = 0; i < rows1; ++i) {
            free(result[i]);
        }
        free(result);
    }

    return 0;
}
