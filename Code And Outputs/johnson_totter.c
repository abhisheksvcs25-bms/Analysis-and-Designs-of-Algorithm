#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Element {
    int value;
    char dir; 
};

struct Element perm[MAX];

void printPermutation(int n) {
    for (int i = 0; i < n; i++) {printf("%d ", perm[i].value);}
    printf("\n");
}

int getLargestMobile(int n) {
    int largestMobile = -1;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int nextIndex;
        if (perm[i].dir == '<')
            nextIndex = i - 1;
        else
            nextIndex = i + 1;

        if (nextIndex >= 0 && nextIndex < n) {
            if (perm[i].value > perm[nextIndex].value) {
                if (perm[i].value > largestMobile) {
                    largestMobile = perm[i].value;
                    index = i;
                }
            }
        }
    }
    return index;
}

void reverseDirection(int n, int value) {
    for (int i = 0; i < n; i++) {
        if (perm[i].value > value) {
            if (perm[i].dir == '<')
                perm[i].dir = '>';
            else
                perm[i].dir = '<';
        }
    }
}

void johnsonTrotter(int n) {
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].dir = '<';
    }

    printPermutation(n);

    while (1) {
        int mobileIndex = getLargestMobile(n);

        if (mobileIndex == -1)
            break;

        int swapIndex;
        if (perm[mobileIndex].dir == '<')
            swapIndex = mobileIndex - 1;
        else
            swapIndex = mobileIndex + 1;

        struct Element temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        mobileIndex = swapIndex;

        reverseDirection(n, perm[mobileIndex].value);
        printPermutation(n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");scanf("%d", &n);

    if (n > MAX) {
        printf("Max allowed is %d\n", MAX);
        return 1;
    }
    johnsonTrotter(n);
    return 0;
}