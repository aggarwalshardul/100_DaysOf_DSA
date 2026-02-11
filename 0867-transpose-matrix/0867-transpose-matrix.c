/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;          // original rows
    int cols = matrixColSize[0];    // original columns
    
    // Transposed matrix will have 'cols' rows
    *returnSize = cols;
    
    // Allocate memory for returnColumnSizes
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    
    // Each row in transpose will have 'rows' columns
    for(int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
    }
    
    // Allocate memory for transpose matrix
    int** result = (int**)malloc(cols * sizeof(int*));
       for(int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }
    
    // Fill transpose matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    return result;
    
}