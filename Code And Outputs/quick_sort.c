#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void runTest(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {arr[i] = rand();}

    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array Size: %d\t\t Time Taken: %f seconds\n", size, time_taken);
    free(arr);
}

int main() {
    srand(time(NULL));
    
    double sizes[] = {1e4, 2e4, 3e4, 4e4, 5e4, 6e4, 7e4, 8e4, 9e4, 1e5};
    int n = sizeof(sizes) / sizeof(sizes[0]);

    for(int i = 0; i < n; i++) {runTest(sizes[i]);}
    return 0;
}