#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LEN 5

void statistiek(int* numbers, int size, int* min, int* max, int* average, int* median);
int compare(const void* a, const void* b);

int main() {
    srand(time(NULL));

    int* numbers = calloc(LEN, sizeof(int));
    int size = LEN;
    int min, max, average, median;

    for (int i = 0; i < LEN; i++) {
        numbers[i] = rand() % 100;
    }

    statistiek(numbers, size, &min, &max, &average, &median);

    printf("Lijst met getallen na de functie-oproep:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Gemiddelde: %.2f\n", (float)average);
    printf("Mediaan: %.2f\n", (float)median);

    free(numbers);

    return 0;
}

void statistiek(int* numbers, int size, int* min, int* max, int* average, int* median) {
    *min = numbers[0];
    *max = numbers[0];

    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] < *min) {
            *min = numbers[i];
        } else if (numbers[i] > *max) {
            *max = numbers[i];
        }

        sum += numbers[i];
    }

    *average = (float)sum / size;

    qsort(numbers, size, sizeof(int), compare);

    if (size % 2 == 0) {
        *median = (float)(numbers[size / 2 - 1] + numbers[size / 2]) / 2;
    } else {
        *median = (float)numbers[size / 2];
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
