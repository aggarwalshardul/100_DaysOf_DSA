int maxSubarraySumCircular(int* nums, int numsSize) {
     int totalSum = 0;
    
    int currMax = nums[0];
    int maxSum = nums[0];
    
    int currMin = nums[0];
    int minSum = nums[0];
    
    for(int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
        
        if(i > 0) {
            currMax = (currMax + nums[i] > nums[i]) ? currMax + nums[i] : nums[i];
            maxSum = (maxSum > currMax) ? maxSum : currMax;
            
            currMin = (currMin + nums[i] < nums[i]) ? currMin + nums[i] : nums[i];
            minSum = (minSum < currMin) ? minSum : currMin;
        }
    }
    
    // If all numbers are negative
    if(maxSum < 0)
        return maxSum;
    
    int circularSum = totalSum - minSum;
    
    return (maxSum > circularSum) ? maxSum : circularSum;
}