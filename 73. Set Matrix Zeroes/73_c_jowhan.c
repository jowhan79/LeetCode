/********************** solution 1 **********************/
// time: O(m*n*(m+n)), space: O(m*n)
// 第一次: 掃描矩陣，紀錄有0出現之座標
// 第二次: 依據紀錄之座標將對應的row及col設為0

inline void _setZeroes_sol1(int** matrix, int matrixRowSize, int matrixColSize) {
    if( matrixRowSize==0 || matrixColSize==0 ) return 0;
    int i, j, k;
    bool isZero[matrixRowSize][matrixColSize];
    
    memset(isZero,0,sizeof(isZero));
    
    for( i=0; i<matrixRowSize; ++i ){
        for( j=0; j<matrixColSize; ++j ){
            if( matrix[i][j]==0 ){
                isZero[i][j] = 1;
            }
        }
    }
    
    for( i=0; i<matrixRowSize; ++i ){
        for( j=0; j<matrixColSize; ++j ){
            if( isZero[i][j]==1 ){
                for( k=0; k<matrixRowSize; ++k ) matrix[k][j]=0;
                for( k=0; k<matrixColSize; ++k ) matrix[i][k]=0;
            }
        }
    }
}
/********************************************************/


/********************** solution 2 **********************/
// time: O(m*n), space: O(m+n)
// 第一次: 掃描矩陣，紀錄有0出現之row及col
// 第二次: 依據紀錄之座標將對應的row及col設為0

inline void _setZeroes_sol2(int** matrix, int matrixRowSize, int matrixColSize) {
    if( matrixRowSize==0 || matrixColSize==0 ) return 0;
    int i, j, k;
    bool isZeroRow[matrixRowSize], isZeroCol[matrixColSize];
    
    memset(isZeroRow,0,sizeof(isZeroRow));
    memset(isZeroCol,0,sizeof(isZeroCol));
    
    for( i=0; i<matrixRowSize; ++i ){
        for( j=0; j<matrixColSize; ++j ){
            if( matrix[i][j]==0 ){
                isZeroRow[i] = 1;
                isZeroCol[j] = 1;
            }
        }
    }
    
    for( i=0; i<matrixRowSize; ++i ){
        if( isZeroRow[i]==1 ){
            for( j=0; j<matrixColSize; ++j ) matrix[i][j]=0;
        }
    }    
    for( j=0; j<matrixColSize; ++j ){
        if( isZeroCol[j]==1 ){
            for( i=0; i<matrixRowSize; ++i ) matrix[i][j]=0;
        }
    }

}
/********************************************************/


/********************** solution 3 **********************/
// time: O(m*n), space: O(1)
// 關鍵: 將資訊記到第一列及第一欄
// 第一次: 
// 1. 首先紀錄第一列與第一欄是否有0
// 2. 掃描矩陣，若遇0則將該座標的第一列與第一欄設成0
// 第二次:
// 1. 將除了第一列與第一欄之外的座標，檢查第一列與第一欄，若其一為0則改為0
// 2. 最後檢查原本第一列與第一欄是有有0，若有則其對應改為0

inline void _setZeroes_sol3(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j, k;
    bool isFirstRowZero=0, isFirstColZero=0;

    // check first row and column
    for( i=0; i<matrixRowSize; ++i ){
        if( matrix[i][0]==0 ){
            isFirstColZero=1;
            break;
        }
    }
    for( j=0; j<matrixColSize; ++j ){
        if( matrix[0][j]==0 ){
            isFirstRowZero=1;
            break;
        }
    }    
    // scan remain elements, set first to zero if meet zero
    for( i=1; i<matrixRowSize; ++i ){
        for( j=1; j<matrixColSize; ++j ){
            if( matrix[i][j]==0 ){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // according to first row and column, fill zeros
    for( i=1; i<matrixRowSize; ++i ){
        for( j=1; j<matrixColSize; ++j ){
            if( matrix[i][0]==0 || matrix[0][j]==0 ){
                matrix[i][j] = 0;
            }
        }
    }    
    // if original first have zeros, fill zeros
    if( isFirstRowZero ){
        for( j=0; j<matrixColSize; ++j ){
            matrix[0][j] = 0;
        }
    }
    if( isFirstColZero ){
        for( i=0; i<matrixRowSize; ++i ){
            matrix[i][0] = 0;
        }
    }
}
/********************************************************/

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    return _setZeroes_sol3(matrix, matrixRowSize, matrixColSize);
}
