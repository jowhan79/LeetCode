// 2017/11/10 Jowhan

#ifndef MAX(X,Y)
#define MAX(X,Y) (((X)>(Y))?(X):(Y))

int findLength(int* A, int ASize, int* B, int BSize) {
    /**************************************************
    DP solution: time: O(n*m), space: O(n*m)
    建立表格紀錄至目前為止的最大相同子字串長度。    
    - 逐一檢查相同字元。
        - 若字元不同則直接記0。
        - 若字元相同則記[左上角結果+1]。
    - 回傳表格中最大值。
    **************************************************/
    if( ASize==0 || BSize==0 ) return 0;
    
    int length_table[ASize][BSize], max_length=0, i, j;
    memset(length_table,0,sizeof(int)*ASize*BSize);
    
    // first row
    for( j=0; j<BSize; ++j ){
        if( A[0]==B[j] ){
            length_table[0][j] = 1;
            max_length = MAX(max_length,length_table[0][j]);
        }
    }    
    
    for( i=1; i<ASize; ++i ){
        // first columns
        if( A[i]==B[0] ){
            length_table[i][0] = 1;
            max_length = MAX(max_length,length_table[i][0]);
        }
        
        // other rows and columns
        for( j=1; j<BSize; ++j ){
            if( A[i]==B[j] ){
                length_table[i][j] = length_table[i-1][j-1]+1;
                max_length = MAX(max_length,length_table[i][j]);
            }
        }
    }
    
    return max_length;
}
