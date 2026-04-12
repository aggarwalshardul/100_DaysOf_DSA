#include <stdlib.h>
#include <limits.h>

int minCostConnectPoints(int** points, int n, int* colSize) {
    int minDist[n];
    int visited[n];

    for(int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        visited[i] = 0;
    }

    minDist[0] = 0;
    int result = 0;

    for(int i = 0; i < n; i++) {
        int u = -1;

        // pick minimum
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        // update distances
        for(int v = 0; v < n; v++) {
            if(!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                if(dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    return result;
}