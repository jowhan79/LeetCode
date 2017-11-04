// 2017/11/04 Peony
int maxSubArray(int* nums, int numsSize) {

    int i, maxVal;
    int table[numsSize];
    memset(table, 0, sizeof(int));
    for(i=1, maxVal=nums[0], table[0]=nums[0]; i<numsSize; i++){
        // update table value
        table[i] = table[i-1] < 0 ? (table[i-1]>nums[i]? table[i-1]: nums[i]) : (table[i-1]+nums[i]);
        if(table[i]>maxVal){ // update maxVal
            maxVal = table[i];
        }
    }
    return maxVal;
}
