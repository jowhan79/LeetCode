// 2017/12/13 Peony
char* reverseWords(char* s) {
    
    int len, j, i, head, tail;
    char ch;
    len = strlen(s);
    
    for(i=0, head=0, tail=0; i<=len; i++){
        if(s[i]==' '||s[i]=='\0'){
            tail = i-1;
            for(j=0; j<=((tail-head)/2); j++){
                ch = s[head + j];
                s[head + j] = s[tail-j];
                s[tail - j] = ch;
            }
            head = i+1;
        }
    }
    
    return s;
}
