#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {L[i] = arr[l + i];}
    for (j = 0; j < n2; j++) {R[j] = arr[m + 1 + j];}

    i = 0; j = 0; k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {arr[k++] = L[i++];} 
        else {arr[k++] = R[j++];}
    }

    while (i < n1) {arr[k++] = L[i++];}
    while (j < n2) {arr[k++] = R[j++];}

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void runTest(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {arr[i] = rand();}

    clock_t start = clock();
    mergeSort(arr, 0, size - 1);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Array Size: %d\t\t Time Taken: %f seconds\n", size, time_taken);
    free(arr);
}

int main() {
    srand(time(NULL));
    double sizes[] = {1e4, 2e4, 3e4, 4e4, 5e4, 6e4, 7e4, 8e4, 9e4, 1e5};
    int n = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < n; i++) {runTest(sizes[i]);}
    return 0;
}