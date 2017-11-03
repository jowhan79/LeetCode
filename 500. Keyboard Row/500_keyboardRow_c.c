char** findWords(char** words, int wordsSize, int* returnSize) {
 
    int table_len[] = {20, 18, 14};
    int table[26]={1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
    int i, j, valid=0, len, t, oldt, count=0;
    char **result = (char**)malloc(sizeof(char*)*wordsSize);

    for(i=0; i<wordsSize; i++){
        len = strlen(words[i]);
        for(j=0, valid=1; j<len; j++){
            if(words[i][j]>='A'&&words[i][j]<='Z'){
                t = table[(words[i][j])-'A'];   
            }else if(words[i][j]>='a'&&words[i][j]<='z'){
                t = table[(words[i][j])-'a']; 
            }
            if(j==0) oldt=t;
            else{
                if(oldt!=t){
                    valid = 0;
                    break;
                }
            }
        }
        if(valid==1){
            result[count] = (char*)malloc(len * sizeof(char));
            strcpy(result[count], words[i]);
            ++count;
        }
    }
    *returnSize = count;
    return result;
}
