#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int capacity = 50;
    int n = 3;
    struct Item items[3] = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };

    int i;
    float totalProfit = 0.0;

    for (i = 0; i < n; i++) {items[i].ratio = (float)items[i].profit / items[i].weight;}

    sortItems(items, n);
    printf("Selected items:\n");
    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
            printf("Take full item -> Weight: %d Profit: %d\n",
                    items[i].weight, items[i].profit);
        } 
        else {
            float fraction = (float)capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            printf("Take %.2f fraction of item -> Weight: %d Profit: %d\n",
                    fraction, items[i].weight, items[i].profit);
                    
            capacity = 0;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);
    return 0;
}