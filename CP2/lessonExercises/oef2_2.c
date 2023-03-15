#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARRAYSIZE 5

void statistiek(int *numbers, int size, int *min, int *max, float *average, float *median);
int* createRandomArray(int size);
void printArray(int *numbers,int size);
void swap(int* xp, int* yp);
void bubbleSort(int* numbers, int size);
int minValue(int* numbers);
int maxValue(int* numbers,int size);
float medianValue(int* numbers,int size);
float averageValue(int* numbers,int size);

int main(void){
    srand(time(NULL));

    int *numbers=createRandomArray(ARRAYSIZE);

    int min;
    int max;
    float median;
    float average;

    printf("RANDOM\n");
    printArray(numbers,ARRAYSIZE);

    statistiek(numbers,ARRAYSIZE,&min,&max,&average,&median);

    printf("UN-SORTED\n");
    printArray(numbers,ARRAYSIZE);

    printf("MAX = %d\n",max);
    printf("MIN = %d\n",min);
    printf("MEDIAN = %.2f\n",median);
    printf("AVERAGE = %.2f\n",average);

}

int* createRandomArray(int size){
    int* numbers = (int*)calloc(size,sizeof(int));


    for(int i=0;i<size;i++){
        numbers[i]= rand()%101;
    }

    return numbers;
}

void printArray(int *numbers,int size){
    for(int i=0;i<size;i++){
        printf("numbers[%d]=%d\n",i,numbers[i]);
    }
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int* numbers, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
            if (numbers[j] > numbers[j + 1])
                swap(&numbers[j], &numbers[j + 1]);
}

int minValue(int* numbers){
    return numbers[0];
}

int maxValue(int* numbers,int size){
    return numbers[size-1];
}

float medianValue(int* numbers,int size){
    float median=0;
    int top=0;
    int lower=0;
    if(size %2 == 0){
        top=(size+1)/2;
        lower=(size-1)/2;
        median=(numbers[top]+numbers[lower])/(float )2;
    }else {
        median=numbers[size/2];
    }
    return median;
}

float averageValue(int* numbers,int size){
    float averageValue=0;
    for(int i=0;i<size;i++){
        averageValue+=numbers[i];
    }
    return  averageValue/size;
}

void statistiek(int *numbers, int size, int *min, int *max, float *average, float *median){
    int* sortedNumbers = (int*)calloc(size,sizeof(int));
    memcpy(sortedNumbers,numbers,sizeof(int)*size);
    bubbleSort(sortedNumbers,size);
    *min = minValue(sortedNumbers);
    *max = maxValue(sortedNumbers,size);
    *average = averageValue(sortedNumbers,size);
    *median = medianValue(sortedNumbers,size);
}
