// 2017/11/14 Jowhan

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/********************** solution 1 **********************/
// hash approach: time: O(n), space: O(n)
// 想法: 將各個數字出現次數記錄下來，回傳出現兩次之數字。

inline int* _findDuplicates_solution1(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    if( numsSize<=1 ) return NULL;
    int count_hash[numsSize], i, j;
    
    memset(count_hash,0,sizeof(int)*numsSize);    
    
    for( i=0; i<numsSize; ++i ){
        if( ++count_hash[nums[i]-1]==2 ) ++*returnSize;
    }
    
    int* ans = (int*)malloc(sizeof(int)*(*returnSize));
    for( i=0, j=0; i<numsSize; ++i ){
        if( count_hash[i]==2 ) ans[j++] = i+1;
    }
    
    return ans;
}
/********************************************************/

/********************** solution 2 **********************/
// time: O(n), space: O(1)
// 想法: 將資訊藏在原本數字中
// 每次掃數字時，將對應的index轉成負數。
// 若有重複數字再次掃到，檢查該對應index的值即為負數。

inline int* _findDuplicates_solution2(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    if( numsSize<=1 ) return NULL;
    int i, j, index;
    int *ans = (int*)malloc(sizeof(int)*numsSize);
    
    for( i=0, j=0; i<numsSize; ++i ){
        index = abs(nums[i])-1;
        if( nums[index]<0 ){
            ans[j++] = abs(nums[i]);
            ++*returnSize;
        }
        else nums[index] = -nums[index];
    }
    ans = (int*)realloc(ans, sizeof(int)*(*returnSize));
    
    return ans;
}

/********************************************************/

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    return _findDuplicates_solution2(nums, numsSize, returnSize);
}
