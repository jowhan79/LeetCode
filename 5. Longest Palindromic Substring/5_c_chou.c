// 2017/11/11 Peony
char* longestPalindrome_v1(char* s){
    int len, i, dis, max_len, max_head, max_tail;
    len = strlen(s);
    
    for(i=0, max_len=0, max_head=max_tail=0; i<len; i++){ // i is center
        // case 1: s[i] is the center
        for(dis=1; dis<=(i<(len-i-1)?i:(len-i-1)); dis++){
            if(s[i-dis]!=s[i+dis]) break;   
        }
        if((2*(dis-1)+1)>max_len){
            max_len = 2*(dis-1) + 1;
            max_head = i-(dis-1);
            max_tail = i+ dis-1;
        }
        // case 2: s[i] is the left hand side of two center element
        for(dis=0; dis<=(i<(len-i-2)?i:(len-i-2)) ; dis++){
            if(s[i-dis]!=s[i+1+dis]) break;
        }
        if((2*(dis))>max_len){
            max_len = 2*(dis);
            max_head = i-(dis-1);
            max_tail = i+ dis;
        }
    }
    
    char *ans = (char*)malloc((max_tail-max_head+2)*sizeof(char));
    for(i=max_head; i<max_tail+1; i++){
        ans[i-max_head] = s[i];
    } ans[max_tail-max_head+1] = '\0';
    return ans;
    
}

char* longestPalindrome(char* s) {
    return longestPalindrome_v1(s);
}
