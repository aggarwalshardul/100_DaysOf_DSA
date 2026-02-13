/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    if(matrixSize == 0){
        *returnSize = 0;
        return NULL;
    }
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    int* result = (int*)malloc(rows * cols * sizeof(int));
    *returnSize = rows * cols;
    
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    int index = 0;
    
    while(top <= bottom && left <= right){
        
        // 1️⃣ Left → Right
        for(int i = left; i <= right; i++){
            result[index++] = matrix[top][i];
        }
        top++;
        
        // 2️⃣ Top → Bottom
        for(int i = top; i <= bottom; i++){
            result[index++] = matrix[i][right];
        }
        right--;
        
        // 3️⃣ Right → Left
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }
        
        // 4️⃣ Bottom → Top
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return result;
}