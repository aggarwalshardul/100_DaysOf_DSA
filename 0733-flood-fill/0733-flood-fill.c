/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(int** image, int m, int n, int r, int c, int oldColor, int newColor) {
    // Boundary check
    if (r < 0 || c < 0 || r >= m || c >= n)
        return;

    // If not matching original color, stop
    if (image[r][c] != oldColor)
        return;

    // Fill the color
    image[r][c] = newColor;

    // Explore 4 directions
    dfs(image, m, n, r + 1, c, oldColor, newColor);
    dfs(image, m, n, r - 1, c, oldColor, newColor);
    dfs(image, m, n, r, c + 1, oldColor, newColor);
    dfs(image, m, n, r, c - 1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes) {

    int m = imageSize;
    int n = imageColSize[0];

    int oldColor = image[sr][sc];

    // Edge case: no change needed
    if (oldColor == color) {
        *returnSize = m;
        *returnColumnSizes = imageColSize;
        return image;
    }

    dfs(image, m, n, sr, sc, oldColor, color);

    *returnSize = m;
    *returnColumnSizes = imageColSize;
    return image;
}