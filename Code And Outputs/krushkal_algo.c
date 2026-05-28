#include <stdio.h>
int parent[10];

int find(int i){
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void uni(int a, int b){parent[a] = b;}

int main(){
    int n = 4; 
    int cost[4][4] = {
        {999, 10, 6, 5},
        {10, 999, 999, 15},
        {6, 999, 999, 4},
        {5, 15, 4, 999}
    };

    int i, j, min, a, b;
    int edges = 0;
    int total = 0;

    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    while(edges < n - 1){
        min = 999;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if(u != v){
            printf("%d - %d = %d\n", a, b, min);
            total += min;
            uni(u, v);
            edges++;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("Total cost = %d\n", total);
    return 0;
}