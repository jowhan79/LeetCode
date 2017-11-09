// 2017/11/09
int findLength_DP(int* A, int ASize, int* B, int BSize){
    
    int i, j, max_len;
    int table[ASize+1][BSize+1];
    memset(table, 0, sizeof(table));
    
    for(i=1, max_len=0; i<=ASize; i++){
        for(j=1; j<=BSize; j++){
            if(A[i-1]==B[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
                max_len = max_len > table[i][j] ? max_len: table[i][j];
                //printf("A[%d]=%d, B[%d]=%d\n", i, A[i-1], j, B[j-1]);
            }
        }
    }
    return max_len;
}

int findLength(int* A, int ASize, int* B, int BSize) {
    return findLength_DP(A, ASize, B, BSize);    
}
// using for may TLE
