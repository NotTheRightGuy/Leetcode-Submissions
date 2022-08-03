int maxSubArray(int *nums, int numsSize){
    int maxCurrent = nums[0], maxGlobal = nums[0];
    for(int i = 1;i<numsSize;i++){
        maxCurrent = nums[i] > nums[i] + maxCurrent ? nums[i] : nums[i] + maxCurrent;
        if(maxCurrent > maxGlobal){
            maxGlobal = maxCurrent;
        }
    }
    return maxGlobal;
}
