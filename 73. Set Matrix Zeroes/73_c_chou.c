// 2017/11/25 Peony
// Solution:
// Check every row and col
inline void setZeros_v1(int** matrix, int matrixRowSize, int matrixColSize){
    
    int i, j;
    int flag_row[matrixRowSize], flag_col[matrixColSize];
    
    memset(flag_row, 0, sizeof(flag_row));
    memset(flag_col, 0, sizeof(flag_col));
    for(i=0; i< matrixRowSize; i++){
        for(j=0; j<matrixColSize; j++){
            if(matrix[i][j]==0){
                flag_row[i]=1;
                flag_col[j]=1;
            }
        }
    }
    
    for(i=0; i<matrixRowSize; i++){
        if(flag_row[i]==1){
            for(j=0; j<matrixColSize; j++){
                matrix[i][j]=0;
            }
        }
    }
    for(i=0; i<matrixColSize; i++){
        if(flag_col[i]==1){
            for(j=0; j<matrixRowSize; j++){
                matrix[j][i]=0;
            }
        }
    }
    
}



void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
   setZeros_v1(matrix, matrixRowSize, matrixColSize);
}
