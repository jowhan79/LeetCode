//2017/11/09 Peony
int lengthOfLongestSubstring(char* s) {

    int i, j, k, maxlen, len=strlen(s), ans=0;
    int count[256];

    for(i=0; i<len; i++){
        memset(count, 0, sizeof(count));
        for(j=i, maxlen=0; j<len; j++){
            if(count[s[j]]==0){
                ++count[s[j]];
                ++maxlen;
            }else{
                break;
            }
        }
        if(maxlen>ans){
            ans=maxlen;
        }
    }
    
    return ans;
}
