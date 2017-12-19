// 2017/12/19 Jowhan

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/********************** solution 1 **********************/
int* _selfDividingNumbers_sol1(int left, int right, int* returnSize) {
    int i, j, val, digit, islegal;
    int *result;
    
    result = malloc((right-left+1)*sizeof(int));
    memset(result,0,sizeof(result));
    
    // check each value
    for( i=left; i<=right; ++i ){
        // check each digit
        for( islegal=1,val=i ; val!=0 ; val/=10 ){
            digit = val % 10;
            if( !digit || i%digit!=0 ){
                islegal = 0;
                break;
            }
        }
        // record legal value
        if( islegal )
            result[(*returnSize)++] = i;
    }
    
    return result;
}
/********************************************************/

int* selfDividingNumbers(int left, int right, int* returnSize) {
    *returnSize = 0;
    return _selfDividingNumbers_sol1(left, right, returnSize);
}
