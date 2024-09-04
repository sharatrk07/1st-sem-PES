#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

void shortest_distance(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = INF;
            }
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = (matrix[i][j] < matrix[i][k] + matrix[k][j]) ? matrix[i][j] : (matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INF) {
                matrix[i][j] = -1;
            }
        }
    }
}

int main() {
    int V = 4;
    int **matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        matrix[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            matrix[i][j] = -1;
        }
    }

    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    shortest_distance(matrix, V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d\t ", matrix[i][j]);
        }
        printf("\n");
    }

    // Freeing memory
    for (int i = 0; i < V; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}