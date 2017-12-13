// 2017/12/13 Peony
char* reverseString(char* s) {
    
    int len, i;
    char c;
    len = strlen(s);
    for(i=0; i<(len/2); i++){
        c = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = c;
    }
    return s;
}
