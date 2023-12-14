#include <stdio.h>

void printArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
   
        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j = j - 1;

        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Lista original: ");
    printArray(arr, n);

    bubbleSort(arr, n);
    printf("Ordenado pelo Bubble Sort: ");
    printArray(arr, n);

    int arrReset[] = {64, 25, 12, 22, 11, 9};

    selectionSort(arrReset, n);
    printf("Ordenado pelo Selection Sort: ");
    printArray(arrReset, n);

    int arrReset2[] = {64, 25, 12, 22, 11, 9};

    insertionSort(arrReset2, n);
    printf("Ordenado pelo Insertion Sort: ");
    printArray(arrReset2, n);

    return 0;
}