#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int *visited = (int*)calloc(pointsSize, sizeof(int));
    int *minDist = (int*)malloc(pointsSize * sizeof(int));
    
    for(int i = 0; i < pointsSize; i++) {
        minDist[i] = INT_MAX;
    }
    
    minDist[0] = 0;
    int result = 0;

    for(int i = 0; i < pointsSize; i++) {
        int u = -1;

        for(int j = 0; j < pointsSize; j++) {
            if(!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        for(int v = 0; v < pointsSize; v++) {
            if(!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + 
                           abs(points[u][1] - points[v][1]);

                if(dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(visited);
    free(minDist);

    return result;
}