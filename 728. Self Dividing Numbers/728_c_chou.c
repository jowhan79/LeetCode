// 2017/12/14 Peony
int* selfDividingNumbers(int left, int right, int* returnSize) {
    
    int i, tmp, digit, count, *ans;
    
    ans = (int*)malloc((right-left+1)*sizeof(int));
    for(i=left, count=0; i <= right; i++){
        tmp = i;
        while(tmp>0){
            digit = tmp % 10;
            if( digit<1 || ( i % digit != 0)){
                tmp = -1; 
                break;   
            }
            tmp = tmp / 10;
        }
        
        if(tmp>=0){
            ans[count++] = i;
        }
        
    }
    *returnSize = count;
    ans = (int*)realloc(ans, count*sizeof(int));
    return ans;
}
