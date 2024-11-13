#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define MAX_VALUE 999
#define TRIALS 20

void generateRandomData(int data[]) {
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % (MAX_VALUE + 1);
    }
}

void printArray(int data[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void doSelectionSort(int data[]) {
    int sortedData[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sortedData[i] = data[i];
    }

    printf("Selection Sort:\n");
    for (int i = 0; i < SIZE - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (sortedData[j] < sortedData[minIdx]) {
                minIdx = j;
            }
        }
        int temp = sortedData[i];
        sortedData[i] = sortedData[minIdx];
        sortedData[minIdx] = temp;

        if ((i + 1) % 10 == 0 || i == SIZE - 2) {
            printf("\n");
            printf("Step %d: ", i + 1);
            printArray(sortedData, SIZE);
        }
    }
}

int doInsertionSort(int data[]) {
    int comparisons = 0;
    int sortedData[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sortedData[i] = data[i];
    }

    for (int i = 1; i < SIZE; i++) {
        int key = sortedData[i];
        int j = i - 1;
        while (j >= 0 && sortedData[j] > key) {
            sortedData[j + 1] = sortedData[j];
            j--;
            comparisons++;
        }
        sortedData[j + 1] = key;
    }
    return comparisons;
}

int doBubbleSort(int data[]) {
    int movements = 0;
    int sortedData[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sortedData[i] = data[i];
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (sortedData[j] > sortedData[j + 1]) {
                int temp = sortedData[j];
                sortedData[j] = sortedData[j + 1];
                sortedData[j + 1] = temp;
                movements += 3;
            }
        }
    }
    return movements;
}

int main() {
    srand(time(NULL));
    int randomData[SIZE];
    int totalComparisons = 0;
    int totalMovements = 0;

    generateRandomData(randomData);
    doSelectionSort(randomData);

    for (int i = 0; i < TRIALS; i++) {
        generateRandomData(randomData);
        totalComparisons += doInsertionSort(randomData);
    }
    printf("\n");
    printf("Insertion Sort Compare Average: %d\n", totalComparisons / TRIALS);
    printf("Insertion Sort Result: \n");
    doInsertionSort(randomData);
    printArray(randomData, SIZE);

    for (int i = 0; i < TRIALS; i++) {
        generateRandomData(randomData);
        totalMovements += doBubbleSort(randomData);
    }

    printf("\n");
    printf("Bubble Sort Move Average: %d\n", totalMovements / TRIALS);
    printf("Bubble Sort Result: \n");
    doBubbleSort(randomData);
    printArray(randomData, SIZE);

    return 0;
}
