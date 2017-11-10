// 2017/11/10 Jowhan

/********************** solution 1 **********************/
// greedy solution: time: O(n^3), space: O(1)

inline bool isPalindrome(char* s, int s_len){
    int i, j, ans=1;
    
    for( i=0,j=s_len-1; i<j; ++i,--j ){
        if( s[i]!=s[j] ){
            ans = 0;
            break;
        }
    }
    
    return ans;
}
inline char* _longestPalindrome_solution1(char* s){    
    int i, j, s_len=strlen(s);
    bool check;
    char *ans_substr;    
    
    for( i=s_len; i>0; --i ){  // control substring length
        for( j=0; i+j<=s_len; ++j ){  // control substring head
            if( check=isPalindrome(s+j, i) ) break;
        }
        if( check ) break;
    }
    
    ans_substr = (char*)malloc(i+1);
    memcpy(ans_substr, s+j, i);
    ans_substr[i]=0;
    
    return ans_substr;
}
/********************************************************/


/********************** solution 2 **********************/
// dp solution: time: O(n^2), space: O(n^2)
// 判斷回文可拆為字首、中段、字尾，若中段為回文，只需再判斷
// 字首字尾是否一樣即可。從短長度開始，將判斷結果記錄在表格中。

inline char* _longestPalindrome_solution2(char* s){
    int s_len=strlen(s);    
    if( s_len==0 ) return 0;
    int len, head, tail, max_length=0, max_head=0;
    bool isPalindrome_dp[s_len][s_len];
    memset(isPalindrome_dp,0,sizeof(isPalindrome_dp));
    
    // first row: single charactor is always palindrome
    for( head=0; head<s_len; ++head ){
        isPalindrome_dp[0][head] = 1;
        max_length = 1;
        max_head = head;
    }
    
    // second row: only need to check head and tail
    for( head=0; head+1<s_len; ++head ){
        tail = head+1;
        if( s[head]==s[tail] ){
            isPalindrome_dp[1][head] = 1;
            max_length = 2;
            max_head = head;
        }
    }
    
    // other rows: check middle and head and tail
    for( len=2; len<s_len; ++len ){  // control substring length (length=len+1)
        for( head=0; len+head<s_len; ++head ){  // control substring head and tail
            tail = head+len;
            if( isPalindrome_dp[len-2][head+1] && s[head]==s[tail] ){
                isPalindrome_dp[len][head] = 1;
                max_length = len+1;
                max_head = head;
            }
        }
    }
    
    // malloc for return
    char *ans = (char*)malloc(max_length+1);
    memcpy(ans,s+max_head,max_length);
    ans[max_length] = 0;
    
    return ans;
}
/********************************************************/

char* longestPalindrome(char* s) {
    return _longestPalindrome_solution2(s);
}
