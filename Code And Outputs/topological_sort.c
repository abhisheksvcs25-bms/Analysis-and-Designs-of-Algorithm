#include <stdio.h>
#define MAX 6

int main() {
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    int indegree[MAX] = {0};
    int removed[MAX] = {0};  

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    printf("Topological Order: ");

    for (int count = 0; count < MAX; count++) {
        int found = -1;

        for (int i = 0; i < MAX; i++) {
            if (indegree[i] == 0 && removed[i] == 0) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            printf("\nGraph has a cycle!\n");
            return 0;
        }

        printf("%d ", found);
        removed[found] = 1;

        for (int j = 0; j < MAX; j++) {
            if (adj[found][j] == 1) {
                indegree[j]--;
            }
        }
    }

    return 0;
}