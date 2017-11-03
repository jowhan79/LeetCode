/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    if( wordsSize==0 ){
        *returnSize = 0;
        return NULL;
    }   
    
    char temp;
    int row, now_row, i, j, max_j=0, max_i=0;
    char islegal[wordsSize];
    char** ans=NULL;

    // initial islegal
    memset(islegal,1,wordsSize);

    for( i=0; i<wordsSize; ++i ){
        row = 0;
        for( j=0; words[i][j]!=0; ++j ){
            temp = toupper(words[i][j]);
            // define keyboard row
            switch(temp){
                case'Q':
                case'W':
                case'E':
                case'R':
                case'T':
                case'Y':
                case'U':
                case'I':
                case'O':
                case'P':
                    now_row = 1;
                    break;
                case'A':
                case'S':
                case'D':
                case'F':
                case'G':
                case'H':
                case'J':
                case'K':
                case'L':
                    now_row = 2;
                    break;
                case'Z':
                case'X':
                case'C':
                case'V':
                case'B':
                case'N':
                case'M':
                    now_row = 3;
                    break;
            }
            if( j>max_j ){
                max_j = j;
            }
            if( row==0 ){
                row = now_row;
            }
            else if( now_row!=row ){
                islegal[i] = 0;
                break;
            }
        }
    }

    max_j += 2;  
    for( i=0; i<wordsSize; ++i ){
        if( islegal[i] )    max_i++; 
    }
    /*printf("max_i=%d, max_j=%d\n",max_i,max_j);
    printf("islegal=");
    for( i=0; i<wordsSize; ++i ){
        printf(" %d",islegal[i]);
    }
    printf("\n");*/

    // prepare for return
    ans = (char**)malloc(sizeof(char*)*max_i);
    for( i=0; i<max_i; ++i )
        ans[i] = (char*)malloc(sizeof(char)*max_j);

    for( i=0,j=0 ; i<wordsSize; ++i ){
        if( islegal[i] ){
            ans[j] = words[i];
            ++j;
        }
    }    

    *returnSize = max_i; 
    return ans;    
}
