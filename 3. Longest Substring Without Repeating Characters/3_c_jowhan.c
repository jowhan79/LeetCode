// 2017/11/09 Jowhan

// for solution 1
# ifndef MAX_SUBSTR_LENGTH
# define MAX_SUBSTR_LENGTH 100
# endif

// for solution 2
# ifndef MAX(X,Y)
# define MAX(X,Y) (((X)>(Y)) ? (X) : (Y))
# endif

inline int _replaceMaxSubstr(char* max_substr, char* s, int substr_begin, int substr_end){
    int j, k;
    if( strlen(max_substr)>=substr_end-substr_begin+1 ) return 0;
    
    // replace
    memset(max_substr,0,MAX_SUBSTR_LENGTH);
    for( j=substr_begin,k=0; j<=substr_end; ++j,++k ){
        max_substr[k] = s[j];
    }
    return 1;
}

inline int _lengthOfLongestSubstring_solution1(char* s) {
    // O(n^2) solution
    int i, j, k, substr_begin=0, substr_end=-1, is_find;
    char max_substr[MAX_SUBSTR_LENGTH];
    
    memset(max_substr,0,MAX_SUBSTR_LENGTH);

    for( i=0; s[i]!=0; ++i ){
        is_find = 0;
        for( j=substr_begin; j<=substr_end; ++j ){  // find repeat characters
            if( s[i]==s[j] ){
                is_find = 1;
                break;
            }
        }
        if( is_find ){  // check is max or not
            _replaceMaxSubstr(max_substr, s, substr_begin, substr_end);
            substr_begin = j+1;  // reset substr pointer
        }
        ++substr_end;
    }
    _replaceMaxSubstr(max_substr, s, substr_begin, substr_end);    
    
    return strlen(max_substr);
}


inline int _lengthOfLongestSubstring_solution2(char* s) { 
    /***********************************************************************
    O(n) solution: DP approach
    
    關鍵: 建立charactor的hash table，用來記錄各個charactor的位置。
    因為每個charactor只會出現一次，因此比對字元時若有對應位置代表此字元已出現過。
    若無出現過: 紀錄hash table中該字元位置
    若有出現過: 子字串頭改為原本字元位置的下一位，並更新hash table中該字元位置
    - 無出現過初始值為-1，子字串頭下一位為0，即為-1的下一位。因此無論有無出現過
    所做的事情均一致。
    - 為了避免遇到[新字元]或是[已被放棄字元]使子字串頭往回跑，所以加入MAX確保子字
    串頭不會回頭。
    ***********************************************************************/
    int char_index[256], i, substr_begin=0, max_substr_length=0;
    memset(char_index,-1,sizeof(int)*256);
    
    for( i=0; s[i]!=0; ++i ){
        // the begin of substring should not become smaller
        substr_begin = MAX(char_index[s[i]]+1,substr_begin);
        // update hash table
        char_index[s[i]] = i;
        // check which substring is longer
        max_substr_length = MAX(max_substr_length,i-substr_begin+1);
    }    
    
    return max_substr_length;
}


int lengthOfLongestSubstring(char* s) {
    return _lengthOfLongestSubstring_solution2(s);
}
