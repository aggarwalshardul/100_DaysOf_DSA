#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Pair;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    Pair* queue = (Pair*)malloc(m * n * sizeof(Pair));
    int front = 0, rear = 0;

    int fresh = 0;

    // Step 1: count fresh + push rotten
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Pair){i, j};
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) {
        free(queue);
        return 0;
    }

    int minutes = 0;
    int dir[5] = {0, 1, 0, -1, 0};

    // Step 2: BFS
    while (front < rear) {
        int size = rear - front;
        int spread = 0;

        for (int i = 0; i < size; i++) {
            Pair p = queue[front++];
            int x = p.x, y = p.y;

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d];
                int ny = y + dir[d + 1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear++] = (Pair){nx, ny};
                    fresh--;
                    spread = 1;
                }
            }
        }

        if (spread) minutes++;
    }

    free(queue);

    return (fresh == 0) ? minutes : -1;
}