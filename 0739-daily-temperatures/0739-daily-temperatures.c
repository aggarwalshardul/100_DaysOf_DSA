/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int *ans = (int*)calloc(temperaturesSize, sizeof(int));
    int *stack = (int*)malloc(sizeof(int) * temperaturesSize);
    
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {

        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            ans[idx] = i - idx;
        }

        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    free(stack);

    return ans;
}