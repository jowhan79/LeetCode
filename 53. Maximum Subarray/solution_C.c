// 2017/11/04

#define MAX(X,Y) (((X)>(Y))?(X):(Y))

int maxSubArray(int* nums, int numsSize) {
    // solution 1: dynamic programming
    int max_sum[numsSize], i, max_ans;
    
    // record the sum of all values
    // reset if previous sum + next single value < next single value
    max_sum[0] = max_ans = nums[0];
    for( i=1; i<numsSize; ++i ){
        if( max_sum[i-1]<0 ){
            max_sum[i] = MAX(max_sum[i-1],nums[i]);
        }
        else{
            max_sum[i] = max_sum[i-1]+nums[i];
        }
        if( max_sum[i]>max_ans )    max_ans = max_sum[i];
    }
    
    return max_ans;
}
