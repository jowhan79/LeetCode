// 2017/11/13 Jowhan

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/********************** solution 1 **********************/
// greedy solution: time: O(nlogn+mlonm), space: O(n+m)
// 想法: 先sort好之後，依序搜尋找出相同元素。

inline int* merge( int *array1, int array1Size, int *array2, int array2Size ){
    if( array1Size+array2Size==0 ) return NULL;
    int* mergedArray=(int*)malloc(sizeof(int)*(array1Size+array2Size));
    int i, j, k;
    
    for( i=0, j=0, k=0; i<array1Size && j<array2Size ; ++k ){
        if( array1[i]<array2[j] ) mergedArray[k] = array1[i++];
        else mergedArray[k] = array2[j++];
    }
    for( ; i<array1Size; ++i, ++k ) mergedArray[k] = array1[i];
    for( ; j<array2Size; ++j, ++k ) mergedArray[k] = array2[j];
    
    return mergedArray;
}

inline void mergeSort( int* array, int arraySize ){
    if( arraySize<=1 ) return;
    
    int len, i, array1Size, array2Size;
    int *array1=NULL, *array2=NULL, *temp=NULL;
    
    for( len=1; len<arraySize; len*=2 ){
        for( i=0; i<arraySize; i+=2*len ){
            array1 = array+i;
            if( i+len>=arraySize ){ // first array not full
                array1Size = arraySize-i;
                array2 = NULL;
                array2Size = 0;
            }
            else if( i+2*len>=arraySize ){ // second array not full
                array1Size = len;
                array2Size = arraySize-i-len;
                if( array2Size==0 ) array2 = NULL;
                else array2 = array+i+len;
            }
            else{ // two arrays both full
                array2 = array+i+len;
                array1Size = array2Size = len;
            }            
            
            temp = merge(array1,array1Size,array2,array2Size);
            
            if( temp ){
                memcpy(array1,temp,sizeof(int)*(array1Size+array2Size));
                free(temp);
                temp = NULL;
            }
        }
    }
}

inline int* _intersection_solution1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *ans = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    int i, j, k, val=2147483647;
    
    // sort
    mergeSort( nums1, nums1Size );
    mergeSort( nums2, nums2Size );
    
    // find in both array
    for( i=0, j=0, k=0; i<nums1Size && j<nums2Size; ){
        if( nums1[i]==nums2[j] && val!=nums1[i] ){
            ans[k++] = nums1[i];
            val = nums1[i];
            ++i;
            ++j;
        }
        else if( nums1[i]<nums2[j] ) ++i;
        else ++j;
    }
    
    *returnSize = k;
    return ans;
}
/********************************************************/

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    return _intersection_solution1(nums1, nums1Size, nums2, nums2Size, returnSize);
}
