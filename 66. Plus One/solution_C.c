// 2017/11/05 Jowhan

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry=0, i=0;
    int* ans;
    
    // check need to malloc digitsSize+1 (all 9) or not
    for( i=0, carry=1; i<digitsSize; ++i ){
        if( digits[i]!=9 ){
            carry = 0;
            break;
        }
    }
    
    if( carry==1 ){
        // all 9 case
        *returnSize = digitsSize+1;
        ans = (int*)malloc(sizeof(int)*(*returnSize));
        memset(ans,0,sizeof(int)*(*returnSize));
        ans[0] = 1;
    }
    else{
        // normal case
        *returnSize = digitsSize;
        ans = (int*)malloc(sizeof(int)*(*returnSize));
        memcpy(ans,digits,sizeof(int)*(*returnSize));
        i = *returnSize-1;
        do{
            ans[i] += 1;
            if( ans[i]==10 ){
                ans[i] = 0;
                carry = 1;
            }
            else
                carry = 0;
            --i;
        }while(carry!=0);
    }
    
    return ans;
}
