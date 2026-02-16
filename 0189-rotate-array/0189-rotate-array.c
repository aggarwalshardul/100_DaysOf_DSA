void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;
    
    k = k % numsSize;   // Handle k > numsSize
    
    int start, end, temp;
    
    // 1️⃣ Reverse whole array
    start = 0;
    end = numsSize - 1;
    while (start < end) {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
    
    // 2️⃣ Reverse first k elements
    start = 0;
    end = k - 1;
    while (start < end) {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
    
    // 3️⃣ Reverse remaining elements
    start = k;
    end = numsSize - 1;
    while (start < end) {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    
}
}