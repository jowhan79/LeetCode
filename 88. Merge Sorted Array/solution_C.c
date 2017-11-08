// 2017/11/08 Jowhan

void merge(int* nums1, int m, int* nums2, int n) {
    // merge array from tail
    int index1=m-1, index2=n-1, index_new=m+n-1;   
    
    // put bigger value from tail
    while( index1>=0 && index2>=0 ){
        if( nums1[index1]>nums2[index2] ){
            nums1[index_new] = nums1[index1];
            --index1;
        }
        else{
            nums1[index_new] = nums2[index2];
            --index2;
        }        
        --index_new;
    }
    
    // put all remain values from nums2 to nums1
    for( ; index2>=0; --index2){
        nums1[index2] = nums2[index2];
    }
    
    return;
}
