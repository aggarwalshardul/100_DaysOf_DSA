/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {

    int *result = (int*)malloc(sizeof(int)*(numsSize-k+1));
    int *deque = (int*)malloc(sizeof(int)*numsSize);

    int front = 0, rear = -1;
    int idx = 0;

    for(int i=0;i<numsSize;i++){

        // Remove elements outside window
        if(front <= rear && deque[front] <= i-k)
            front++;

        // Maintain decreasing order
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        deque[++rear] = i;

        // Store result when first window completed
        if(i >= k-1)
            result[idx++] = nums[deque[front]];
    }

    *returnSize = idx;
    return result;
}