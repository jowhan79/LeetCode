// 2017/11/08 Jowhan
// Total 3 solutions.

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* _countBits_solution1(int num, int* returnSize){
    int i, j, base;
    int *sum = (int*)malloc(sizeof(int)*(num+1));
    memset(sum,0,sizeof(int)*(num+1));
    
    for( i=0; i<=num; ++i ){
        for( j=0; j<32; ++j ){
            sum[i] += (i>>j) & 1;
        }
    }
    
    *returnSize = num+1;
    return sum;
}

int* _countBits_solution2(int num, int* returnSize){
    // 這太難了吧，沒google最好會
    const int m1 = 0x55555555;   // 0101010101010101
    const int m2 = 0x33333333;   // 0011001100110011
    const int m4 = 0x0f0f0f0f;   // 0000111100001111
    const int m8 = 0x00ff00ff;   // 0000000011111111
    const int m16 = 0x0000ffff;    
    int i;
    int *hamming_weight = (int*)malloc(sizeof(int)*(num+1));
    
    for( i=0; i<=num; ++i ){    
        hamming_weight[i] = i; 
        hamming_weight[i] = (hamming_weight[i] & m1) + (hamming_weight[i]>>1 & m1);
        hamming_weight[i] = (hamming_weight[i] & m2) + (hamming_weight[i]>>2 & m2);
        hamming_weight[i] = (hamming_weight[i] & m4) + (hamming_weight[i]>>4 & m4);
        hamming_weight[i] = (hamming_weight[i] & m8) + (hamming_weight[i]>>8 & m8);
        hamming_weight[i] = (hamming_weight[i] & m16) + (hamming_weight[i]>>16 & m16);
    }
    
    *returnSize = num+1;
    return hamming_weight;
}

int* _countBits_solution3(int num, int* returnSize){
    // 上面想太難，可用DP解
    int i;
    int *hamming_weight = (int*)malloc(sizeof(int)*(num+1));
    
    hamming_weight[0] = 0;
    for( i=1; i<=num; ++i ){
        hamming_weight[i] = (i&1) + hamming_weight[i>>1];
    }
    
    *returnSize = num+1;
    return hamming_weight;
}

int* countBits(int num, int* returnSize) {
    return _countBits_solution3(num, returnSize);
}
