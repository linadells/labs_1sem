#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int i, j, a, b, n, ne = 1, ver = 1, k = 0;
int min, cost[9][9], vert[9];
int main() {
    printf("Enter the number of vertices:");
    scanf_s("%d", &n);
    printf("Enter the cost adjacency matrix:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf_s("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("Edges of minimum spanning tree:\n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if (a != b) {
            printf("%d%d\n", a, b);
            for (int i = 1; i <= n; i++) {
                if (vert[i] == a) {
                    k++;
                }
            }
            if (!k) {
                if (vert[ver]) ver++;
                vert[ver] = a;
            }
            k = 0;
            for (int i = 1; i <= n; i++) {
                if (vert[i] == b) {
                    k++;
                }
            }
            if (!k) {
                if (vert[ver]) ver++;
                vert[ver] = b;
            }
            ne++;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Vertices of minimum spanning tree:\n");
    for (int i = 1; i <= n; i++) {
        printf("%i ", vert[i]);
    }
    return 0;
}
/*
0 1 5 4 5
1 0 2 6 1
5 2 0 1 7
4 6 1 0 4
5 1 7 4 0
*/