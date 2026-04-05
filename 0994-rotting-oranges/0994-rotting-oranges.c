int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    // Queue (store coordinates)
    int queue[m * n][2];
    int front = 0, rear = 0;

    int fresh = 0;

    // Step 1: count fresh & push rotten
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    int minutes = 0;
    int dir[5] = {0, 1, 0, -1, 0};

    // Step 2: BFS
    while (front < rear) {
        int size = rear - front;
        int spread = 0;

        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d];
                int ny = y + dir[d + 1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                    fresh--;
                    spread = 1;
                }
            }
        }

        if (spread) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}