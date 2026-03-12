/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int *answer = (int*)calloc(temperaturesSize, sizeof(int));
    int *stack = (int*)malloc(sizeof(int) * temperaturesSize);
    
    int top = -1;
    
    for(int i = 0; i < temperaturesSize; i++){
        
        while(top != -1 && temperatures[i] > temperatures[stack[top]]){
            
            int index = stack[top--];
            answer[index] = i - index;
        }
        
        stack[++top] = i;
    }
    
    *returnSize = temperaturesSize;
    free(stack);
    
    return answer;
}