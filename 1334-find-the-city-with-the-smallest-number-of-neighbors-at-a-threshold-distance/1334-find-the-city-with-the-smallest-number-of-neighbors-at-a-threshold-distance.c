#include <limits.h>

#define MAXN 101
#define INF 1000000000

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    
    int dist[MAXN][MAXN];

    // Step 1: Initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Fill edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Find result
    int resultCity = -1;
    int minReachable = INT_MAX;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        if (count <= minReachable) {  // tie-breaking
            minReachable = count;
            resultCity = i;
        }
    }

    return resultCity;
}