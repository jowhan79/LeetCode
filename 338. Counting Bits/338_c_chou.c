// 2017/11/8
int* countBits(int num, int* returnSize) {
    
    int i, j, bits, val; 
    int *ans = (int*)malloc((num+1)*sizeof(int));
    
    for(i=0; i<=num; i++){
        bits = 0;
        for(j=0, val=i; j<32 && val>0; j++){
            bits += val%2;
            val = val >> 1;
        }
        ans[i] = bits;
    }
    
    *returnSize = num+1;
    return ans;
}
