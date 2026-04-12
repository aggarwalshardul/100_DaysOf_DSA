#include <stdlib.h>
#include <limits.h>

int minCostConnectPoints(int** points, int n, int* colSize) {
    int *minDist = (int*)malloc(n * sizeof(int));
    char *visited = (char*)calloc(n, sizeof(char)); // faster than int
    
    for(int i = 0; i < n; i++) minDist[i] = INT_MAX;

    minDist[0] = 0;
    int result = 0;

    for(int i = 0; i < n; i++) {
        int u = -1;

        // find minimum
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        int ux = points[u][0];
        int uy = points[u][1];

        // update distances
        for(int v = 0; v < n; v++) {
            if(!visited[v]) {
                int dx = ux - points[v][0];
                if(dx < 0) dx = -dx;

                int dy = uy - points[v][1];
                if(dy < 0) dy = -dy;

                int dist = dx + dy;

                if(dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(visited);
    return result;
}