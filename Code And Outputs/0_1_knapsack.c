#include <stdio.h>

int main() {
    int weights[] = {1, 3, 4, 5};
    int values[]  = {1, 4, 5, 7};
    int n = 4;          
    int capacity = 7;   
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {dp[i][w] = 0;}
            else if (weights[i - 1] <= w) {
                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude = dp[i - 1][w];

                dp[i][w] = (include > exclude) ? include : exclude;
            }
            else {dp[i][w] = dp[i - 1][w];}
        }
    }

    printf("Maximum value in Knapsack = %d\n", dp[n][capacity]);
    return 0;
}