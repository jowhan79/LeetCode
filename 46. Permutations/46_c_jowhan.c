// 2017/11/28 Jowhan

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/********************** solution 1 **********************/
// recursive
// 超難，偷看資結筆記才會XD
// 記錄個有點難de的bug：取值(*)運算子優先權較一些常用運算子(+,-,[])低。

inline void swap(int* a, int* b){
    if( *a==*b ) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int** _permute_sol1(int* nums, int numsSize, int*** returnArray, int* returnSize, int i) {
    int j;

    if( i+1==numsSize ){
        *returnArray = realloc(*returnArray,sizeof(int*)*(++(*returnSize)));
        (*returnArray)[(*returnSize)-1] = malloc(sizeof(int)*numsSize);
        memcpy((*returnArray)[(*returnSize)-1],nums,sizeof(int)*numsSize);
    }
    else{
        for( j=i; j<numsSize; ++j ){
            swap(&nums[i],&nums[j]);
            *returnArray = _permute_sol1(nums, numsSize, returnArray, returnSize, i+1);
            swap(&nums[i],&nums[j]);
        }
    }
    
    return *returnArray;
}
/********************************************************/
    
int** permute(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;    
    int **returnArray=NULL;
    return _permute_sol1(nums, numsSize, &returnArray, returnSize, 0);
}
